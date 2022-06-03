**Synchronization in Java**
- Example: 
  - [1. Communication b/w Parent, Child Thread](#e1)

### synchronization in Java
- [What is synchronization](/Threads_Processes_IPC/IPC/synchronization/README.md#sy)
- **How Java achieves synchronization?** 
  - Method itself is made synchronized
  - Only 1 thread can execute a synchronized method at a time.
```java
synchronized void fun() {
  ...
}
```

### Examples
#### 1. Communication b/w Parent, Child Thread
```java
class test implements Runnable {
    test() {
        Thread t = new Thread (this);             //2. Create child thread
        t.start();                                //3. Start child thread ie call run()
        System.out.println ("Parent execute");    //6. Child waiting, Parent execute
    }
    synchronized void notifyChild() {
        System.out.println ("Notifying the waiting thread");
        this.notify();
    }
    synchronized public void run() {                //4. Child thread will wait
        try {
            System.out.println ("Child Thread wait");
            this.wait();                            //wait()=sleep(). And hence Parent gets control
        }
        catch(InterruptedException e) {
        }
        System.out.println ("Child Thread completing");
    }
    public static void main(String args[]) {
        test t = new test();                       //1. Call Constructor
        t.notifyChild();                           //7. Parent notifies waiting thread
    }
}
$ javac test.java
$ java test
Parent execute
Child Thread wait
Notifying the waiting thread
Child Thread completing
```
