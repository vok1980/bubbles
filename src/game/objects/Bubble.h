
#pragma once


#include "GameObject.h"
#include "color.h"



class CBubble : public CGameObject
{
	friend class CDrawVisitor;
	friend class CUpdateVisitor;

public:
	CBubble(CGameObject *pParent, BoardSize_t iPosX, BoardSize_t iPosY, BoardSize_t dRadius, SColor &refColor);

public:
	virtual void AcceptVisitor(IGameObjVisitor*);
	virtual BoardSize_t GetDimention(ObjectDimention);
	bool IsValid(void);

private:
	float GetVelocity(void);

private:
	BoardSize_t m_iPosX;
	BoardSize_t m_iPosY;
	BoardSize_t m_iRadius;
	SColor m_color;
};
