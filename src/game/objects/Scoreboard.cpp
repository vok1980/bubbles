
#include "Scoreboard.h"




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


