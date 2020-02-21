#pragma once

#include "stdafx.h"

class CMainWnd : public SHostWnd
{
public:
	CMainWnd();
	~CMainWnd();

	void OnClose();
	void OnMinimize();
	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);	
	void OnBtnListProjects();
	//bool OnBtnClickTestEventSubscribe(EventArgs *pEvtBase);//����ͨ���¼����ķ�ʽ��Ӧ�ؼ��¼�

	void GetLoginWndHwnd(HWND loginWndHwnd);//��ȡ��½���ڵ�hwnd
	void InitListProjects();

protected:
	//��ť�¼�����ӳ���
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)//�ر�
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)//��С��
		EVENT_NAME_COMMAND(L"list_projects", OnBtnListProjects)
		EVENT_MAP_END()

		//������Ϣ����ӳ���
		BEGIN_MSG_MAP_EX(CMainWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)//ע�⽫û�д������Ϣ�������ദ��
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
public:
	BOOL            m_bLayoutInited;
private:
	HWND	m_loginWndHwnd;	//��½����hwnd
};