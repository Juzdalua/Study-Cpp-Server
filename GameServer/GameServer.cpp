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

int main()
{
	Vector<int32> v(100);
	Map<int32, Knight> m;
	m[100] = Knight();
}
