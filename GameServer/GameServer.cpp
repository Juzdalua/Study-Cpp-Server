#include "pch.h"
#include "ThreadManager.h"
#include <iostream>
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ServerPacketHandler.h"

class Player
{
public:
	int32 hp = 0;
	int32 attack = 0;
	Player* target = nullptr;
	vector<int32> buffs;
};

int main()
{

	Player* player = new Player();
	delete player;
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
		vector<BuffData> buffs{ BuffData{100, 1.5f}, BuffData{200, 2.3f}, BuffData{300, 0.7f} };
		SendBufferRef sendBuffer = ServerPacketHandler::Make_S_TEST(1001, 100, 10, buffs, L"¾È³çÇÏ¼¼¿ä");

		GSessionManager.Broadcast(sendBuffer);

		this_thread::sleep_for(250ms);
	}

	GThreadManager->Join();
}