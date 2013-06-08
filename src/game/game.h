
#pragma once



class CGame
{
public:
	CGame();
	virtual ~CGame();

public:
	void Init(int iWidth, int iHeight); 
	void OnGameLoopTick(float fDeltaTime);

private:
	void CalcScene(void);
	void DrawFrame(void);

private:
	int m_iWidth; 
	int m_iHeight;
};

