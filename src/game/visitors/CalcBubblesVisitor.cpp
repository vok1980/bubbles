
#include "CalcBubblesVisitor.h"



CCalcBubblesVisitor::CCalcBubblesVisitor() :
	m_iCount(0)
{
}


int CCalcBubblesVisitor::GetCount(void)
{
	return m_iCount;
}


/**
 *	Do nothing
 */
void CCalcBubblesVisitor::Visit(CScene*)
{
}


/** 
 *	increment bubble count
 */
void CCalcBubblesVisitor::Visit(CBubble*)
{
	++m_iCount;
}


void CCalcBubblesVisitor::PostVisit(CGameObject*)
{
}



