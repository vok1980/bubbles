
#include "GameObject.h"

#include <algorithm>

#include "IGameObjVisitor.h"





CGameObject::CGameObject(CGameObject *pParent) : 
	m_pParent(NULL)
{
	AtachToParent(pParent);
}


CGameObject::~CGameObject()
{
	DetachFromParent();

	std::for_each(m_aObjects.begin(), m_aObjects.end(),
		[](const ObjectsColl_t::value_type &refVal)
		{
			delete refVal;
		}
	);
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


CGameObject* CGameObject::GetParent(void) const
{
	return m_pParent;
}


void CGameObject::AtachToParent(CGameObject *pParent)
{
	m_pParent = pParent;

	if (m_pParent)
		m_pParent->AddChild(this);
}


void CGameObject::DetachFromParent(void)
{
	if (m_pParent)
		m_pParent->RemoveChild(this);
}



void CGameObject::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	std::for_each(m_aObjects.begin(), m_aObjects.end(), 
		[pVisitor](const ObjectsColl_t::value_type &refVal)
		{
			refVal->AcceptVisitor(pVisitor);
		});	

	pVisitor->PostVisit(this);
}

