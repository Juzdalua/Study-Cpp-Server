#pragma once

extern class ThreadManager*			GThreadManager;
extern class DeadLockProfiler*		GDeadLockProfiler;
extern class Memory*				GMemory;
extern class SendBufferManager*		GSendBufferManager;

class CoreGlobal
{
public:
	CoreGlobal();
	~CoreGlobal();

private:
};

