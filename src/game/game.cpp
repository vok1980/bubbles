
#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>

#include <cassert>
#include <math.h>

#include "game.h"
#include "GameObjectFactory.h"
#include "Scene.h"

#include "color.h"

#include "CalcBubblesVisitor.h"
#include "UpdateVisitor.h"
#include "DrawVisitor.h"



#define MAX_BUBBLES_COUNT 15



CGame::CGame() 
{
	m_pObjectFactory.reset(new CGameObjectFactory());
	m_pMainScene.reset(new CScene(NULL, this));
}


CGame::~CGame()
{
}


void CGame::Init(int iWidth, int iHeight)
{
	m_aSize[OD_WIDTH] = iWidth;
	m_aSize[OD_HEIGHT] = iHeight;
}


void CGame::OnGameLoopTick(float fDeltaTime)
{
	CalcScene(fDeltaTime);
	DrawFrame();
}


void CGame::DrawFrame(void)
{
	glPushMatrix();

	GLfloat szMainMatrix[] = 
		{
			2.0/GetDimention(OD_WIDTH),		0.0,							0.0,			0.0,
			0.0,							-2.0/GetDimention(OD_HEIGHT),	0.0,			0.0,
			0.0,							0.0,							1.0,			0.0,
			-1.0,							+1.0,							0.0,			1.0
		};

	glMultMatrixf(szMainMatrix);

	{
		CDrawVisitor visDraw;
		m_pMainScene->AcceptVisitor(&visDraw);
	}

	glPopMatrix();
}


void CGame::CalcScene(float fDeltaTime)
{
	{
		CCalcBubblesVisitor visCalc;
		m_pMainScene->AcceptVisitor(&visCalc);

		if (visCalc.GetCount() < MAX_BUBBLES_COUNT)
		{
			m_pObjectFactory->CreateBubble(m_pMainScene.get());
		}
	}

	{
		CUpdateVisitor visUpdate(fDeltaTime);
		m_pMainScene->AcceptVisitor(&visUpdate);
	}
}


BoardSize_t CGame::GetDimention(ObjectDimention dim)
{
	BoardSize_t &refSize = m_aSize[dim];

	assert(refSize > 0);
	return refSize;
}



