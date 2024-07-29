#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave() {
	// user lock
	lock_guard<mutex> guard(this->_mutex);

	// account lock
	AccountManager::instance()->GetAccount(100);
}