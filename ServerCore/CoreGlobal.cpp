#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "DeadLockProfiler.h"
#include "Memory.h"
#include "SocketUtils.h"
#include "SendBuffer.h"

ThreadManager* GThreadManager = nullptr;
DeadLockProfiler* GDeadLockProfiler = nullptr;
Memory* GMemory = nullptr;
CoreGlobal GCoreGlobal;
SendBufferManager* GSendBufferManager = nullptr;

CoreGlobal::CoreGlobal() {
	GThreadManager = new ThreadManager;
	GMemory = new Memory();
	GDeadLockProfiler = new DeadLockProfiler;
	GSendBufferManager = new SendBufferManager();
	SocketUtils::Init();
}

CoreGlobal::~CoreGlobal() {
	delete GThreadManager;
	delete GMemory;
	delete GDeadLockProfiler;
	delete GSendBufferManager;
	SocketUtils::Clear();
} 