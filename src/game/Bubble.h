
#pragma once



#include "GameObject.h"



class CBubble : public CGameObject
{
public:
	CBubble(CGameObject *pParent, float dRadius);

public:
	virtual bool Update(double dTimeDelta);
	virtual void Draw(void);
};
