
#pragma once


class CGameObject;
class CScene;
class CBubble;
class CScoreboard;


/**
 *	Visitor interface for 
 *	visitor pattern
 *	http://www.oodesign.com/visitor-pattern.html
 */
class IGameObjVisitor
{
public:
	virtual void Visit(CScene*) = 0;
	virtual void Visit(CBubble*) = 0;
	virtual void Visit(CScoreboard*) = 0;

	virtual void PostVisit(CGameObject*) = 0;
};
