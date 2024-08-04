#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>
#include "RefCounting.h"
#include "Memory.h"

class Player{};

class Knight : public Player{
public:
	Knight() { cout << "생성자" << endl; }
	~Knight() { cout << "소멸자" << endl; }

	int32 _hp = 100;
};

int main()
{
	Knight* k = xnew<Knight>();
	xdelete(k);
	k->_hp = 1;

	Knight* p = (Knight*)xnew<Player>();
	p->_hp = 2;
	xdelete(p); // Error - Memory Overflow
}
