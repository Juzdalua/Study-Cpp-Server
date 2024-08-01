#pragma once
class PlayerManager
{
	USE_LOCK;

public:
	void PlayerThenAccount();
	void Lock();

private:
};

extern PlayerManager GPlayerManager;