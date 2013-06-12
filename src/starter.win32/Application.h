
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
	void OnSize(void);
	void SetActive(bool);
	void OnLBMouseClick(POINT pt);
	HWND CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight, int nCmdShow, bool bIsOpenGL);
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	int Init(void);
	void OnIdle(void);
	float GetGameTimePassed(void);
	void ReleaseAll(void);

private:
	HWND m_hWndMain;
	HINSTANCE m_hInstance;
	bool m_bActive;
	std::string m_strAppName;
	std::auto_ptr<CGraphics> m_pGraphics;
	std::auto_ptr<CGame> m_pGame;
};