## Yelp or Proximity Server?
- Used to discover nearby attractions like places, events, restaurants, theaters, etc.

## Need To cover(RBSHD):
  1. Requirements(Functional)
  2. BOE Calculations
  3. System APIs
  4. HLD
  5. Database Schema
  6. Requirements(Non functional)
  
## 1. Requirements(Functional)
  - service should work
  - Add/delete/update places
  - Given longitude/lattitude nearby places should be listed for given radius
  - Users should be able to give reviews, ratings, open/close times, pictures, text, and a rating

## 2. BOE
  - 500k Places
  - 10k user/sec
  
## 3. System APIs
  - Get Place/person/thing information
```
<structure> search(dev_key, searchTerm, userLocation, radius, max_results, category, sort, long, lat)
Parameters:
  - dev_key: Id of registered user
  - searchTerm: This is the string which is to be searched
  - userLocation: Location of user performing the search
  - radius(optional): Radius in meters to be searched
  - maximum_results_to_return (number): Number of strings to be returned as result.
  - category(optional): Type of service resturant, gym, hotel etc.
  - sort (Optional) Best matched (0 - default), Minimum distance (1), Highest rated (2).
  - longitude
  - lattitude
Returns: JSON containing information about 
  - list of businesses matching the search query. 
  - reviews
  - photos
  - ratings
  - open/close time
  
```

## 4. HLD
  - User queries something as "Schools near me". Yelp/Google-map sends lattitude,longitude of user's device and on DB all locations within `10 km` radius of lattitude,longitude are relayed back to user.
  - For this, We need to store information of all places/things on earth so that when user queries a place/thing & all places that falls in 10 km radius are relyaed back.
  - This information will be huge, to store places/things information we will use ***SQL DB***.
  - For searching information faster we will use ***GRIDS(Tree data structure)***.    
![ImgUrl](https://i.ibb.co/PhCRgbC/2dgrid.png)   

### Storing information into DB?
  1. **Step-1** GRIDS
    - Whole whole world map is divided into grids.
    - Grid is a Node in Tree data structure.
    - Grid stores the DB server ID which contains all places information b/w lattitude,long range. (lattitude-start,longitude-start) & (lattitude-end,longitude-end) ie Places residing within a specific range of longitude and latitude.
```
  struct grid{
    uint32 gridId;        //gridId hash gives the DB where (latt-start,long-start,latt-end,long-end) are stored
    double lattitude-start,lattitude-end;
    double longitude-start,longitude-end;
    struct grid *child[4];
  }
```
    - Whenever user provides lattitude,longitude(of region to be searched), appropriate grid which serves enquired lattitude,longitude is searched in tree.
    
```
    User
  Parks near me
(lattitude-p,longitude-p)--->  APP-SERVER
                          lattitude-p,longitude-p
                                    |-------search in quadTree------>  QUADTREE(root)
                                    |                                     / | \ \
                                    |                                     Node-60
                                    |                               lattitude-start < lattitude-p < lattitude-end
                                    |                               longitude-start < longitude-p < longitude-end                                                           |    <---gridId of Node-60--------
                        gridId->|Hash|->serverID(n)
                            //serverID is DB number where info is stored
                                    |
                                    |                                        DB-n
                                    |---get info(lattitude-p,longitude-p)---> |
                                    |                                  Search DB for all (lattitude,longitude) 
                                    |                                  pairs within 10km of (lattitude-p,longitude-p)
                                    | <------create AJAX/REST information-----|  
     <------information-----------  |                     
```
    - GRID SIZE: Dynamically adjust the grid size such that whenever grid gets lot of places(maybe > 500) break it down to create smaller grids.
    - So, whenever a grid reaches 500 things, ***break it down into four grids*** of equal size and distribute places among them.
      - Thickly populated areas like San Francisco will have a lot of grids.
      - Sparsely populated area like the Pacific Ocean will have large grids with places only around the coastal lines.
  - **Datastructure to store Grid information**: Tree with 4 child nodes(`QuadTree`).
    - All the leaf nodes will represent the grids that cannot be further broken down.
```
  struct node{
    struct node* children[4];
    struct information{
      long objectID;        //This is a unique ID assigned to object(place, thing etc)
    };
  };
```    
![ImgUrl](https://i.ibb.co/mCbqctM/quadtree.png)

  - ***Building the Grid***
    - Start with one node that will represent the whole world in one grid, break it down into four nodes and distribute locations among them.
    - keep repeating this process with each child node until there are no nodes left with more than 500 locations.
  - **Finding grid for given location**
    - Start from root node, search the required node in tree downwards.
    - Once objectID is found search it in DB.
  - **Finding neighbouring grid of given grid***
    - Note only leaf node can contain list of locations
    - All leaf nodes of a parent will be neighbours. We can connect all leaves using `doubly linked list` and move easiy between them.
  - **MEMORY REQUIREMENTS**
    - Number of Grids
      - Total earth area = 200 * 10<sub>6</sub> sq miles. (200 Million sq miles)
      - let's take grid diagonal = 10 miles
      - Total Grids = 20 Million
    - objectId=4 bytes, lattitude,longitude=8bytes.   24 bytes
    - Database requirement:  24 * 20 * 10<sub>6</sub> = 4 * 10<sub>9</sub> = 4 GB
    - QuadTree: objectID(4 bytes) + 4 pointers(32 bytes) = 36 * 20 * 10<sub>6</sub> = 7 GB
  - **Adding new place into system**
    - Insertion need to take place in DB, Quadtree both.
    - Quadtree resides on multiple server
      - find the grid/server of the new Place and then add it there
   
## 5. DATABASE
### 5A. DB SCHEMA
- Each place will have following feilds

| objectID | lattitude | longitude | locationID | Description | Category |
| --- | --- | --- | --- | --- | --- |
| ram temple | 38.8951 | -77.0364 |

- objectID: This is a unique ID assigned to object(place, thing etc)
- lattitude: Geographic coordinate specifying north–south position of a point on the Earth's surface.
- longitude: Geographic coordinate specifying east–west position of a point on the Earth's surface.  
  - (lattitude, longitude): precise location of features on the surface of the Earth.
- locationID(8 bytes): Uniquely identifies a location. LocationId is taken 8 bytes(64 bits) considering future in mind.
  - 2<sup>64</sup> = Huge number of locations
- Description(512 bytes)
- Category(1 byte): E.g., coffee shop, restaurant, theater, etc.

### 5B. DATA PARTIONING
#### 5B1. SHARDING BASED ON REGION
  - Storing all places having particular zip code on set of servers.
  - Over time, some regions can end up storing a lot of places compared to others
#### 5B1. SHARDING BASED ON LOCATION ID
  - Using locationID to hash function. ServerID is generated. Data will be stored here.
  
## 6. ARCHITECTURE
### 6A. Storing location information in DB
```
User                            
click on add place
- Fill category
- Pick place on map
  (Lattitude, Longitude)
- Add name of place
         Authentication-happened
-Add_Place(lattitude,long,category,name)   <-------------------Data center-------------------->
                           |-------------->  APP-SERVER    
                                               |
                                        Generate a locationID, objectID              DB-1
                                  LocationID is generated based on Lat,lon           DB-2
                                        locationID->|Hash|->ServerID(3)              DB-4
                                                             -place info----->       DB-3
                                                                              objectID,lattitude,longitude,locationID
                                                                              Description,Category
 
```

## 6. REPLICATION
  - We will take master-slave configuration.
    - Master: caters all writes. Syncs data to replica
    - Replica: Can serve Read traffic.
    
## 7. CACHE(memcached)
  - To deal with hot Places, we can introduce a cache in front of our database.
  - Based on clients’ usage pattern, we can adjust how many cache servers we need.
  - Cache Eviction policy: LRU
  
## 8. LOAD BALANCING
  - At 2 places load balancers can be placed:
    a. Between clients and Application servers
    b. B/w application & backend servers.
    
## 9. RANKING
- **WHAT** rank the search results by proximity, popularity, relevance.
- **How**
  - Store the start given by user for place in QuadTree and database both.
  - While searching for the top 100 places in a given radius, we can ask each partition of the QuadTree to return the top 100 places with maximum popularity. 
  - Assuming the popularity of a place is not expected to reflect in the system within a few hours, we can decide to update it once or twice a day, especially when the load on the system is minimum
