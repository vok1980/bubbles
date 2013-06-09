
#pragma once


#include <list>

#include "IBoardSize.h"


class CGameObject : public IDimension
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
	int GetChildCount() const;

private:
	void AtachToParent(CGameObject *pParent);

protected:
	typedef std::list<CGameObject*> ObjectsColl_t;
	ObjectsColl_t m_aObjects;

private:	
	CGameObject* m_pParent;
};

