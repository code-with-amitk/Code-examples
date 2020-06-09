## What is yelp or proximity server?
- used to discover nearby attractions like places, events, restaurants, theaters, etc.

## To cover(RBSHD):
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
  


