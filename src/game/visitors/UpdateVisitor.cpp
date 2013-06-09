
#include <algorithm>

#include "UpdateVisitor.h"

#include "../GameObject.h"
#include "../Bubble.h"



CUpdateVisitor::CUpdateVisitor(float fDeltaTime) : 
	m_fDeltaTime(fDeltaTime)
{
}


CUpdateVisitor::~CUpdateVisitor()
{ 
	std::for_each(m_aUnvalidItems.begin(), m_aUnvalidItems.end(),
		[](const UnvalidItems_t::value_type &refItem)
		{
			delete refItem;
		}
	);
}


void CUpdateVisitor::Visit(CScene*)
{
}


void CUpdateVisitor::Visit(CBubble *pBubble)
{
	pBubble->m_iPosY += pBubble->GetVelocity() * m_fDeltaTime;
	
	if (!pBubble->IsValid())
	{
		m_aUnvalidItems.push_back(pBubble);
	}
}


void CUpdateVisitor::PostVisit(CGameObject*)
{
}

