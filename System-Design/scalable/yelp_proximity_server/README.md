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
  - We need to store data of places so that when user queries and place falls in radius (based on category) information can be relyaed.
  - We can store information about things into:
    - `grids`(ie tree having 4 children)
    - SQL DB.
![ImgUrl](https://i.ibb.co/PhCRgbC/2dgrid.png)    

### Storing data in GRID
  - Divide the whole world map into dynamic grids.
  - **What is Grid**
    - grid is a datastructure that stores nodes with a region. May be a class or struct.
    - we can find all the neighboring grids and then query these grids to find nearby places.
  - **Grid size**
    - Dynamically adjust the grid size such that whenever grid gets lot of places(maybe > 500) break it down to create smaller grids.
    - This will help in faster searching.
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
