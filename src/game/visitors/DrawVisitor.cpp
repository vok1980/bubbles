
#include "DrawVisitor.h"

#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>
#include <math.h>


#include "Bubble.h"




CDrawVisitor::CDrawVisitor()
{}


void CDrawVisitor::Visit(CScene*)
{}


void CDrawVisitor::Visit(CBubble *pBubble)
{
	glPushMatrix();
	glTranslatef(pBubble->m_iPosX, pBubble->m_iPosY, 0);

	GLfloat theta;
	GLfloat pi     = acos(-1.0);
	GLfloat radius = pBubble->m_iRadius; // радиус
	GLfloat step   = 2.0f; // чем больше шаг тем хуже диск

	SColor &color = pBubble->m_color;

	// рисуем диск по часовой стрелки GL_CW
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4ub(color.R, color.G, color.B, color.A);

		for(GLfloat a = 0.0f; a < 360.0f; a += step) 
		{
			theta = 2.0f * pi * a / 180.0f;
			glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
		}

	glEnd();
	glPopMatrix();
}


void CDrawVisitor::PostVisit(CGameObject*)
{
}