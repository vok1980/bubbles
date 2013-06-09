
#include <stdlib.h>
#include <cassert>
#include <time.h>

#include "GameObjectFactory.h"
#include "Bubble.h"




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
	BoardSize_t iBubbleMinRadius = max (12, iBubbleMaxRadius / 25);
	BoardSize_t iRadius = iBubbleMinRadius + (rand() % (int)(iBubbleMaxRadius - iBubbleMinRadius));

	BoardSize_t iPosX = iRadius + rand() % (int)(pParent->GetDimention(OD_WIDTH) - 2 * iRadius);
	BoardSize_t iPosY = iRadius;

#define MIN_CLR_VAL 0x20
#define MAX_CLR_VAL 0xFF

	SColor color(	MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MIN_CLR_VAL + rand() % (MAX_CLR_VAL - MIN_CLR_VAL),
					MAX_CLR_VAL	);

	return new CBubble(pParent, iPosX, iPosY, iRadius, color);
}