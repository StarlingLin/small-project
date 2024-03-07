#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"

//��¼����
void _LoginUI(int width, int height, LPCTSTR title)
{
	//��ʼ����¼����
	hiex::Window window_login = _InitSysWindow(width, height, title);
	//���Ƶ�¼����
	_DrawLoginMenu(window_login, width, height);
	//��ذ�ťȷ�ϵ�¼
	_GetLoginMenu(window_login);
	window_login.CloseWindow();
}
//���Ƶ�¼����
void _DrawLoginMenu(hiex::Window wnd, int width, int height)
{
//�������
	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(25, 0, L"��Բ");
	RECT rect = {0, 0, width, height/5};
	canvas.CenterText(L"��¼", rect);
	wnd.Redraw();
}
//��ذ�ťȷ�ϵ�¼
void _GetLoginMenu(hiex::Window wnd)
{
	//���������
	hiex::SysEdit edit_password;
	edit_password.Create(wnd.GetHandle(), 25, 50, 150, 25, L"����");
	//ȷ�ϵ�¼��ť
	hiex::SysButton btn_login;
	btn_login.Create(wnd.GetHandle(), 25, 80, 150, 50, L"��¼");
	wnd.Redraw();

	//��ذ�ť
	while (wnd.IsAlive())
	{
		if (btn_login.IsClicked())
		{
			//������ȷ���˳�ѭ��
			if (wcscmp(edit_password.GetText().c_str(), L"123456") == 0)
			{
				break;
			}
			//�����������ʾ
			else
			{
				MessageBox(wnd.GetHandle(), L"�������", L"����", MB_OK);
			}
		}
		Sleep(50);
	}
}

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
	hiex::Window wnd(width, height);
	wnd.SetTitle(title);
	EnableResizing(wnd.GetHandle(), false);
	return wnd;
}

//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main, int width, int height)
{
	//�������
	hiex::Canvas canvas;
	window_main.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(40, 0, L"��Բ");
	RECT rect = {0, 0, width, height/5};
	canvas.CenterText(L"����ϵͳ", rect);
	window_main.Redraw();
}

//��ذ�ť�ı����״̬
enum State _GetSysMenu(hiex::Window wnd)
{
	//��ť
	hiex::SysButton btn_viewstu;
	btn_viewstu.Create(wnd.GetHandle(), 75, 80, 150, 50, L"�鿴ѧ���б�");
	hiex::SysButton btn_searchstu;
	btn_searchstu.Create(wnd.GetHandle(), 75, 130, 150, 50, L"��ѯѧ����Ϣ");
	hiex::SysButton btn_addstu;
	btn_addstu.Create(wnd.GetHandle(), 75, 180, 150, 50, L"ֱ�����ѧ��");
	hiex::SysButton btn_savequit;
	btn_savequit.Create(wnd.GetHandle(), 75, 230, 150, 50, L"�����˳�ϵͳ");

	//��ذ�ť
	while (wnd.IsAlive())
	{
		if (btn_viewstu.IsClicked())
		{
			return VIEW;
		}
		if (btn_searchstu.IsClicked())
		{
			return SEARCH;
		}
		if (btn_addstu.IsClicked())
		{
			return ADD;
		}
		if (btn_savequit.IsClicked())
		{
			return EXIT;
		}
		Sleep(50);
	}

	return EXIT;
}