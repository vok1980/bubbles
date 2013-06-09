
#pragma once


#include <memory>
#include <map>
#include "IBoardSize.h"


class CGameObjectFactory;
class CScene;


class CGame : public IDimension
{
public:
	CGame();
	virtual ~CGame();

public:
	void Init(int iWidth, int iHeight); 
	void OnGameLoopTick(float fDeltaTime);

private:
	void CalcScene(float fDeltaTime);
	void DrawFrame(void);

	BoardSize_t GetDimention(ObjectDimention);

private:
	std::map<ObjectDimention, BoardSize_t> m_aSize;
	std::auto_ptr<CGameObjectFactory> m_pObjectFactory;
	std::auto_ptr<CScene> m_pMainScene;
};

