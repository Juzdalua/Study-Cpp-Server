#include "pch.h"
#include "CorePch.h"
#include "ThreadManager.h"
#include "SocketUtils.h"
#include <iostream>

int main()
{
	SOCKET socket = SocketUtils::CreateSocket();
	SocketUtils::BindAnyAddress(socket, 7777);
	SocketUtils::Listen(socket);

	SOCKET clientSocket = accept(socket, nullptr, nullptr);

	cout << "Client Connected!" << endl;

	while (true)
	{

	}

	GThreadManager->Join();
}