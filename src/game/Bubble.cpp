
#include <cassert>

#include "Bubble.h"
#include "IGameObjVisitor.h"


#define VELOCITY_KOEFF 300000


CBubble::CBubble(CGameObject *pParent, BoardSize_t iPosX, BoardSize_t iPosY, BoardSize_t dRadius, SColor &refColor) : 
	CGameObject(pParent),
	m_iRadius(dRadius),
	m_iPosX(iPosX),
	m_iPosY(iPosY),
	m_color(refColor)
{
}


float CBubble::GetVelocity(void)
{
	return VELOCITY_KOEFF / (m_iRadius * m_iRadius);
}


void CBubble::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	pVisitor->Visit(this);
	CGameObject::AcceptVisitor(pVisitor);
}


BoardSize_t CBubble::GetDimention(ObjectDimention)
{
	return m_iRadius * 2;
}


bool CBubble::IsValid(void)
{
	assert(NULL != GetParent());

	if ( (GetParent()->GetDimention(OD_WIDTH) < m_iPosX + m_iRadius)
		|| (0 > m_iPosX - m_iRadius)
		|| (GetParent()->GetDimention(OD_HEIGHT) < m_iPosY + m_iRadius)
		|| 0 > m_iPosY - m_iRadius	)
	{
		return false;
	}

	return true;	
}

