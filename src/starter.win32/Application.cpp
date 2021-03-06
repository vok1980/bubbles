
#include <Windows.h>

#include <time.h> 
#include <string>

#include "Application.h"

#include "Graphics.h"
#include "Game.h"



CApplication::CApplication() : 
	m_bActive(true)
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

	// ������� ���� �������� ����������
	m_hWndMain = CreateMainWindow(szWindowName, min(480, iWidthScreen), min(640, iHeightScreen), SW_NORMAL, true);
	
	if(!m_hWndMain)
		return 1;
	
	// �������������
	if ( 0 != Init() )
		return 2;

	return 0;
}


// �������� �������� ���� ����������.
HWND CApplication::CreateMainWindow(LPCSTR pWindowName, int nWidth, int nHeight,
	int nCmdShow, bool bIsOpenGL)
{
	WNDCLASS wndclass;
	// ������������ ����� ����
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

	// ������� ����
	HWND hWnd = CreateWindow(m_strAppName.c_str(), pWindowName, dwStyle,
		(GetSystemMetrics(SM_CXSCREEN)-nWidth)/2,
		(GetSystemMetrics(SM_CYSCREEN)-nHeight)/2,
		nWidth, nHeight,
		0, 0, m_hInstance, NULL);

	if (hWnd)
	{
		// ������ ���� �������
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
			{
				POINT pt;
				pt.x = LOWORD(lParam);
				pt.y = HIWORD(lParam);

				CApplication::instance().OnLBMouseClick(pt);
			}
			
			break;

		case WM_SIZING:
			{
				LPRECT lpRect = (LPRECT)lParam;
				
				if ( min(lpRect->bottom - lpRect->top, lpRect->right - lpRect->left) < 240 )
				{
					GetWindowRect(hWnd, lpRect);
				}
			}
			break;

		case WM_SIZE:
			
			switch(wParam)
			{
				case SIZE_RESTORED:
				case SIZE_MAXIMIZED:
					CApplication::instance().SetActive(true);
					break;

				default:
					CApplication::instance().SetActive(false);
					break;
						
			}

			CApplication::instance().OnSize();
			break;

		case WM_DESTROY:
			PostQuitMessage( 0 );
			return 0;
	}

	return CallWindowProc( (WNDPROC)DefWindowProc, hWnd, uMsg, wParam, lParam );
}


// �������������
int CApplication::Init()
{
	int iRet = 0;
	m_pGraphics.reset(new CGraphics());
	
	if ( 0 != (iRet = m_pGraphics->Init(m_hWndMain)) )
		return iRet;

	RECT rect;
	GetClientRect(m_hWndMain, &rect);

	if (!m_pGame.get())
	{
		m_pGame.reset(new CGame());
	}

	m_pGame->Init(rect.right - rect.left, rect.bottom - rect.top);

	return iRet;
}


int CApplication::Run(void)
{
	MSG msg={0};

	while(msg.message!=WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) || !m_bActive)
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


// �������, ������������ ��� ������ ������� ���������
void CApplication::OnIdle(void)
{	
	m_pGraphics->Clear();
	m_pGame->OnGameLoopTick();
	m_pGraphics->SwapBuffers();
}


void CApplication::ReleaseAll(void)
{
//	m_graphics.ReleaseOpenGL();
}


void CApplication::SetActive(bool bActive)
{
	if (!bActive && m_pGame.get())
	{
		m_pGame->OnPause();
	}

	m_bActive = bActive;
}


void CApplication::OnSize(void)
{
	Init();
}


void CApplication::OnLBMouseClick(POINT pt)
{
	if (m_pGame.get())
	{
		SPoint point = {pt.x, pt.y};
		m_pGame->OnMouseClick(point);
	}
}


