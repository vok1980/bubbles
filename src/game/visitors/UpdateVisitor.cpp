
#include <algorithm>

#include "UpdateVisitor.h"

#include "GameObject.h"
#include "Bubble.h"



CUpdateVisitor::CUpdateVisitor(float fDeltaTime) : 
	m_fDeltaTime(fDeltaTime)
{
}


/**
 *	Deleting unvalid objects on destruction
 */
CUpdateVisitor::~CUpdateVisitor()
{ 
	std::for_each(m_aUnvalidItems.begin(), m_aUnvalidItems.end(),
		[](const UnvalidItems_t::value_type &refItem)
		{
			delete refItem;
		}
	);
}


/**
 *	Do nothing
 */
void CUpdateVisitor::Visit(CScene*)
{
}


/**
 *	Do nothing
 */
void CUpdateVisitor::Visit(CScoreboard *pBubble)
{
}


/**
 *	Moving bubbles and collecting unvalid ones.
 *	Unvalid are thouse, which have leaved the scene.
 */
void CUpdateVisitor::Visit(CBubble *pBubble)
{
	pBubble->Move(m_fDeltaTime);
	
	if (!pBubble->IsValid())
	{
		m_aUnvalidItems.push_back(pBubble);
	}
}


/**
 *	Do nothing
 */
void CUpdateVisitor::PostVisit(CGameObject*)
{
}

