#include "pch.h"
#include "CMonsterDetectRangeScript.h"
#include "CMonsterScript.h"

CMonsterDetectRangeScript::CMonsterDetectRangeScript()
	: CScript(static_cast<UINT>(SCRIPT_TYPE::MONSTERDETECTRANGESCRIPT))
{
}

CMonsterDetectRangeScript::~CMonsterDetectRangeScript()
{
}

void CMonsterDetectRangeScript::begin()
{
	GetOwner()->Collider3D()->SetOffsetScale({ 3000.f, 3000.f, 3000.f });
}

void CMonsterDetectRangeScript::tick()
{
}

void CMonsterDetectRangeScript::BeginOverlap(CCollider3D* _Other)
{
	// Player와 부딪힌 경우에만.
	if (_Other->GetOwner()->GetLayerIndex()	== static_cast<int>(LAYER::PLAYER))
	{
		GetOwner()->GetParent()->GetScript<CMonsterScript>()->SetDetect(true);
		Destroy();
	}
}
