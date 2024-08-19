#include "pch.h"
#include "ClientPacketHandler.h"
#include "BufferReader.h"

void ClientPacketHandler::HandlePacket(BYTE* buffer, int32 len)
{
	BufferReader br(buffer, len);
	PacketHeader header;
	br >> header;

	switch (header.id)
	{
	case S_TEST:
		Handle_S_TEST(buffer, len);
		break;

	default:
		break;
	}
}

#pragma pack(1)
// [����������][����������]
// [PKT_S_TEST][BuffListItem BuffListItem BuffListItem ...]
struct PKT_S_TEST
{
	struct BuffListItem
	{
		uint64 buffId;
		float remainTime;
	};

	// Header
	uint16 packetSize;
	uint16 packetId;

	// Data
	uint64 id;
	uint32 hp;
	uint16 attack;

	/*
		���� ������
		1) ���ڿ� - �г���
		2) ����Ʈ �迭 - ��� �̹���
		3) �Ϲ� ����Ʈ
	*/
	uint16 buffsOffset; // ���� �������� ���� �ּ� ��ġ
	uint16 buffsCount; // ���� ������ ����

	bool Validate()
	{
		uint32 size = 0;
		size += sizeof(PKT_S_TEST);
		size += buffsCount * sizeof(BuffListItem);

		if (size != packetSize)
			return false;

		if (buffsOffset + buffsCount * sizeof(BuffListItem) > packetSize)
			return false;

		return true;
	}
	//vector<BuffListItem> buffs;
	//wstring name;
};
#pragma pack()

void ClientPacketHandler::Handle_S_TEST(BYTE* buffer, int32 len)
{
	BufferReader br(buffer, len);

	if (len < sizeof(PKT_S_TEST))
		return;

	PKT_S_TEST pkt;
	br >> pkt;
	
	if (pkt.Validate() == false)
		return;

	cout << "ID: " << pkt.id << ", HP: " << pkt.hp << ", ATK: " << pkt.attack << endl;

	vector<PKT_S_TEST::BuffListItem> buffs;
	buffs.resize(pkt.buffsCount);
	for (int32 i = 0; i < pkt.buffsCount; i++)
	{
		br >> buffs[i];
	}

	cout << "BuffCOunt: " << pkt.buffsCount << endl;
	for (int32 i = 0; i < pkt.buffsCount; i++)
	{
		cout << "BuffInfo: " << buffs[i].buffId << " / " << buffs[i].remainTime << endl;
	}
}
