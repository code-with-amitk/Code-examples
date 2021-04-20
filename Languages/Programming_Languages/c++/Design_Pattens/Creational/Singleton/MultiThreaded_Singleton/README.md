## Multithreaded
- Below code is not thread-safe. if 2 threads run this code it will creates two objects for singleton.

Solution:
    1. Making fun() as synchronized (In Java)
            public static synchronized test fun(){        //Adding synchronized makes every thread to wait for its turn.    
            }
    2. Using Mutexes (In Linux)
    
Drawbacks of Synchronization: This is heavy/time consuming operation.
1. Do eagerly instance creation (instead of lazily done Below)
            public class test{
                    static test obj = new test(); //Since all threads have same DS. so there will be only 1 copy of obj.
                    test(){}
                    public:
                        static test fun(){  return obj;  }
            }
2. Check the variable before locking mutex//Double-Checking Locking
        class test{
                volatile test obj;
            public:
                static test fun(String n){
                        if(obj == NULL){        //Adding extra check for Object reduces overhead significantly.
                            pthread_mutex_lock(&var);
                                if(obj=NULL)
                                        obj = new test(n);
                            pthread_mutex_unlock(&var);
                        }
                        return obj;    
                }
        }
