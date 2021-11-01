#include "dispatcher.h"
#include "request.h"

#include <cstring>
#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>
using namespace std;

sig_atomic_t signal_caught = 0;
mutex logMutex;

void signal_handler (int sig) {
  signal_caught = 1;
}

void logFn(string strText) {
  logMutex.lock();
  cout << strText << endl;
  logMutex.unlock();
}

int main() {
    signal (SIGINT, &signal_handler);
    Dispatcher::init(10);
    cout << "Initialized" << endl;
    int cycles = 0;
}
