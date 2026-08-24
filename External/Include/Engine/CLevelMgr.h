#pragma once
#include "CSingleton.h"

class CLevel;
class CGameObject;

class CLevelMgr :
    public CSingleton<CLevelMgr>
{   
    SINGLE(CLevelMgr);
private:
    CLevel*     m_pCurLevel;

public:
    CLevel*      GetCurLevel() const { return m_pCurLevel; }
    CGameObject* FindObjectByName(const wstring& _strName) const;
    void         FindObjectByName(const wstring& _strName, vector<CGameObject*>& _Out) const;

    void ChangeLevel(CLevel* _NextLevel);

public:
    void init();
    void tick() const;
};

