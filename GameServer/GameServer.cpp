#include "pch.h"
#include "CorePch.h"
#include "CoreMacro.h"
#include "ThreadManager.h"
#include <iostream>
#include "RefCounting.h"

class Wraith: public RefCountable {
public:
	int _hp = 150;
	int _posX = 0;
	int _posY = 0;
};

using WraithRef = TSharedPtr<Wraith>;

class Missile : public RefCountable {
public:

	void SetTarget(WraithRef target) {
		_target = target;
	}

	bool Update() {
		if (_target == nullptr)
			return true;

		int posX = _target->_posX;
		int posY = _target->_posY;

		// TODO: 쫓아간다

		if (_target->_hp == 0) {
			_target = nullptr;
			return true;
		}
		return false;
	}

	WraithRef _target = nullptr;
};

using MissileRef = TSharedPtr<Missile>;

int main()
{
	WraithRef wraith(new Wraith());
	wraith->ReleaseRef();
	MissileRef missile(new Missile());
	missile->ReleaseRef();
	missile->SetTarget(wraith);

	// 레이스가 피격 당함
	wraith->_hp = 0;
	wraith = nullptr; // WraithRef(nullptr)

	while (true) {
		if (missile) {
			if (missile->Update()) {
				missile->ReleaseRef();
				missile = nullptr;
			}
		}
	}
	missile = nullptr;
}
