#pragma once

#include "stdafx.h"
#include"MainWnd.h"
#include <ShellAPI.h>

class CLoginWnd : public SHostWnd
{
public:
	CLoginWnd();
	~CLoginWnd();

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
	void OnClose();
	void OnMinimize();
	void OnBtnLogin();//��½������������

	//�������ͼ��(��ʼ��)
	void AddTrayIcon();

protected:
	//��ť�¼�����ӳ���
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"x_login", OnBtnLogin)
		EVENT_MAP_END()

		//������Ϣ����ӳ���
		BEGIN_MSG_MAP_EX(CLoginWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)//ע�⽫û�д������Ϣ�������ദ��
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL            m_bLayoutInited;
	//��������ͼ�����
	NOTIFYICONDATA m_trayIcon;
	CMainWnd	m_mainWnd;
};