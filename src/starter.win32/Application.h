
#pragma once

#include <string>
#include <memory>
#include <time.h> 

#include "Singleton.h"
//#include "Graphics.h"

class CGraphics;
class CGame;


class CApplication : public Singleton<CApplication>
{
public:
	CApplication();
	virtual ~CApplication();

public:
	int Initialize(HINSTANCE hInstance, const char * szAppName, const char * szWindowName);
	int Run(void);

private:
	HWND CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight, int nCmdShow, bool bIsOpenGL);
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	int Init(HWND hWndMain);
	void OnIdle(void);
	double GetGameTimePassed(void);
	void ReleaseAll(void);

private:
	HINSTANCE m_hInstance;
	std::string m_strAppName;
	std::auto_ptr<CGraphics> m_pGraphics;
	std::auto_ptr<CGame> m_pGame;

private:
//	clock_t m_clocksBegin;
	clock_t m_clocksLast;
};