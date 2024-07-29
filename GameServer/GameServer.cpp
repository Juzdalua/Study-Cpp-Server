#include "pch.h"
#include "CorePch.h"
#include <iostream>
#include <thread>
#include "AccountManager.h"
#include "UserManager.h"

void Func1() {
	for (int32 i = 0; i < 1'000; i++) {
		UserManager::Instance()->ProcessSave();
	}
}

void Func2() {
	for (int32 i = 0; i < 1'000; i++) {
		AccountManager::instance()->ProcessLogin();
	}
}

int main()
{
	thread t1(Func1);
	thread t2(Func2);

	t1.join();
	t2.join();

	cout << "done" << endl;
}
