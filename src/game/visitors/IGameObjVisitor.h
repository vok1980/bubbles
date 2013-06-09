
#pragma once


class CGameObject;
class CScene;
class CBubble;


class IGameObjVisitor
{
public:
	virtual void Visit(CScene*) = 0;
	virtual void Visit(CBubble*) = 0;
	virtual void PostVisit(CGameObject*) = 0;
};
