#pragma once
#include "Session.h"

class GameSession : public PacketSession
{
public:
	virtual ~GameSession()
	{
		cout << "~GameSession" << endl;
	}

public:
	virtual void OnConnected() override;
	virtual void OnDisconnected() override;
	virtual int32 OnRecvPacket(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;
};