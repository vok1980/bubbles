
#pragma once

#include <list>
#include <vector>
#include <set>

#include "IGameObjVisitor.h"

#include "point.h"

class CScoreboard;


/**
 *	This visitor transfers a click points to game objects.
 *	It collects a clicked buubles
 *	and then charges points from them
 */
class CClickVisitor : public IGameObjVisitor
{
public:
	CClickVisitor(std::list< SPoint > &_aClicksColl);
	virtual ~CClickVisitor();

public:
	void ChargePoints(CScoreboard *pScore);

	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void Visit(CScoreboard*);

	virtual void PostVisit(CGameObject*);

private:
	/// collection of click points
	std::vector< SPoint > m_aClicksColl;
	
	/// Only one instance should be in collection. 
	///	Thats why container is std::set
	std::set<CBubble*> m_aClickedBubbles;
};