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
	//bool OnBtnClickTestEventSubscribe(EventArgs *pEvtBase);//测试通过事件订阅方式响应控件事件

	void GetLoginWndHwnd(HWND loginWndHwnd);//获取登陆窗口的hwnd
	void InitListProjects();

protected:
	//按钮事件处理映射表
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)//关闭
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)//最小化
		EVENT_NAME_COMMAND(L"list_projects", OnBtnListProjects)
		EVENT_MAP_END()

		//窗口消息处理映射表
		BEGIN_MSG_MAP_EX(CMainWnd)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)//注意将没有处理的消息交给基类处理
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
public:
	BOOL            m_bLayoutInited;
private:
	HWND	m_loginWndHwnd;	//登陆窗口hwnd
};