
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


void DrawCircle(float iPosX, float iPosY, float iPosZ, float iRadius, SColor rgb)
{
	glPushMatrix();
	glTranslatef(iPosX, iPosY, iPosZ);

	GLfloat theta;
	GLfloat pi     = acos(-1.0);
	GLfloat radius = iRadius; // радиус
	GLfloat step   = 2.0f; // чем больше шаг тем хуже диск

	// рисуем диск по часовой стрелки GL_CW
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4ub(rgb.R, rgb.G, rgb.B, rgb.A);

		for(GLfloat a = 0.0f; a < 360.0f; a += step) 
		{
			theta = 2.0f * pi * a / 180.0f;
			glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
		}

	glEnd();
	glPopMatrix();

}


void CGame::DrawFrame(void)
{
	//glBegin(GL_TRIANGLES);
	//	glColor3ub(255,0,0);
	//	glVertex3f(-1.0f, -0.5f, 0.0f);
	//	glVertex3f( 1.0f,  0.5f, 0.0f);
	//	glColor3ub(0,0,255); // синий
	//	glVertex3f(-0.7f,  0.2f, 0.0f);
	//glEnd();

	glPushMatrix();

	GLfloat szMainMatrix[] = 
		{
			2.0/GetDimention(OD_WIDTH),		0.0,							0.0,			0.0,
			0.0,							-2.0/GetDimention(OD_HEIGHT),	0.0,			0.0,
			0.0,							0.0,							1.0,			0.0,
			-1.0,							+1.0,							0.0,			1.0
		};

	glMultMatrixf(szMainMatrix);

	DrawCircle(0, 0, 0, 100, SColor(255, 0, 20, 200) ); 
	DrawCircle(GetDimention(OD_WIDTH)/2, GetDimention(OD_HEIGHT)/2, 0, 50, SColor(0, 200, 50, 1));
	DrawCircle(200, 200, 0, 100, SColor(0, 0, 255, 10) ); 

	glPopMatrix();
}


void CGame::CalcScene(float fDeltaTime)
{
	if (m_pMainScene->GetChildCount() < MAX_BUBBLES_COUNT)
	{
		m_pObjectFactory->CreateBubble(m_pMainScene.get());
	}

	m_pMainScene->Update(fDeltaTime);
}


BoardSize_t CGame::GetDimention(ObjectDimention dim)
{
	BoardSize_t &refSize = m_aSize[dim];

	assert(refSize > 0);
	return refSize;
}



