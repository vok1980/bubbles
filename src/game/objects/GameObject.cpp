
#include "GameObject.h"

#include <algorithm>

#include "IGameObjVisitor.h"




/**
 *	On object creation we need to attach to parent object, if any.
 */
CGameObject::CGameObject(CGameObject *pParent) : 
	m_pParent(pParent)
{
	AtachToParent(pParent);
}


/**
 *	On object delete we need to detach it from parent
 *	and delete all the children.
 *
 *	Don't need to remove objects from collection cause of 
 *	child will remove itself from parents collection on delete.
 */
CGameObject::~CGameObject()
{
	DetachFromParent();

	while ( m_aObjects.size() > 0 )
	{
		delete *m_aObjects.begin();
	}
}


/** 
 *	Add child object
 */
void CGameObject::AddChild(CGameObject *pChild)
{
	m_aObjects.push_back(pChild);
}


/**
 *	Remove child object
 */
void CGameObject::RemoveChild(CGameObject *pChild)
{
	m_aObjects.remove(pChild);
}


/**
 *	Get child count :)
 */ 
int CGameObject::GetChildCount() const
{
	return m_aObjects.size();
}


/**
 *	Get child parent :)))
 */ 
CGameObject* CGameObject::GetParent(void) const
{
	return m_pParent;
}


/**
 *	Attach to parent object
 */
void CGameObject::AtachToParent(CGameObject *pParent)
{
	m_pParent = pParent;

	if (m_pParent)
		m_pParent->AddChild(this);
}


/**
 *	Detuch from parent
 */
void CGameObject::DetachFromParent(void)
{
	if (m_pParent)
		m_pParent->RemoveChild(this);
}


/**
 *	Part of Visitor pattern for a game objects tree
 */
void CGameObject::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	std::for_each(m_aObjects.begin(), m_aObjects.end(), 
		[pVisitor](const ObjectsColl_t::value_type &refVal)
		{
			refVal->AcceptVisitor(pVisitor);
		});	

	pVisitor->PostVisit(this);
}

