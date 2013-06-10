
#include <stdlib.h>
#include <cassert>
#include <time.h>

#include "GameObjectFactory.h"
#include "Bubble.h"

#include "consts.h"




CGameObjectFactory::CGameObjectFactory()
{
	time_t ltime;
	time(&ltime);
	srand(ltime);
}


CGameObjectFactory::~CGameObjectFactory()
{
}


CGameObject* CGameObjectFactory::CreateBubble(CGameObject *pParent)
{
	assert(pParent != NULL);	

	BoardSize_t iBubbleMaxRadius = min (pParent->GetDimention(OD_WIDTH), pParent->GetDimention(OD_HEIGHT)) / 7;
	iBubbleMaxRadius = min (iBubbleMaxRadius, MAX_RADIUS);
	BoardSize_t iBubbleMinRadius = max (MIN_RADIUS, iBubbleMaxRadius / 25);
	BoardSize_t iRadius = iBubbleMinRadius + (rand() % (int)(iBubbleMaxRadius - iBubbleMinRadius));

	BoardSize_t iPosX = iRadius + rand() % (int)(pParent->GetDimention(OD_WIDTH) - 2 * iRadius);
	BoardSize_t iPosY = iRadius;
	
	SColor color(	MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MAX_CLR_VAL	);

	return new CBubble(pParent, iPosX, iPosY, iRadius, color);
}