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
	void OnBtnLogin();//登陆，进入主界面

	//添加托盘图标(初始化)
	void AddTrayIcon();

protected:
	//按钮事件处理映射表
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"x_login", OnBtnLogin)
		EVENT_MAP_END()

		//窗口消息处理映射表
		BEGIN_MSG_MAP_EX(CLoginWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)//注意将没有处理的消息交给基类处理
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL            m_bLayoutInited;
	//定义托盘图标对象
	NOTIFYICONDATA m_trayIcon;
	CMainWnd	m_mainWnd;
};