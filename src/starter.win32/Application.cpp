
#include <Windows.h>

#include <time.h> 
#include <string>

#include "Application.h"

#include "Graphics.h"
#include "Game.h"



CApplication::CApplication() : 
//	m_clocksBegin(0),
	m_clocksLast(0)
{
}


CApplication::~CApplication()
{
	ReleaseAll();
}


int CApplication::Initialize(HINSTANCE hInstance, const char * szAppName, const char * szWindowName)
{
	m_hInstance = hInstance;
	m_strAppName = szAppName;

	int iWidthScreen = GetSystemMetrics(SM_CXSCREEN);
	int iHeightScreen = GetSystemMetrics(SM_CYSCREEN);

	// Создаем окно главного приложения
	HWND hWndMain = CreateMainWindow(szWindowName, min(480, iWidthScreen), min(640, iHeightScreen), SW_NORMAL, true);
	
	if(!hWndMain)
		return 1;
	
	// Инициализация
	if ( 0 != Init(hWndMain) )
		return 2;

	return 0;
}


// Создание главного окна приложения.
HWND CApplication::CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight,
	int nCmdShow, bool bIsOpenGL)
{
	WNDCLASS wndclass;
	// регистрируем класс окна
	wndclass.style         = 0;
	wndclass.lpfnWndProc   = (WNDPROC)WndProc;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = m_hInstance;
	wndclass.hIcon         = LoadIcon (m_hInstance, m_strAppName.c_str());
	wndclass.hCursor       = LoadCursor (NULL,IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wndclass.lpszMenuName  = m_strAppName.c_str();
	wndclass.lpszClassName = m_strAppName.c_str();

	if(!RegisterClass(&wndclass))
		return 0;

	DWORD dwStyle = WS_OVERLAPPEDWINDOW;
	if(bIsOpenGL)
		dwStyle |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	// Создаем окно
	HWND hWnd = CreateWindow(m_strAppName.c_str(), pWindowName, dwStyle,
		(GetSystemMetrics(SM_CXSCREEN)-nWidth)/2,
		(GetSystemMetrics(SM_CYSCREEN)-nHeight)/2,
		nWidth, nHeight,
		0, 0, m_hInstance, NULL);

	if (hWnd)
	{
		// делаем окно видимым
		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);
	}

	return hWnd;
}


LRESULT CALLBACK CApplication::WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch( uMsg )
	{
		case WM_LBUTTONDOWN:
			break;

		case WM_SIZE:
			break;

		case WM_DESTROY:
			PostQuitMessage( 0 );
			return 0;
	}

	return CallWindowProc( (WNDPROC)DefWindowProc, hWnd, uMsg, wParam, lParam );
}


// Инициализация
int CApplication::Init(HWND hWndMain)
{
	int iRet = 0;
	m_pGraphics.reset(new CGraphics());
	
	if ( 0 != (iRet = m_pGraphics->Init(hWndMain)) )
		return iRet;

	RECT rect;
	GetWindowRect(hWndMain, &rect);

	m_pGame.reset(new CGame());
	m_pGame->Init(rect.right - rect.left, rect.bottom - rect.top);

	return iRet;
}


int CApplication::Run(void)
{
	MSG msg={0};

	while(msg.message!=WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if(GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
			OnIdle();
	}

	return msg.wParam;
}


double CApplication::GetGameTimePassed(void)
{
	clock_t clocks = clock();

	if (0 == m_clocksLast)
	{
//		m_clocksBegin = clocks;
		m_clocksLast = clocks;
	}

	double dRes = (double)(clocks - m_clocksLast) / CLOCKS_PER_SEC;
	m_clocksLast = clocks;
	
   	return dRes;
}


// Функция, вызывающаяся при пустой очереди сообщений
void CApplication::OnIdle(void)
{	
	double dDeltaTime = GetGameTimePassed();

	m_pGraphics->SwapBuffers();
	m_pGame->OnGameLoopTick(dDeltaTime);
}


void CApplication::ReleaseAll(void)
{
//	m_graphics.ReleaseOpenGL();
}



