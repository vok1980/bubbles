
#pragma once


#include "GameObject.h"


typedef unsigned long score_t;


class CScoreboard : public CGameObject
{
public:
	CScoreboard(CGameObject *pParent);
	virtual ~CScoreboard();

public:
	score_t GetScore(void);
	void AddScore(score_t iScore);

	virtual void AcceptVisitor(IGameObjVisitor*);
	virtual BoardSize_t GetDimention(ObjectDimention);

private:
	score_t m_iScoreVal;
};