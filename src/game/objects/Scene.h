
#pragma once


#include "GameObject.h"


class CScene : public CGameObject
{
public:
	CScene(CGameObject *pParent, IDimension *pDimention);
	virtual ~CScene();

public:
	virtual void AcceptVisitor(IGameObjVisitor*);
	virtual BoardSize_t GetDimention(ObjectDimention);

private:
	IDimension *m_pDimention;
};

