#include "pch.h"
#include "CorePch.h"
#include "ThreadManager.h"
#include "SocketUtils.h"
#include <iostream>
#include "Listener.h"

int main()
{
	/*SOCKET socket = SocketUtils::CreateSocket();
	SocketUtils::BindAnyAddress(socket, 7777);
	SocketUtils::Listen(socket);
	SOCKET clientSocket = accept(socket, nullptr, nullptr);
	cout << "Client Connected!" << endl;*/

	Listener listener;
	listener.StartAccept(NetAddress(L"127.0.0.1", 7777));

	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([=]() {
			while (true)
			{
				GIocpCore.Dispatch();
			}
			});
	}

	GThreadManager->Join();
}