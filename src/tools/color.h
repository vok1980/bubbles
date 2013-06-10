
#pragma once

#include "platformGL.h"


struct SColor
{
	SColor() :
		R(0), G(0), B(0), A(0)
	{}


	SColor(GLubyte _R, GLubyte _G, GLubyte _B, GLubyte _A) :
		R(_R), G(_G), B(_B), A(_A)
	{}

	GLubyte R;
	GLubyte G;
	GLubyte B;	
	GLubyte A;	
};