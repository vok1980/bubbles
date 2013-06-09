
#pragma once




class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual bool Update(double dTimeDelta);
	virtual void Draw(void);
};

