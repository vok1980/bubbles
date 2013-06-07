
#pragma once


class CGame
{
public:
	CGame();
	virtual ~CGame();

public:
	void OnGlContextCreated(void); 
	void OnGameLoopTick(float fDeltaTime);
};

