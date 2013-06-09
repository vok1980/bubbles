
#include "GameObject.h"





CGameObject::CGameObject(CGameObject *pParent) : 
	m_pParent(NULL)
{
	AtachToParent(pParent);
}


CGameObject::~CGameObject()
{
}


void CGameObject::AddChild(CGameObject *pChild)
{
	m_aObjects.push_back(pChild);
}


void CGameObject::RemoveChild(CGameObject *pChild)
{
	m_aObjects.remove(pChild);
}


int CGameObject::GetChildCount() const
{
	return m_aObjects.size();
}


void CGameObject::AtachToParent(CGameObject *pParent)
{
	m_pParent = pParent;

	if (m_pParent)
		m_pParent->AddChild(this);
}

