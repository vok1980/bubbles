
#pragma once


#include <list>
#include "IGameObjVisitor.h"


/**
 *	This visitor updates game objects 
 *	for fDeltaTime time elapsed 
 */
class CUpdateVisitor : public IGameObjVisitor
{
public:
	CUpdateVisitor(float fDeltaTime);
	virtual ~CUpdateVisitor();

private:
	virtual void Visit(CScene*);
	virtual void Visit(CBubble*);
	virtual void Visit(CScoreboard*);
	virtual void PostVisit(CGameObject*);

private:
	float m_fDeltaTime;
	typedef std::list<CGameObject*> UnvalidItems_t;
	UnvalidItems_t m_aUnvalidItems;
};
