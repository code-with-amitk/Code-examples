**Yelp or Proximity Server**
- [1. Requirements](#r)
- [2. BOE Calculations](#b)
- [3. System APIs](#s)
- [4. HLD](#h)
- [5. Database Schema](#d)
- [6. Requirements(Non functional)](#rn)


## Yelp/Proximity Server/Google Maps
- **What?** Used to discover nearby places(eg: schools near me), events, restaurants, theaters, etc.
- Yelp App on phone sends `(lattitude,longitude)` of user's device and yelp server sends locations within `10 km` radius of `(lattitude,longitude)` to the user.
  - (lattitude,longitude) are like coordinates of point on earth.

<a name=r></a> 
### 1. Requirements(Functional)
- Add/delete/update places.
- Given `(longitude, lattitude)` nearby places should be listed for given radius.
- Users should be able to give reviews, ratings, open/close times, pictures, text, and a rating

<a name=b></a>
### 2. BOE
  - 500k Places
  - 10k user/sec
  
<a name=sa></a> 
### 3. System APIs
1. Get Place/person/thing information
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
2. Update/Delete
```c
struct old_info {lattitude, longitude, name, desc}
struct new_info {lattitude, longitude, name, desc}
HttpCode update (old_info, new_info)

HttpCode delete (longitude, lattitude, name)
```

<a name=h></a>
### 4. HLD
- Information of places to be stored in ***SQL DB***.
- For searching information faster we will use **[Quad Tree data structure](/DS_Questions/Data_Structures/Trees/M-Ary_Trees/Quad_Tree/)**.
  
#### 1. **GRIDS**
  ![ImgUrl](https://i.ibb.co/mCbqctM/quadtree.png)
  
  - Whole whole world map is divided into grids.
  - Grid is a `Node in QuadTree` data structure. QuadTree can reside on multiple servers.
  - Grid stores the `DB server ID` which contains all place's information b/w lattitude,longitude range. (lattitude-start,longitude-start) & (lattitude-end,longitude-end) ie Places residing within a longitude and latitude.
    
```
  struct gridNode{
    uint32 gridId;        //gridId hash gives the DB where (latt-start,long-start,latt-end,long-end) are stored
    double lattitude-start,lattitude-end;
    double longitude-start,longitude-end;
    struct grid *child[4];
  }
```
  - ***Case-1: User queries `Schools near me`***
    - User's device provides self lattitude,longitude. appropriate grid which serves enquired lattitude,longitude is searched in tree.
    
```
    User
  Schools near me
  Google-map sends self
(lattitude-s,longitude-s)--->  APP-SERVER
                          lattitude-s,longitude-s
                                    |-------search in quadTree------>  QUADTREE(root)
                                    |                                     / | \ \
                                    |                                     Node-60
                                    |                               lattitude-start < lattitude-s < lattitude-end
                                    |                               longitude-start < longitude-s < longitude-end                                                           |    <---gridId of Node-60--------
                        gridId->|Hash|->serverID(n)
                        //serverID is DB number where info is stored
                                    |
                                    |                                        DB-n
                                    |---get info(lattitude-s,longitude-s)---> |
                                    |                                  Search DB for all (lattitude,longitude) 
                                    |                                  pairs within 10km of (lattitude-s,longitude-s)
                                    | <------create AJAX/REST information-----|  
     <------information-----------  |                     
```
  - ***GRID SIZE***: Dynamically adjust the grid size such that whenever grid gets lot of places(maybe > 500) break it down to create smaller grids.
    - So, whenever a grid reaches 500 things, ***break it down into four grids*** of equal size and distribute places among them.
      - Thickly populated areas like San Francisco will have a lot of grids.
      - Sparsely populated area like the Pacific Ocean will have large grids with places only around the coastal lines.
    - All the leaf nodes will represent the grids that cannot be further broken down
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
  
  - ***Case-2: Storing Place/Thing information on QuadTree, SQL-DB***
```
User                            
click on add New place
- Fill category
- Pick place on map(Lattitude-n, Longitude-n)
- Add name of place
         Authentication-happened
-Add_Place(lattitude-n,long-n,category,name)   <-------------------Data center-------------------->
                            |-------------->  APP-SERVER    
                                     Search (lattitude-n,long-n) in QuadTree
                                                 |----(lattitude-n,long-n)---->   QUADTREE(root)
                                                 |                                 / | \ \
                                                 |                       lattitude-start < lattitude-n < lattitude-end
                                                 |                       longitude-start < longitude-n < longitude-end
                                                 |                        Node-89 will store lattitude-n,longitude-n
                                                 |  <--gridID of Node89---------------|
                                                 |
                                        gridId->|Hash|->ServerID(3)                  DB-1
                                                      DB-3 will store infor
                                                             ---information----->    DB-3
                                                                              objectID,lattitude,longitude,locationID
                                                                              Description,Category
 
```
   
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
  - **QUad-tree** We will have replication of quad-tree in master-slave configuration 
    - Master: caters all writes. Syncs data to replica
    - Replica: Can serve Read traffic.
  - **Server dies**
    - We can have a secondary replica of each server and, if primary dies, it can take control after the failover. 
    - Both primary and secondary servers will have the same QuadTree structure.
    
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
