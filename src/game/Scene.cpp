

#include "Scene.h"
#include "IGameObjVisitor.h"



CScene::CScene(CGameObject *pParent, IDimension *pDimention) : 
	CGameObject(pParent),
	m_pDimention(pDimention)
{}


CScene::~CScene()
{}


void CScene::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	pVisitor->Visit(this);
	CGameObject::AcceptVisitor(pVisitor);
}


BoardSize_t CScene::GetDimention(ObjectDimention dim)
{
	return m_pDimention->GetDimention(dim);
}