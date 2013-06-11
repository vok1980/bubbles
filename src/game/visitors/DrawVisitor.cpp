
#include "DrawVisitor.h"

#include <math.h>
#include <cstdio>
#include <string>

#include "platformGL.h"
#include "Bubble.h"
#include "Scoreboard.h"

#include "platformGL.h"




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
	sprintf(szOutText, "%u", pBubble->GetScore());
	std::string strText(szOutText);
	
#ifndef ANDROID
	glColor4f(1, 1, 1, 1);
	glRasterPos2i(10, 10); 
	glListBase(1000);
	
	glCallLists(strText.size(), GL_UNSIGNED_BYTE, strText.c_str());
#endif	
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
	
	SColor color;
	pBubble->GetColor(color);

#define step   8.0f ///< 8 is enough to look like a circle
#define iPointsCount  (int)(360.0f / step)
#define iVertValCount  ((iPointsCount + 1) * 3)
#define iIndValCount   (iPointsCount * 3)
	
	static GLfloat pVerts[iVertValCount];
	static GLushort pInd[iIndValCount];

	memset(pVerts, 0, sizeof(GLfloat) * iVertValCount);
	memset(pInd, 0, sizeof(GLushort) * iIndValCount);

	GLfloat *itVert = pVerts + 3;

	for(GLfloat a = 0.0f; a < 360.0f; a += step, itVert += 3) 
	{
		theta = 2.0f * pi * a / 360.0f;
		
		*(itVert + 0) = radius * cos(theta);
		*(itVert + 1) = radius * sin(theta);
	}

	for ( int lc = 0; lc < iPointsCount; ++lc )
	{
//		*( pInd + 0 + lc * 3 ) = 0;
		*( pInd + 1 + lc * 3 ) = lc + 1;
		*( pInd + 2 + lc * 3 ) = lc + 2;
	}

	*( pInd + iIndValCount - 1 ) = 1;

	glColor4ub(color.R, color.G, color.B, color.A);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pVerts);

	glDrawElements(GL_TRIANGLES, iIndValCount, GL_UNSIGNED_SHORT, pInd);

}


/**
 *	PostVisit should do glPopMatrix() due to 
 *	all Visits implemetations
 */
void CDrawVisitor::PostVisit(CGameObject*)
{
	glPopMatrix();
}