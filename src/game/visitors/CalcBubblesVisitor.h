
#pragma once


#include "IGameObjVisitor.h"


class CCalcBubblesVisitor : public IGameObjVisitor
{
public:
	CCalcBubblesVisitor();
	int GetCount(void);

private:
	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void PostVisit(CGameObject*);

private:
	int m_iCount;
};

