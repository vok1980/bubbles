
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


/**
 *	Nothing to draw for CScene,
 *	but we have to do glPushMatrix() 
 *	due to PostVisit implementation
 */
void CDrawVisitor::Visit(CScene*)
{
	glPushMatrix();
}


/**
 *	Draw a simple raster text output for scores
 */
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


/**
 *	Draw a bubble 
 */
void CDrawVisitor::Visit(CBubble *pBubble)
{
	glPushMatrix();

	BoardSize_t iPosX;
	BoardSize_t iPosY;
	BoardSize_t iRadius;

	pBubble->GetPosition(iPosX, iPosY, iRadius);
	glTranslatef(iPosX, iPosY, 0);

	GLfloat theta;
	GLfloat pi     = (GLfloat)acos(-1.0);
	GLfloat radius = iRadius; 
	GLfloat step   = 8.0f; ///< 8 is enough to look like a circle

	SColor color;
	pBubble->GetColor(color);

	// drawing a circle in triangles
	glBegin(GL_TRIANGLE_FAN);
		
		glColor4ub(color.R, color.G, color.B, color.A);

		for(GLfloat a = 0.0f; a < 360.0f; a += step) 
		{
			theta = 2.0f * pi * a / 180.0f;
			glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
		}

	glEnd();
}


/**
 *	PostVisit should do glPopMatrix() due to 
 *	all Visits implemetations
 */
void CDrawVisitor::PostVisit(CGameObject*)
{
	glPopMatrix();
}