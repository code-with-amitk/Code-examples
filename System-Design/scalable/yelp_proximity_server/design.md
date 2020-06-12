## What is yelp or proximity server?
- used to discover nearby attractions like places, events, restaurants, theaters, etc.

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

### Storing data in GRID
  - Divide the whole world map into dynamic grids.
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
  - ***Building the Grid***
    - Start with one node that will represent the whole world in one grid, break it down into four nodes and distribute locations among them.
    - keep repeating this process with each child node until there are no nodes left with more than 500 locations.
  - **Finding grid for given location**
    - Start from root node, search the required node in tree downwards.
    - Once objectID is found search it in DB.
  - **Finding neighbouring grid of given grid***
    - Note only leaf node can contain list of locations
    - All leaf nodes of a parent will be neighbours. We can connect all leaves using `doubly linked list` and move easiy between them.
   
  
  
## 5. DATABASE SCHEMA

| objectID | lattitude | longitude |
| --- | --- | --- |
| ram temple | 38.8951 | -77.0364 |

- objectID: This is a unique ID assigned to object(place, thing etc)
- lattitude: Geographic coordinate specifying north–south position of a point on the Earth's surface.
- longitude: Geographic coordinate specifying east–west position of a point on the Earth's surface.  
- (lattitude, longitude): precise location of features on the surface of the Earth.



