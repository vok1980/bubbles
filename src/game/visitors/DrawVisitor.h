
#pragma once

#include "IGameObjVisitor.h"



class CDrawVisitor : public IGameObjVisitor
{
public:
	CDrawVisitor();

private:
	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void Visit(CScoreboard*);
	virtual void PostVisit(CGameObject*);
};
