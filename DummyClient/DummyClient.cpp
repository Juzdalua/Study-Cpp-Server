#include "pch.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "ThreadManager.h"

char sendData[] = "Hello World";

class ServerSession : public PacketSession
{
public:
	virtual ~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

public:
	virtual void OnConnected() override
	{
		cout << "Connected to Server" << endl;

	}

	virtual int32 OnRecvPacket(BYTE* buffer, int32 len) override
	{
		//PacketHeader header = *((PacketHeader*)buffer);
		PacketHeader header = *reinterpret_cast<PacketHeader*>(buffer);
		//cout << "Packet ID: " << header.id << ", Size: " << header.size << endl;

		char recvBuffer[4096];
		memcpy(recvBuffer, &buffer[4], header.size - sizeof(PacketHeader));
		cout << recvBuffer << endl;

		cout << "OnRecv Len = " << len << endl;
		this_thread::sleep_for(1s);
		
		SendBufferRef sendBuffer = GSendBufferManager->Open(4096);
		memcpy(sendBuffer->Buffer(), sendData, sizeof(sendData));
		sendBuffer->Close(sizeof(sendData));

		Send(sendBuffer);

		return len;
	}

	virtual void OnSend(int32 len) override
	{
		//cout << "OnSend Len = " << len << endl;
	}

	virtual void OnDisconnected() override
	{
		//cout << "Disconnected" << endl;
	}
};

int main()
{
	this_thread::sleep_for(1s);

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>,
		5
	);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 2; i++)
	{
		GThreadManager->Launch([=]() {
			while (true)
			{
				service->GetIocpCore()->Dispatch();
			}
			});
	}

	GThreadManager->Join();
}