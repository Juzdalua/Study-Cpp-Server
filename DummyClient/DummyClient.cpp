﻿#include "pch.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "ThreadManager.h"
#include "ServerPacketHandler.h"

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
		/*Protocol::C_MOVE movePacket;
		auto sendBuffer = ServerPacketHandler::MakeSendBuffer(movePacket);*/
		cout << "Connected to Server" << endl;

	}

	virtual void OnRecvPacket(BYTE* buffer, int32 len) override
	{
		PacketSessionRef session = GetPacketSessionRef();
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

		ServerPacketHandler::HandlePacket(session, buffer, len);
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
	ServerPacketHandler::Init();
	this_thread::sleep_for(1s);

	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>,
		1
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