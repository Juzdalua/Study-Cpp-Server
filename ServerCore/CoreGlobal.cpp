#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "DeadLockProfiler.h"
#include "Memory.h"
#include "SocketUtils.h"

ThreadManager* GThreadManager = nullptr;
DeadLockProfiler* GDeadLockProfiler = nullptr;
Memory* GMemory = nullptr;
CoreGlobal GCoreGlobal;

CoreGlobal::CoreGlobal() {
	GThreadManager = new ThreadManager;
	GMemory = new Memory();
	GDeadLockProfiler = new DeadLockProfiler;
	SocketUtils::Init();
}

CoreGlobal::~CoreGlobal() {
	delete GThreadManager;
	delete GMemory;
	delete GDeadLockProfiler;
	SocketUtils::Clear();
} 