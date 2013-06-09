
#include <stdlib.h>

#include "GameObjectFactory.h"
#include "Bubble.h"




CGameObjectFactory::CGameObjectFactory()
{
}


CGameObjectFactory::~CGameObjectFactory()
{
}


CGameObject* CGameObjectFactory::CreateBubble(CGameObject *pParent)
{
	return new CBubble(pParent, 10);
}