
#include "DrawVisitor.h"

#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>
#include <math.h>


#include "Bubble.h"
#include "Scoreboard.h"




CDrawVisitor::CDrawVisitor()
{}


void CDrawVisitor::Visit(CScene*)
{
	glPushMatrix();
}


void CDrawVisitor::Visit(CScoreboard *pBubble)
{
	glPushMatrix();

	BoardSize_t iParentHeight = pBubble->GetParent()->GetDimention(OD_HEIGHT);

	glTranslatef(pBubble->GetDimention(OD_WIDTH)/5, iParentHeight - 2 * pBubble->GetDimention(OD_HEIGHT), 0);

	char szOutText[256];
	sprintf_s(szOutText, "%u", pBubble->GetScore());
	std::string strText(szOutText);
	
	glColor3f(1, 1, 1);
	glRasterPos2i(10, 10); 
	glListBase(1000); 
	
	glCallLists(strText.size(), GL_UNSIGNED_BYTE, strText.c_str()); 
}


void CDrawVisitor::Visit(CBubble *pBubble)
{
	glPushMatrix();
	glTranslatef(pBubble->m_iPosX, pBubble->m_iPosY, 0);

//	wglUseFontBitmaps

	GLfloat theta;
	GLfloat pi     = acos(-1.0);
	GLfloat radius = pBubble->m_iRadius; // ������
	GLfloat step   = 2.0f; // ��� ������ ��� ��� ���� ����

	SColor &color = pBubble->m_color;

	// ������ ���� �� ������� ������� GL_CW
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4ub(color.R, color.G, color.B, color.A);

		for(GLfloat a = 0.0f; a < 360.0f; a += step) 
		{
			theta = 2.0f * pi * a / 180.0f;
			glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
		}

	glEnd();
}


void CDrawVisitor::PostVisit(CGameObject*)
{
	glPopMatrix();
}