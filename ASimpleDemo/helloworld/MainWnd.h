#pragma once

#include "stdafx.h"

class CMainWnd : public SHostWnd
{
public:
	CMainWnd();
	~CMainWnd();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();

	void OnSize(UINT nType, CSize size);

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
protected:
	//��ť�¼�����ӳ���
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_MAP_END()

		//������Ϣ����ӳ���
		BEGIN_MSG_MAP_EX(CMainWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)//ע�⽫û�д������Ϣ�������ദ��
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL            m_bLayoutInited;
};