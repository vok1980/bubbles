
#pragma once


#include <memory>
#include <map>
#include <list>
#include "IBoardSize.h"

#include "point.h"


class CGameObjectFactory;
class CScene;
class CScoreboard;


/**
 *	The main game class
 */
class CGame : public IDimension
{
public:
	CGame();
	virtual ~CGame();

public:
	void Init(long iWidth, long iHeight); 
	void OnGameLoopTick(float fDeltaTime);
	void OnMouseClick(const SPoint &point);

private:
	void CalcScene(float fDeltaTime);
	void DrawFrame(void);

	BoardSize_t GetDimention(ObjectDimention);
	long GetMaxBoubblesCount(bool bRecalc = false);

private:
	std::map<ObjectDimention, BoardSize_t> m_aSize;
	std::auto_ptr<CGameObjectFactory> m_pObjectFactory;
	std::auto_ptr<CScene> m_pMainScene;
	CScoreboard *m_pScoreboard;			///< Should not delete this pointer

	std::list< SPoint > m_aClicks;
};

