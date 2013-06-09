
#pragma once

#include <list>
#include <vector>

#include "IGameObjVisitor.h"

#include "point.h"

class CScoreboard;


class CClickVisitor : public IGameObjVisitor
{
public:
	CClickVisitor(const std::list< SPoint > &_aClicksColl);
	virtual ~CClickVisitor();

public:
	void ChargePoints(CScoreboard *pScore);

	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void Visit(CScoreboard*);

	virtual void PostVisit(CGameObject*);

private:
	std::vector< SPoint > m_aClicksColl;
	std::list<CBubble*> m_aClickedBubbles;
};