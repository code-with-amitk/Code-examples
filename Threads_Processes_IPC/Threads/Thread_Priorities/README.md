**Thread Priorities**
- Create 2 threads of different Priority
  - [1. Java](#e1)

## Thread Priorities
- Higher the Priority, higher is the preference of execution to a particular thread. ie if 2 threads are started at sametime, thread with higher priority will execute 1st.
- **Java:** Java has 10 priorities. 0=Lowest, 10=Highest. Thread is created with priority=5

### Create 2 threads of different Priority
#### 1. Java
```java
class test implements Runnable {
    test() {
        Thread cur = Thread.currentThread();
        cur.setPriority (Thread.NORM_PRIORITY + 1);         //2. Increase Main Process priority=6

        Thread t = new Thread (this, "New thread");         //3. Created child thread
        t.start();                                          //4. Started

        for (int cnt = 0; cnt < 3; cnt ++)                  //5. But Parent will execute (not child)
            System.out.println ("Parent Thread : "+ cnt);
    }
    public void run () {
        for (int i = 0; i < 3; i++)                         //6. Child executes once Parent finishes
            System.out.println ("Child Thread : " + i);
    }
    public static void main (String args[]) {
        new test();                                       //1. Execute constructor
    }
}
$ javac test.java
$ java test
Parent Thread : 0
Parent Thread : 1
Parent Thread : 2
Child Thread : 0
Child Thread : 1
Child Thread : 2
```
