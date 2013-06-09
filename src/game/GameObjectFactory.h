
#pragma once


class CGameObject;
class IBoardSize;


class CGameObjectFactory
{
public:
	CGameObjectFactory();
	virtual ~CGameObjectFactory();

public:
	CGameObject* CreateBubble(CGameObject *pParent);
};