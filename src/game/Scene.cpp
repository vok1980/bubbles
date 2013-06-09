

#include "Scene.h"



CScene::CScene(CGameObject *pParent, IDimension *pDimention) : 
	CGameObject(pParent),
	m_pDimention(pDimention)
{}


CScene::~CScene()
{}


bool CScene::Update(double dTimeDelta)
{
	ObjectsColl_t::iterator it = m_aObjects.begin();

	while (it != m_aObjects.end())
	{
		if ((*it)->Update(dTimeDelta))
		{
			++it;
		}
		else
		{
			delete *it;
			it = m_aObjects.erase(it);
		}
	}

	return true;
}


void CScene::Draw(void)
{}


BoardSize_t CScene::GetDimention(ObjectDimention dim)
{
	return m_pDimention->GetDimention(dim);
}