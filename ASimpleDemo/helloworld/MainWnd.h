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
protected:
	//按钮事件处理映射表
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_MAP_END()

		//窗口消息处理映射表
		BEGIN_MSG_MAP_EX(CMainWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)//注意将没有处理的消息交给基类处理
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL            m_bLayoutInited;
};