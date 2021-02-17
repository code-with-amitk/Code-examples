  ## Types of Caches
  
|Method|What|Disadvantage|Advantage|
|---|---|---|---|
|1. Write Thru Cache|Data written to cache and DB both|Latency is high|2 copies stored|
|2. Write Around Cache|Write goes directly to DB. Operation is considered completed only after writing to DB|Reading recent data is  cache miss & need to be read from DB. High latency|Cache flooding avoided|
|3. Write Back Cache|Write done to cache only. Cache writes the info to DB(asynchronously).|Data availability risk(cache may fail)|Low latency, High throughput|
                                 
