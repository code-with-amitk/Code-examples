#include<iostream>
#include<thread>
#include<vector>
#include <unistd.h>
using namespace std;

class hitCount {
	std::vector<std::thread> thread_arr;
	int hitCount[3600]={0}, counter=0;
	long int timer_seconds=0;
public:
	void thread_func1() {
		cout<<"Writer Thread1"<<endl;
		int var;
		srand(time(NULL));
		cout<<endl;
		while(1) {
			if(counter == 3600) counter=0;
			var = rand()%1000;
			hitCount[counter] = var;
			cout<<"Hit count this second hitCount["<<counter<<"]="<<var<<" timer="<<timer_seconds<<endl;
			timer_seconds++;
			counter++;
			sleep(1);
		}
	}
	void thread_func2() {
		cout<<"Reader Thread2"<<endl;
		int counter_h, temp;
		while(1) {
			//Afer every 10 seconds => Reads hit count of last 10 seconds
			if ((timer_seconds%10 == 0) && (timer_seconds/10 != 0)) {
				temp = 0;
				counter_h = counter;
				for(int i=(counter_h - 10);i<counter_h;i++) {
					temp += hitCount[i];
				}
				cout<<"Hit Count in Last 10 seconds="<<temp<<endl<<endl;
			}

			//Afer every 30 seconds => Reads hit count of last 1 hour
			if ((timer_seconds%30 == 0) && (timer_seconds/30 != 0)) {
				temp = 0;
				for (int i=0;i<3600;i++) {
					temp += hitCount[i];
				}
				cout<<"Hit Count in Last 1 Hour="<<temp<<endl<<endl;
			}
			sleep(2);
		}
	}
	void make_thread1() {
		thread_arr.push_back(thread(&hitCount::thread_func1, this));
		cout<<"Writer Thread1 created"<<endl;
	}
	void make_thread2() {
		thread_arr.push_back(thread(&hitCount::thread_func2, this));
		cout<<"Reader Thread2 created"<<endl;
	}
	void jointhem() {
		thread_arr[0].join();
		thread_arr[1].join();
	}
};


int main() {
	cout<<"Main Thread.."<<endl;
	hitCount obj;
	obj.make_thread1();	
	obj.make_thread2();
	obj.jointhem();	
	return 0;
}
