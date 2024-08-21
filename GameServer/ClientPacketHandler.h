#pragma once
#include "Protocol.pb.h"

using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

// [1]
enum : uint16
{
	PKT_C_TEST = 1000,
	PKT_C_MOVE = 1001,
	PKT_S_TEST = 1002,
	PKT_S_LOGIN = 1003,
};

// Custom Handler
bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);

// [2]
bool Handle_C_TEST(PacketSessionRef& session, Protocol::C_TEST &pkt);
bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE &pkt);

class ClientPacketHandler
{
public:
	static void Init()
	{
		for (int32 i = 0; i < UINT16_MAX; i++)
		{
			GPacketHandler[0] = Handle_INVALID;
		}

// [3]
		GPacketHandler[PKT_C_TEST] = [](PacketSessionRef& session, BYTE* buffer, int32 len)
			{
				return HandlePacket<Protocol::C_TEST>(Handle_C_TEST, session, buffer, len);
			};
		GPacketHandler[PKT_C_MOVE] = [](PacketSessionRef& session, BYTE* buffer, int32 len)
			{
				return HandlePacket<Protocol::C_MOVE>(Handle_C_MOVE, session, buffer, len);
			};
	}

	static bool HandlePacket(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

		return GPacketHandler[header->id](session, buffer, len);
	}
// [4]
	static SendBufferRef MakeSendBuffer(Protocol::S_TEST &pkt) { return MakeSendBuffer(pkt, PKT_S_TEST); }
	static SendBufferRef MakeSendBuffer(Protocol::S_LOGIN &pkt) { return MakeSendBuffer(pkt, PKT_S_LOGIN); }

private:
	template<typename PacketType, typename ProcessFunc>
	static bool HandlePacket(ProcessFunc func, PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;

		return func(session, pkt);
	}

	template<typename T>
	static SendBufferRef MakeSendBuffer(T& pkt, uint16 pktId)
	{
		const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
		const uint16 packetSize = dataSize + sizeof(PacketHeader);

		SendBufferRef sendBuffer = GSendBufferManager->Open(packetSize);

		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
		header->size = packetSize;
		header->id = pktId;

		ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));

		sendBuffer->Close(packetSize);
		return sendBuffer;
	}
};
