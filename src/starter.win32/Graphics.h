
#pragma once

#include <Windows.h>


class CGraphics
{
public:
	CGraphics();
	virtual ~CGraphics();

	int Init(HWND hWnd);	
	void Clear(void);
	void SwapBuffers(void);	

private:
	void ReleaseOpenGL();
	int InitPixelFormat(HDC hdc);

private:
	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_hRC;
};

