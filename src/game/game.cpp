
#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>

#include <cassert>
#include <math.h>

#include "game.h"
#include "GameObjectFactory.h"
#include "Scene.h"
#include "Scoreboard.h"

#include "color.h"

#include "CalcBubblesVisitor.h"
#include "UpdateVisitor.h"
#include "DrawVisitor.h"
#include "ClickVisitor.h"

#include "consts.h"



CGame::CGame() :
	m_pScoreboard(NULL)
{
	m_pObjectFactory.reset(new CGameObjectFactory());
	m_pMainScene.reset(new CScene(NULL, this));
	m_pScoreboard = new CScoreboard( m_pMainScene.get() );
}


CGame::~CGame()
{
}


/**
 *	Game is initializing with a game field size.
 */
void CGame::Init(long iWidth, long iHeight)
{
	m_aSize[OD_WIDTH] = iWidth;
	m_aSize[OD_HEIGHT] = iHeight;
}


/**
 *	OnGameLoopTick is called in game main loop
 *	Here we calculates the scene and draw it.
 *
 *	@param fDeltaTime	time elapsed from previous OnGameLoopTick call
 */
void CGame::OnGameLoopTick(float fDeltaTime)
{
	CalcScene(fDeltaTime);
	DrawFrame();
}


void CGame::DrawFrame(void)
{
	glPushMatrix();

	///	Set a convenient coordinates for the game.
	///	Zero point is in the left-top corner
	///	width equals to GetDimention(OD_WIDTH)
	///	height equals to GetDimention(OD_HEIGHT)

	GLfloat szMainMatrix[] = 
		{
			2.0/GetDimention(OD_WIDTH),		0.0,							0.0,			0.0,
			0.0,							-2.0/GetDimention(OD_HEIGHT),	0.0,			0.0,
			0.0,							0.0,							1.0,			0.0,
			-1.0,							+1.0,							0.0,			1.0
		};

	glMultMatrixf(szMainMatrix);

	{
		/// Now this visitor will the scene
		CDrawVisitor visDraw;
		m_pMainScene->AcceptVisitor(&visDraw);
	}

	glPopMatrix();
}


/**
 *	Calculates the scene changes for fDeltaTime time period
 */
void CGame::CalcScene(float fDeltaTime)
{
	if ( !m_aClicks.empty() )
	{
		/// transfers mouse clicks to bubbles
		
		CClickVisitor visClick(m_aClicks);
		m_aClicks.clear();
		m_pMainScene->AcceptVisitor(&visClick);
		
		visClick.ChargePoints(m_pScoreboard);
	}

	{		
		///	Calculates the number of actual bubbles on the scene
		
		CCalcBubblesVisitor visCalc;
		m_pMainScene->AcceptVisitor(&visCalc);

		/// If boublle count less than allawed, create more
		
		if (visCalc.GetCount() < GetMaxBoublesCount())
		{
			m_pObjectFactory->CreateBubble(m_pMainScene.get());
		}
	}

	{
		/// Update game objects

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


void CGame::OnMouseClick(const SPoint &point)
{	 
	m_aClicks.push_back(point);
}


long CGame::GetMaxBoublesCount(void)
{
	return MAX_BUBBLES_COUNT_PER_AREA * GetDimention(OD_WIDTH) * GetDimention(OD_HEIGHT);
}

