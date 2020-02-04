#pragma once

#include "stdafx.h"
#include"MainWnd.h"

CMainWnd::CMainWnd()
: SHostWnd(_T("LAYOUT:XML_MAINWND"))//这里定义主界面需要使用的布局文件
{
	m_bLayoutInited = FALSE;
}

CMainWnd::~CMainWnd()
{

}

void CMainWnd::OnClose()
{
	PostMessage(WM_QUIT);
}

void CMainWnd::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

BOOL CMainWnd::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	return 0;
}
