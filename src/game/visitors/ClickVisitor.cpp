
#include <algorithm>

#include "ClickVisitor.h"

#include "Bubble.h"
#include "Scoreboard.h"





CClickVisitor::CClickVisitor(const std::list< SPoint > &_aClicksColl) :
	m_aClicksColl(_aClicksColl.begin(), _aClicksColl.end())
{	
}


CClickVisitor::~CClickVisitor()
{}


void CClickVisitor::Visit(CScene*)
{}


void CClickVisitor::ChargePoints(CScoreboard *pScore)
{
	while ( !m_aClickedBubbles.empty() )
	{	
		std::list<CBubble*>::iterator it = m_aClickedBubbles.begin();

		pScore->AddScore((*it)->GetPoints());
		delete *it;
		m_aClickedBubbles.erase(it);
	}
}


void CClickVisitor::Visit(CBubble *pObject)
{
	BoardSize_t iPosX;
	BoardSize_t iPosY;
	BoardSize_t iRadius;

	pObject->GetPosition(iPosX, iPosY, iRadius);
	const BoardSize_t iPowR2 = pow(iRadius, 2);

	std::for_each(m_aClicksColl.begin(), m_aClicksColl.end(),
		[this, pObject, iPosX, iPosY, iPowR2](const SPoint &refPoint)
		{
			if (pow(refPoint.m_iX - iPosX, 2) + pow(refPoint.m_iY - iPosY, 2) < iPowR2)
			{
				m_aClickedBubbles.push_back(pObject);
			}
		}	
	);
}


void CClickVisitor::Visit(CScoreboard*)
{
}


void CClickVisitor::PostVisit(CGameObject*)
{
}

