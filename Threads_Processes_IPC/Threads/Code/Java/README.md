**Create Threads**
- Using Thread class

### Using Thread class
```java
class test implements Runnable {		//Class should implement Runnable Interface to create Thread
    test() {
        Thread cur = Thread.currentThread();

        Thread t = new Thread (this, "New thread"); //1. Created child thread
        t.start();                                  //2. Started child thread. if start() is not called, Child Thread will not start
        try {
            for (int i = 0; i < 6; ++i) {
                System.out.println ("Parent Thread");       //Parent process waits 1sec
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println ("Interrupted");
        }
        System.out.println ("exiting main thread");
    }
    public void run () {
        try {
            for (int i = 0; i < 3; ++i) {
                System.out.println ("Child Thread");        //Child Thread waits 2sec
                Thread.sleep(2000);
            }
        }
        catch (InterruptedException e) {
            System.out.println ("child interrupted");
        }
        System.out.println ("exiting child thread");
    }
    public static void main (String args[]) {
        new test();					//1. Calls constructor
    }
}
$ javac test.java
$ java test
$ java test
Parent Thread
Child Thread
Parent Thread
Child Thread
Parent Thread
Parent Thread
Child Thread
Parent Thread
Parent Thread
exiting child thread
exiting main thread
```
