#pragma once

#include "stdafx.h"
#include"LoginWnd.h"
#include"process.h"
#include"CommonDefine.h"
#include"resource1.h"

CLoginWnd::CLoginWnd()
: SHostWnd(_T("LAYOUT:XML_LOGINWND"))//���ﶨ����������Ҫʹ�õĲ����ļ�
{
	m_bLayoutInited = FALSE;
}

CLoginWnd::~CLoginWnd()
{

}

void CLoginWnd::OnClose()
{
	Shell_NotifyIcon(NIM_DELETE, &m_trayIcon);//ɾ������ͼ��
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
	lstrcpy(m_trayIcon.szTip, _T("ս��"));
	//m_trayIcon.uCallbackMessage = WM_SHOWTASK;
	m_trayIcon.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD, &m_trayIcon);
	//ShowWindow(SW_HIDE);
}

void CLoginWnd::OnBtnLogin()
{
	ShowWindow(SW_HIDE);//���ص�½����

	m_mainWnd.Create(NULL);
	m_mainWnd.SendMessageW(WM_INITDIALOG);
	m_mainWnd.ShowWindow(SW_SHOWNORMAL);

	m_mainWnd.GetLoginWndHwnd(m_hWnd);
}
