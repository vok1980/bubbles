
#pragma once


#include <list>

#include "IBoardSize.h"

class IGameObjVisitor;


class CGameObject : public IDimension
{
public:
	CGameObject(CGameObject *pParent);
	virtual ~CGameObject();

public:
	virtual void AcceptVisitor(IGameObjVisitor*) = 0;

public:
	void AddChild(CGameObject*);
	void RemoveChild(CGameObject*);
	int GetChildCount() const;
	
	CGameObject* GetParent(void) const;

private:
	void AtachToParent(CGameObject *pParent);
	void DetachFromParent(void);

private:
	typedef std::list<CGameObject*> ObjectsColl_t;
	ObjectsColl_t m_aObjects;
	CGameObject* m_pParent;
};

