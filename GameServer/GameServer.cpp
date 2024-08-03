#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>
#include "RefCounting.h"
#include "Memory.h"

class Knight {
public:
	Knight() { cout << "생성자" << endl; }
	~Knight() { cout << "소멸자" << endl; }
};

int main()
{
	Knight* knight = new Knight();
	delete knight;

	Knight* knight1 = xnew<Knight>();
	xdelete(knight1);
}
