#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>

CoreGlobal Core;

void ThreadMain() {
	while (true) {
		cout << "Hello: " << LThreadId << endl;
		this_thread::sleep_for(1s);
	}
}

int main()
{
	for (int32 i = 0; i < 5; i++) {
		GThreadManager->Launch(ThreadMain);
	}
	GThreadManager->Join();
}
