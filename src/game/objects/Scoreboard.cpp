
#include "Scoreboard.h"

#include "IGameObjVisitor.h"




CScoreboard::CScoreboard(CGameObject *pParent) : 
	CGameObject(pParent),
	m_iScoreVal(0)
{
}


CScoreboard::~CScoreboard()
{
}


score_t CScoreboard::GetScore(void)
{
	return m_iScoreVal;
}


void CScoreboard::AddScore(score_t iScore)
{
	m_iScoreVal += iScore;
}


void CScoreboard::AcceptVisitor(IGameObjVisitor *pVisitor)
{
	pVisitor->Visit(this);
	CGameObject::AcceptVisitor(pVisitor);
}


BoardSize_t CScoreboard::GetDimention(ObjectDimention)
{
	return 15;
}
