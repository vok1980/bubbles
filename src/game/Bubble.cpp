
#include "Bubble.h"



CBubble::CBubble(CGameObject *pParent, float dRadius) : 
	CGameObject(pParent),
	m_iRadius(dRadius),
	m_iPosX(0),
	m_iPosY(0)
{
}


bool CBubble::Update(double dTimeDelta)
{
	
	return true;
}


void CBubble::Draw(void)
{
}


BoardSize_t CBubble::GetDimention(ObjectDimention)
{
	return m_iRadius * 2;
}

