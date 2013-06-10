
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


/**
 *	Do nothing
 */
void CClickVisitor::Visit(CScene*)
{}


/**
 *	Here we pops the selected bubbles and taking a points from them
 */
void CClickVisitor::ChargePoints(CScoreboard *pScore)
{
	while ( !m_aClickedBubbles.empty() )
	{	
		std::set<CBubble*>::iterator it = m_aClickedBubbles.begin();

		pScore->AddScore((*it)->GetPoints());
		delete *it;
		m_aClickedBubbles.erase(it);
	}
}


/**
 *	Here we selects the bubbles that are clicked
 */
void CClickVisitor::Visit(CBubble *pObject)
{
	BoardSize_t iPosX;
	BoardSize_t iPosY;
	BoardSize_t iRadius;

	pObject->GetPosition(iPosX, iPosY, iRadius);
	const BoardSize_t iPowR2 = pow(iRadius, 2);

	/// Cheking each click point for this bubble
	std::for_each(m_aClicksColl.begin(), m_aClicksColl.end(),
		[this, pObject, iPosX, iPosY, iPowR2](const SPoint &refPoint)
		{
			///	formula for the circumference
			///	(x-a)^2 + (y-b)^2 < R^2 
			///
			if (pow(refPoint.m_iX - iPosX, 2) + pow(refPoint.m_iY - iPosY, 2) < iPowR2)
			{
				/// So, if click is in the circle, put this bubble into clicked collection
				m_aClickedBubbles.insert(pObject);
			}
		}	
	);
}


/**
 *	Do nothing
 */
void CClickVisitor::Visit(CScoreboard*)
{
}


/**
 *	Do nothing
 */
void CClickVisitor::PostVisit(CGameObject*)
{
}

