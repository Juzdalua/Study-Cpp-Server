#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>
#include "RefCounting.h"
#include "Memory.h"
#include "Allocator.h"

class Player{};

class Knight : public Player{
public:
	Knight() { cout << "생성자" << endl; }
	~Knight() { cout << "소멸자" << endl; }

	int32 _hp = 100;
};

class Monster
{
public:
	int64 _id = 0;
};

int main()
{
	Knight* k = ObjectPool<Knight>::Pop();
	ObjectPool<Knight>::Push(k);

	// shared_ptr -> { allocator, deleter }
	shared_ptr<Knight> sptr = ObjectPool<Knight>::MakeShared();

	for (int32 i = 0; i < 5; i++) 
	{
		GThreadManager->Launch([]() {
			while (true)
			{
				Vector<int32> v(100);
				Map<int32, Knight> m;
				m[100] = Knight();
				this_thread::sleep_for(10ms);
			}
			});
	}

	GThreadManager->Join();
}
