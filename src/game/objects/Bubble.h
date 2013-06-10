
#pragma once


#include "GameObject.h"
#include "color.h"



/** 
 *	Game object that representats a bubble.
 *	Incapsulates data about size, position and color of the bubble.
 */
class CBubble : public CGameObject
{
public:
	CBubble(CGameObject *pParent, BoardSize_t iPosX, BoardSize_t iPosY, BoardSize_t dRadius, SColor &refColor);

public:
	virtual void AcceptVisitor(IGameObjVisitor*);

	virtual BoardSize_t GetDimention(ObjectDimention);
	bool IsValid(void) const;
	void GetPosition(BoardSize_t &refPosX, BoardSize_t &refPosY, BoardSize_t &refRadius) const;
	void GetColor(SColor &refColor) const; 
	long GetPoints(void) const;
	void Move(float fDeltaTime);

private:
	float GetVelocity(void) const;

private:
	BoardSize_t m_iPosX;
	BoardSize_t m_iPosY;
	BoardSize_t m_iRadius;
	SColor m_color;
};
