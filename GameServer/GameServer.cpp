#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>
#include "RefCounting.h"
#include "Memory.h"
#include "Allocator.h"

using TL = TypeList<class Mage, class Knight, class Archer, class Player>;

enum PLAYER_TYPE
{
	KNIGHT,
	MAGE
};

class Player
{
public:
	Player() { INIT_TL(Player); }
	virtual ~Player() {}
	DECLARE_TL
};

class Knight : public Player {
public:
	Knight() { INIT_TL(Knight) }
	~Knight() { cout << "소멸자" << endl; }

	int32 _hp = 100;
};

class Mage : public Player {
public:
	Mage() { INIT_TL(Mage) }
};

class Archer : public Player {
public:

};

class Dog {};

void AttackPlayer(Player* player)
{

}

int main()
{
	Player* p1 = new Knight();
	Player* p2 = new Mage();

	Knight* k1 = dynamic_cast<Knight*>(p1);
	//if (p1->_type == KNIGHT)
	//{
	//	//Knight* k1 = (Knight*)p1;
	//	Knight* k1 = static_cast<Knight*>(p1);
	//}

	TypeList<Mage, Knight>::Head who1; // Mage
	TypeList<Mage, Knight>::Tail who2; // Knight

	TypeList<Mage, TypeList<Knight, Archer>>::Tail::Head who3; // Knight
	TypeList<Mage, TypeList<Knight, Archer>>::Tail::Tail who4; // Archer

	int32 len1 = Length<TypeList<Mage, Knight>>::value; // 2
	int32 len2 = Length<TypeList<Mage, Knight, Archer>>::value; // 3

	TypeAt<TL, 0>::Result who5; // Mage
	TypeAt<TL, 1>::Result who6; // Knight
	TypeAt<TL, 2>::Result who7; // Archer

	int32 index1 = IndexOf<TL, Mage>::value; // 0
	int32 index2 = IndexOf<TL, Knight>::value; // 1
	int32 index3 = IndexOf<TL, Archer>::value; // 2
	int32 index4 = IndexOf<TL, Dog>::value; // -1

	bool canConvert1 = Conversion<Player, Knight>::exists;
	bool canConvert2 = Conversion<Knight, Player>::exists;
	bool canConvert3 = Conversion<Knight, Dog>::exists;

	TypeConversion<TL> test;
	test.s_convert[0][0];
	
	{
		Player* player = new Player();
		Player* knight = new Knight();

		bool canCast1 = CanCast<Knight*>(player);
		Knight* pknight = TypeCast<Knight*>(player);

		bool canCast2 = CanCast<Knight*>(knight);
		Knight* kknight = TypeCast<Knight*>(knight);
		
		delete player;
		delete knight;
	}

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
