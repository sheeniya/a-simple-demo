#pragma once

#include "stdafx.h"
#include"MainWnd.h"
#include"process.h"
#include"CommonDefine.h"

CMainWnd::CMainWnd()
: SHostWnd(_T("LAYOUT:XML_MAINWND"))//���ﶨ����������Ҫʹ�õĲ����ļ�
{
	m_bLayoutInited = FALSE;
}

CMainWnd::~CMainWnd()
{

}

void CMainWnd::OnClose()
{
	::SendMessage(m_loginWndHwnd, WM_CLOSE, 0, 0);//֪ͨ��½�����˳�(Ϊ���ܹ�ɾ������ͼ��)
	PostMessage(WM_QUIT);
	//ShowWindow(SW_HIDE);//���ش���
}

void CMainWnd::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

BOOL CMainWnd::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	InitListProjects();
	//ͨ���¼����ķ�ʽ��Ӧ�ؼ��¼�
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
		pList->InsertItem(0, L"���ںϲ������");
		pList->InsertItem(1, L"�¼�����");
		pList->InsertItem(2, L"��ҷ����");
		pList->InsertItem(3, L"����");
	}
	pList->SetSelectedItem(0);
}

//bool CMainWnd::OnBtnClickTestEventSubscribe(EventArgs *pEvtBase)//����ͨ���¼����ķ�ʽ��Ӧ�ؼ��¼�
//{
//	MessageBox(NULL, L"�¼�����", L"����", 0);
//	return true;
//}


