
#include "Graphics.h"

#include "platformGL.h"



CGraphics::CGraphics()
{
}


CGraphics::~CGraphics()
{	
	ReleaseOpenGL();
}


int CGraphics::Init(HWND _hWnd)
{
	m_hWnd = _hWnd;
	m_hDC = GetDC(m_hWnd);

	if (!InitPixelFormat(m_hDC))
		return 1;

	m_hRC = wglCreateContext(m_hDC);
	wglMakeCurrent(m_hDC, m_hRC);

	glClearColor( 0, 0, 0, 0 );

	wglUseFontBitmaps(m_hDC, 0, 256, 1000);

	return 0;
}


void CGraphics::Clear(void)
{
	::glClear(GL_COLOR_BUFFER_BIT);
}


void CGraphics::SwapBuffers(void)
{
	::SwapBuffers(m_hDC);
}


void CGraphics::ReleaseOpenGL()
{
	glDeleteLists(1000, 256); 

	if(m_hRC)
	{
		wglMakeCurrent(m_hDC, 0);
		wglDeleteContext(m_hRC);
		m_hRC = 0;
	}
	if(m_hDC)
	{
		ReleaseDC(m_hWnd, m_hDC);
		m_hDC = 0;
	}
}


int CGraphics::InitPixelFormat(HDC hdc)
{
	int pixelformat;
	PIXELFORMATDESCRIPTOR pfd = {0};

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;

	if (!(pixelformat = ChoosePixelFormat(hdc, &pfd)))
	{
		//Error: ChoosePixelFormat failed
		return 0;
	}

	if(!SetPixelFormat(hdc, pixelformat, &pfd))
	{
		//Error: SetPixelFormat failed"
		return 0;
	}

	return 1;
}