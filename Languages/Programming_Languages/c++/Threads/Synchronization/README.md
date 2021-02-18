## Synchronization
- `include<mutex>` has 4 classes: mutex, recursive_mutex, timed_mutex, recursive_timed_mutex for providing synchronization to threads.

|Type|What|Locking same mutex Mutliple times|
|---|---|---|
|1.mutex|Normal mutex|undefined behaviour|
|2.try_lock/NON_BLOCKING|if mutex is acquired by any other thread it returns back immediately ie does not block|no|
|3.Recurive Mutex|Locking same mutex again|yes|
|4.Timed_mutex_try_lock_for|Unlike try_lock(){Which returns immediately} this waits for specific timeout duration and returns if lock is not acquired during that time.|no|
|5.timed_mutex_try_lock_until|same as Timed_mutex_try_lock_for but waits for specific time from present|no|
