
#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>

#include <cassert>
#include <math.h>

#include "game.h"

#include "color.h"




CGame::CGame() : 
	m_iWidth(0),
	m_iHeight(0)
{
}


CGame::~CGame()
{
}


void CGame::Init(int iWidth, int iHeight)
{
	m_iWidth = iWidth; 
	m_iHeight = iHeight;
}


void CGame::OnGameLoopTick(float fDeltaTime)
{
	CalcScene();
	DrawFrame();
}


void DrawCircle(float iPosX, float iPosY, float iPosZ, float iRadius, SColor rgb)
{
	glPushMatrix();
	glTranslatef(iPosX, iPosY, iPosZ);

	GLfloat theta;
	GLfloat pi     = acos(-1.0);
	GLfloat radius = iRadius; // ������
	GLfloat step   = 2.0f; // ��� ������ ��� ��� ���� ����

	// ������ ���� �� ������� ������� GL_CW
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
	//	glColor3ub(0,0,255); // �����
	//	glVertex3f(-0.7f,  0.2f, 0.0f);
	//glEnd();

	assert(m_iHeight > 0);
	assert(m_iWidth > 0);

	glPushMatrix();

	GLfloat szMainMatrix[] = 
		{
			2.0/m_iWidth,		0.0,			0.0,			0.0,
			0.0,				2.0/m_iHeight,	0.0,			0.0,
			0.0,				0.0,			1.0,			0.0,
			-1.0,				-1.0,			0.0,			1.0
		};

	glMultMatrixf(szMainMatrix);

	DrawCircle(300, 200, 0, 100, SColor(255, 0, 20, 200) );
	DrawCircle(480/2, 320, 0, 50, SColor(0, 200, 50, 1));

	glPopMatrix();
}


void CGame::CalcScene(void)
{
}



