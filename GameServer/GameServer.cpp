#include "pch.h"
#include "ThreadManager.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"

int main()
{
	/*SOCKET socket = SocketUtils::CreateSocket();
	SocketUtils::BindAnyAddress(socket, 7777);
	SocketUtils::Listen(socket);
	SOCKET clientSocket = accept(socket, nullptr, nullptr);
	cout << "Client Connected!" << endl;*/

	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<GameSession>,
		100
	);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([=]() {
			while (true)
			{
				service->GetIocpCore()->Dispatch();
			}
			});
	}

	char sendData[] = "Hello World!";
	while (true)
	{
		SendBufferRef sendBuffer = GSendBufferManager->Open(4096);

		BufferWriter bw(sendBuffer->Buffer(), 4096);
		PacketHeader* header = bw.Reserve<PacketHeader>();

		// id(uint64), ü��(uint32), ���ݷ�(uint16)
		bw << (uint64)1001 << (uint32)100 << (uint16)10;
		bw.Write(sendData, sizeof(sendData));

		header->size = bw.WriteSize();
		header->id = 1;

		sendBuffer->Close(bw.WriteSize());

		GSessionManager.Broadcast(sendBuffer);

		this_thread::sleep_for(250ms);
	}

	GThreadManager->Join();
}