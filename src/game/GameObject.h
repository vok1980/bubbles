
#pragma once


#include <list>


class CGameObject
{
public:
	CGameObject(CGameObject *pParent);
	virtual ~CGameObject();

public:
	virtual bool Update(double dTimeDelta) = 0;
	virtual void Draw(void) = 0;

public:
	void AddChild(CGameObject*);
	void RemoveChild(CGameObject*);

private:
	void AtachToParent(CGameObject *pParent);

private:
	std::list<CGameObject*> m_aObjects;
	CGameObject* m_pParent;
};

