
#pragma once


#include "IGameObjVisitor.h"


/**
 *	Visitor that simply calculates a number of bubbles in 
 *	game object tree.
 */
class CCalcBubblesVisitor : public IGameObjVisitor
{
public:
	CCalcBubblesVisitor();
	int GetCount(void);

private:
	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void Visit(CScoreboard*);
	virtual void PostVisit(CGameObject*);

private:
	int m_iCount;
};

