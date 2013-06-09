

#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>


struct SColor
{
	SColor(GLubyte _R, GLubyte _G, GLubyte _B, GLubyte _A) :
		R(_R),
		G(_G),
		B(_B),
		A(_A)
	{
	}

	GLubyte R;
	GLubyte G;
	GLubyte B;	
	GLubyte A;	
};