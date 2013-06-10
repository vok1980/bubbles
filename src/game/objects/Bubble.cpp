
#include <cassert>

#include "Bubble.h"
#include "IGameObjVisitor.h"

#include "consts.h"



CBubble::CBubble(CGameObject *pParent, BoardSize_t iPosX, BoardSize_t iPosY, BoardSize_t dRadius, SColor &refColor) : 
	CGameObject(pParent),
	m_iRadius(dRadius),
	m_iPosX(iPosX),
	m_iPosY(iPosY),
	m_color(refColor),
	m_fVelocity(0.0f)
{

/* 
 *	Calculating bubbles velocity, based on its, size.
 *	The bigger size -- the sloweer bubble.
 */
	m_fVelocity = VELOCITY_PER_1_DIV_RAD_2_KOEFF / (m_iRadius * m_iRadius);
}


/**
 *	Changing object position due to its velocity and elapced time
 */
void CBubble::Move(float fDeltaTime)
{
	m_iPosY += GetVelocity() * fDeltaTime;
}


/**
 *	Calculating points for bursting the bubble, 
 *	based on it's velocity. 
 */
long CBubble::GetPoints(void) const
{
	return (long)(GetVelocity() * POINTS_PER_VELOCITY);
}


/** 
  *	Returns bubble velocity
 */
float CBubble::GetVelocity(void) const
{
	return m_fVelocity;
}


/**
 *	Part of Visitor pattern
 */
void CBubble::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	pVisitor->Visit(this);
	CGameObject::AcceptVisitor(pVisitor);
}


/**
 *	Characteristic dimension of the object
 */
BoardSize_t CBubble::GetDimention(ObjectDimention)
{
	return m_iRadius * 2;
}


/** 
 *	Checks it bubble are still on the scene.
 */
bool CBubble::IsValid(void) const
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


/**
 *	REturns the bubble color
 */
void CBubble::GetColor(SColor &refColor) const 
{
	refColor = m_color;
}


/**
 *	Returns the bubble position & size
 */
void CBubble::GetPosition(BoardSize_t &refPosX, BoardSize_t &refPosY, BoardSize_t &refRadius) const
{
	refPosX = m_iPosX; 
	refPosY = m_iPosY; 
	refRadius = m_iRadius;
}
