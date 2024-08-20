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
		if (packetSize < size)
			return false;

		size += buffsCount * sizeof(BuffListItem);
		if (size != packetSize)
			return false;

		if (buffsOffset + buffsCount * sizeof(BuffListItem) > packetSize)
			return false;

		return true;
	}

	using BuffList = PacketList<PKT_S_TEST::BuffListItem>;
	BuffList GetBuffList()
	{
		BYTE* data = reinterpret_cast<BYTE*>(this);
		data += buffsOffset;
		return BuffList(reinterpret_cast<PKT_S_TEST::BuffListItem*>(data), buffsCount);
	}
};
#pragma pack()

void ClientPacketHandler::Handle_S_TEST(BYTE* buffer, int32 len)
{
	BufferReader br(buffer, len);

	PKT_S_TEST* pkt = reinterpret_cast<PKT_S_TEST*>(buffer);
	
	if (pkt->Validate() == false)
		return;

	cout << "ID: " << pkt->id << ", HP: " << pkt->hp << ", ATK: " << pkt->attack << endl;

	PKT_S_TEST::BuffList buffs = pkt->GetBuffList();

	cout << "BuffCOunt: " << buffs.Count() << endl;
	for (int32 i = 0; i < buffs.Count(); i++)
	{
		cout << "BuffInfo: " << buffs[i].buffId << " / " << buffs[i].remainTime << endl;
	}

	for (auto it = buffs.begin(); it != buffs.end(); it++)
	{
		cout << "BuffInfo: " << it->buffId << " / " << it->remainTime << endl;
	}

	for (auto& buff:buffs)
	{
		cout << "BuffInfo: " << buff.buffId << " / " << buff.remainTime << endl;
	}
}
