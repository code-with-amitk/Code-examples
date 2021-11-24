- [spinlock](#sl)
- [Code](#co)
- [Problems with spinlock](#p)

<a name=sl></a>
## Spin lock
- Thread-1(or process-1) is in Critical section and has set atomic variable var=1, before entering into CS. Thread-2 keeps checking var continously in while(1) to be 0 and enter CS.
- This consumes CPU but is 3 times faster than Mutex.
**Spinlocks are used in ISR**. Critical sections in [ISR(Interrupt service routines)](/Operating_Systems/Linux/Kernel/Interrupts/) are implemented using spinlocks, because spinlocks are 3 times faster than mutex.
- **Example**
  - _1._ Take [atomic_bool](/Threads_Processes_IPC/Terms).
  - _2._ lock() => Set atomic_bool to true atomically using [exchange()](https://en.cppreference.com/w/cpp/atomic/atomic/exchange)
  - _3._ unlock() => Replace the present value in atomic_bool using [store()](https://en.cppreference.com/w/cpp/atomic/atomic/store)
```c
  atomic_bool a;            //1
  lock() { a.exchange(true, std::memory_order_acquire);    //exchange(desired_value, memory order constraints to enforce) }//2
  unlock() { a.store(false, std::memory_order_release);}  //3
```
<a name=co></a>
### Code
```cpp
/// Program to calculate Duplicate elements using 3 threads.
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a = { 10, 1, 1, 20, 2, 2, 3, 30, 3 };
int asize = a.size();
int acount = 0, k = 0, last_index = asize/3, start_index = 0, temp=0;

struct my_spin_lock {
    static atomic_bool my_lock;
    static void lock() {
        while (my_lock.exchange(true, std::memory_order_acquire));
    }
    static void unlock() {
        my_lock.store(false, std::memory_order_release);
    }
};
atomic_bool my_spin_lock::my_lock = false;
void fun() {
    thread::id s = this_thread::get_id();
    cout << s << "\n";
    
    my_spin_lock::lock();                           //Lock spin lock
    
    sort(a.begin() + start_index, a.begin() + last_index);

    for (int i = start_index; i < last_index -1; ++i) {
        if (a[i] == a[i + 1])
            acount++;
    }
    temp = last_index;
    start_index = temp;
    last_index += 3;
    my_spin_lock::unlock();                        //unlock
}

int main() {
    auto startTime = chrono::high_resolution_clock::now();
    thread t1(fun);
    thread t2(fun);
    thread t3(fun);
    t1.join();
    t2.join();
    t3.join();
    auto stopTime = chrono::high_resolution_clock::now();
    cout << "Time:" << chrono::duration_cast<chrono::milliseconds>(stopTime - startTime).count() << atomic_count;
}

$./a.out
Time: 413.      //if we replace spinlock with mutex same algo takes 623 ms

```
 
<a name=p></a>
### Problems with spinlocks?
#### 1. Consumes more CPU
#### 2. Fast process need to wait until Slow is in spinlock
Consider 2 processes(fast and slow). Slow-Process enters critical section, CPU schedules slow-process for IO. Now fast-Process need to wait until slow-process's IO(slow operations) does not complete.
- **Solution: Peterson’s Solution:**
  - Before going into critical section each process or thread calls enter_region() function
  - Before leaving critical_section they call leave_region
```c
#define FALSE 0
#define TRUE 1
#define N 2         /* number of processes */
int turn;           /* whose turn is it? */
int interested[N]; /* all values initially 0 (FALSE) */

void enter region(int process){   
  int other;                            /* number of the other process */
  other = 1 − process;                  /* the opposite of process */
  interested[process] = TRUE;           /* show that you are interested */
  turn = process;                       /* set flag */
  while (turn == process && interested[other] == TRUE) /* null statement */ ;
}

void leave region(int process){              /* process: who is leaving */
  interested[process] = FALSE;              /* indicate departure from critical region */
}

///////////Thread-1 or Process-1//////////////
while (TRUE) {
  while (shared_var != 0)
    critical_section();
    shared_var = 1;
    noncritical_section();
  }
}

//////////Thread-2 or Process-2/////////////////
while (TRUE) {
  while (shared_var != 1)
    critical_section();
    shared_var = 0;
    noncritical_section();
  }
}
```
