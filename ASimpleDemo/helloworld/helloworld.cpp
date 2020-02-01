// helloworld.cpp : main source file
//

#include "stdafx.h"
#include "mainwnd.h"
#include <com-loader.hpp>


#ifdef _DEBUG
#define COM_IMGDECODER  _T("imgdecoder-wicd.dll")
#define COM_RENDER_GDI  _T("render-gdid.dll")
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define COM_IMGDECODER  _T("imgdecoder-wic.dll")
#define COM_RENDER_GDI  _T("render-gdi.dll")
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR /*lpstrCmdLine*/, int /*nCmdShow*/)
{
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));

	int nRet = 0;

	SComLoader imgDecLoader;
	SComLoader renderLoader;
	SComLoader transLoader;
	//�����������·���޸ĵ���Ŀ����Ŀ¼���ڵ�Ŀ¼
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
	_tcscpy(lpInsertPos + 1, _T(".."));
	SetCurrentDirectory(szCurrentDir);

	{

		CAutoRefPtr<SOUI::IImgDecoderFactory> pImgDecoderFactory;
		CAutoRefPtr<SOUI::IRenderFactory> pRenderFactory;
		imgDecLoader.CreateInstance(COM_IMGDECODER, (IObjRef**)&pImgDecoderFactory);
		renderLoader.CreateInstance(COM_RENDER_GDI, (IObjRef**)&pRenderFactory);

		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);

		SApplication *theApp = new SApplication(pRenderFactory, hInstance);

		HMODULE hSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
		if (hSysResource)
		{
			CAutoRefPtr<IResProvider> sysSesProvider;
			CreateResProvider(RES_PE, (IObjRef**)&sysSesProvider);
			sysSesProvider->Init((WPARAM)hSysResource, 0);
			theApp->LoadSystemNamedResource(sysSesProvider);
		}


		CAutoRefPtr<IResProvider>   pResProvider;
		CreateResProvider(RES_FILE, (IObjRef**)&pResProvider);
		if (!pResProvider->Init((LPARAM)_T("uires"), 0))
		{
			SASSERT(0);
			return 1;
		}
		theApp->AddResProvider(pResProvider);

		//2.x�汾�Ѿ�����Ҫ�������С�
		//theApp->Init(_T("XML_INIT")); 

		{//������������������д���
			{
				//������������������д���
				CMainWnd wndMain;
				wndMain.Create(GetActiveWindow(), 0, 0, 800, 600);
				wndMain.SendMessage(WM_INITDIALOG);
				wndMain.CenterWindow(wndMain.m_hWnd);
				wndMain.ShowWindow(SW_SHOWNORMAL);
				nRet = theApp->Run(wndMain.m_hWnd);
				//�������
			}
		}

		delete theApp;
	}

	OleUninitialize();
	return nRet;
}