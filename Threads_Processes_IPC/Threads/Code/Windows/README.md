### Create Threads
```c
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
using namespace std;
DWORD WINAPI worker(LPVOID param) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int* data = (int*)param;
	TCHAR buf[60];
	DWORD dwChar;
	StringCchPrintf(buf, 60, TEXT("val=%d"), *data);
	WriteConsole(hStdout, buf, 10, &dwChar, nullptr);
	return 0;
}

int _tmain() {
	DWORD thread_id[5];
	for (int i = 0; i < 5; ++i) {
		CreateThread(
			NULL,               //Default security attributes
			0,                  //Use default stack size
			worker,             //thread function
			(void*)i,           //argument to thread function
			0,                  //Default creation flag
			&thread_id[i]);     //Thread identifier returned
	}

}
```
