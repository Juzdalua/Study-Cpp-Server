#pragma once

/*----------------------
	Base Allocator
----------------------*/

class BaseAllocator
{
public:
	static void* Alloc(int32 size);
	static void Release(void* ptr);
};

/*----------------------
	Stomp Allocator
----------------------*/

class StompAllocator {
	enum { PAGE_SIZE = 0x1000 }; // 4kb
public:
	static void* Alloc(int32 size);
	static void Release(void* ptr);
};

/*----------------------
	Pool Allocator
----------------------*/

class PoolAllocator {
	enum { PAGE_SIZE = 0x1000 }; // 4kb
public:
	static void* Alloc(int32 size);
	static void Release(void* ptr);
};

/*----------------------
	STL  Allocator
----------------------*/

template<typename T>
class STLAllocator
{
public:
	using value_type = T;

	STLAllocator() {}

	template<typename Other>
	STLAllocator(const STLAllocator<Other>&) {}

	T* allocate(size_t count)
	{
		const int32 size = static_cast<int32>(count * sizeof(T));
		//return static_cast<T*>(Xalloc(size));
		return static_cast<T*>(PoolAllocator::Alloc(size));
	}

	void deallocate(T* ptr, size_t count)
	{
		//Xrelease(ptr);
		PoolAllocator::Release(ptr);
	}
};