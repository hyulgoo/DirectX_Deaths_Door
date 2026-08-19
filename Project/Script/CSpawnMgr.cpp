#include "pch.h"
#include "CSpawnMgr.h"
#include "CRoomScript.h"
#include "CFenceScript.h"

CSpawnMgr::CSpawnMgr()
	: m_iCurRoomNum(-1)
	, m_mapRoom{}
{
}
CSpawnMgr::~CSpawnMgr()
{
}

void CSpawnMgr::RegisterFence(int _iRoomNum, CFenceScript* _pFence)
{
	assert(_iRoomNum != -1);
	FenceInfo tFenceInfo;
	tFenceInfo.RoomNum = _iRoomNum;
	tFenceInfo.Fence = _pFence;
	m_vecFence.push_back(tFenceInfo);
}

void CSpawnMgr::RegisterRoom(int _iRoomNum, CRoomScript* _pRoom)
{
	assert(_iRoomNum != -1);
	m_mapRoom.insert(make_pair(_iRoomNum, _pRoom));
}

void CSpawnMgr::SpawnMonster(int _iRoomNum) const
{
	assert(_iRoomNum != -1);
	m_mapRoom.find(m_iCurRoomNum)->second->SpawnMst();
}

void CSpawnMgr::ActivateFence(int _iRoomNum, bool _bOpen)
{
	assert(_iRoomNum != -1);
	m_iCurRoomNum = _iRoomNum;
	if (!_bOpen)
		SpawnMonster(_iRoomNum);
	for (auto& iter : m_vecFence)
	{
		if (_iRoomNum == iter.RoomNum)
			iter.Fence->ActivateFence(_bOpen);
	}
}

void CSpawnMgr::ReduceMonsterCount() const
{
	//assert(m_iCurRoomNum != -1);
	m_mapRoom.find(m_iCurRoomNum)->second->ReduceMonsterCount();
}

void CSpawnMgr::ReduceGimmickCount() const
{
	assert(m_iCurRoomNum != -1);
	m_mapRoom.find(m_iCurRoomNum)->second->ReduceGimmickCount();
}

void CSpawnMgr::Clear()
{
	m_iCurRoomNum = -1;
	m_mapRoom.clear();
	m_vecFence.clear();
}
