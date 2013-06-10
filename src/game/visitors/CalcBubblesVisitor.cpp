
#include "CalcBubblesVisitor.h"



CCalcBubblesVisitor::CCalcBubblesVisitor() :
	m_iCount(0)
{
}


/**
 *	Get objects count
 */
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


/**
 *	Do nothing
 */
void CCalcBubblesVisitor::PostVisit(CGameObject*)
{
}


/**
 *	Do nothing
 */
void CCalcBubblesVisitor::Visit(CScoreboard *pBubble)
{
}

