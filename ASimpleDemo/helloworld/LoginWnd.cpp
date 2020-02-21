#pragma once

#include "stdafx.h"
#include"LoginWnd.h"
#include"process.h"
#include"CommonDefine.h"
#include"resource1.h"

CLoginWnd::CLoginWnd()
: SHostWnd(_T("LAYOUT:XML_LOGINWND"))//这里定义主界面需要使用的布局文件
{
	m_bLayoutInited = FALSE;
}

CLoginWnd::~CLoginWnd()
{

}

void CLoginWnd::OnClose()
{
	Shell_NotifyIcon(NIM_DELETE, &m_trayIcon);//删除托盘图标
	PostMessage(WM_QUIT);
}

void CLoginWnd::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

BOOL CLoginWnd::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	AddTrayIcon();
	return 0;
}

void CLoginWnd::AddTrayIcon() {
	memset(&m_trayIcon, 0, sizeof(NOTIFYICONDATA));
	m_trayIcon.cbSize = sizeof(NOTIFYICONDATA);
	m_trayIcon.hIcon = ::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	m_trayIcon.hWnd = m_hWnd;
	lstrcpy(m_trayIcon.szTip, _T("战盟"));
	//m_trayIcon.uCallbackMessage = WM_SHOWTASK;
	m_trayIcon.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD, &m_trayIcon);
	//ShowWindow(SW_HIDE);
}

void CLoginWnd::OnBtnLogin()
{
	ShowWindow(SW_HIDE);//隐藏登陆窗口

	m_mainWnd.Create(NULL);
	m_mainWnd.SendMessageW(WM_INITDIALOG);
	m_mainWnd.ShowWindow(SW_SHOWNORMAL);

	m_mainWnd.GetLoginWndHwnd(m_hWnd);
}
