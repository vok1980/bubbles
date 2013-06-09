
#pragma once


#include "GameObject.h"



class CBubble : public CGameObject
{
public:
	CBubble(CGameObject *pParent, float dRadius);

public:
	virtual bool Update(double dTimeDelta);
	virtual void Draw(void);
	virtual BoardSize_t GetDimention(ObjectDimention);

private:
	BoardSize_t m_iPosX;
	BoardSize_t m_iPosY;
	BoardSize_t m_iRadius;
};
