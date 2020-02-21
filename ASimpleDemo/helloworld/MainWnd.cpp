#pragma once

#include "stdafx.h"
#include"MainWnd.h"
#include"process.h"
#include"CommonDefine.h"

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
	::SendMessage(m_loginWndHwnd, WM_CLOSE, 0, 0);//通知登陆窗口退出(为了能够删除托盘图标)
	PostMessage(WM_QUIT);
	//ShowWindow(SW_HIDE);//隐藏窗口
}

void CMainWnd::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

BOOL CMainWnd::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	InitListProjects();
	//通过事件订阅方式响应控件事件
	//SButton *pBtn = FindChildByName2<SButton>(L"test_event_subscribe");
	//pBtn->GetEventSet()->subscribeEvent(EVT_LBUTTONDOWN, Subscriber(&CMainWnd::OnBtnClickTestEventSubscribe, this));
	
	return 0;
}

void CMainWnd::GetLoginWndHwnd(HWND loginWndHwnd)
{
	m_loginWndHwnd = loginWndHwnd;
}

void CMainWnd::OnBtnListProjects()
{

}

void CMainWnd::InitListProjects()
{
	SListCtrl *pList = FindChildByName2<SListCtrl>(L"list_projects");
	if (pList)
	{
		pList->InsertItem(0, L"窗口合并与分离");
		pList->InsertItem(1, L"事件订阅");
		pList->InsertItem(2, L"拖曳功能");
		pList->InsertItem(3, L"翻译");
	}
	pList->SetSelectedItem(0);
}

//bool CMainWnd::OnBtnClickTestEventSubscribe(EventArgs *pEvtBase)//测试通过事件订阅方式响应控件事件
//{
//	MessageBox(NULL, L"事件订阅", L"标题", 0);
//	return true;
//}


