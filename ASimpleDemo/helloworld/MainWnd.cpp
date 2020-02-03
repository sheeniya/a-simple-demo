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
void CMainWnd::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainWnd::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainWnd::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainWnd::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	if (nType == SIZE_MAXIMIZED)
	{
		FindChildByName(L"btn_restore")->SetVisible(TRUE);
		FindChildByName(L"btn_max")->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		FindChildByName(L"btn_restore")->SetVisible(FALSE);
		FindChildByName(L"btn_max")->SetVisible(TRUE);
	}
}

BOOL CMainWnd::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	return 0;
}
