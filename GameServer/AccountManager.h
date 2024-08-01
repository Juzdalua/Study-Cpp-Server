#pragma once
class AccountManager
{
	USE_LOCK;

public:
	void AccountThenPlayerLock();
	void Lock();
};

extern AccountManager GAccountManager;