
#pragma once

#include "platformGL.h"


struct SColor
{
	SColor() : 		
		R(0), G(0), B(0), A(0)
	{}


	SColor(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a) :		
				R(_r), G(_g), B(_b), A(_a)
	{}

	GLubyte R;
	GLubyte G;
	GLubyte B;	
	GLubyte A;	
};