
#pragma once


class CGameObject;


/**
 *	Factory for the bubbles
 */
class CGameObjectFactory
{
public:
	CGameObjectFactory();
	virtual ~CGameObjectFactory();

public:
	CGameObject* CreateBubble(CGameObject *pParent);
};