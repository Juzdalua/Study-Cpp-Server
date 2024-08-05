#pragma once

/*-----------------------
	Memory Header
-----------------------*/
// [32] [64] [  ] [  ] [  ] [  ] [  ]
struct MemoryHeader
{
	// [Memory Header] [Data]
	// 데이터의 크기, 데이터의 주소 등 정보를 저장하는 header
	MemoryHeader(int32 size) : allocSIze(size) {}

	static void* AttachHeader(MemoryHeader* header, int32 size)
	{
		new(header)MemoryHeader(size); // placement new
		return reinterpret_cast<void*>(++header);
	}

	static MemoryHeader* DetatchHeader(void* ptr)
	{
		MemoryHeader* header = reinterpret_cast<MemoryHeader*>(ptr) - 1;
		return header;
	}

	int32 allocSIze;
};

/*-----------------------
	Memory Pool
-----------------------*/

class MemoryPool
{
public:
	MemoryPool(int32 allocSize);
	~MemoryPool();

	void Push(MemoryHeader* ptr);
	MemoryHeader* Pop();

private:
	int32 _allocSize = 0;
	atomic<int32> _allocCount = 0;

	USE_LOCK;
	queue<MemoryHeader*> _queue;
};

