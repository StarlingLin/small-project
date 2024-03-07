#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"

//登录界面
void _LoginUI(int width, int height, LPCTSTR title)
{
	//初始化登录窗口
	hiex::Window window_login = _InitSysWindow(width, height, title);
	//绘制登录界面
	_DrawLoginMenu(window_login, width, height);
	//监控按钮确认登录
	_GetLoginMenu(window_login);
	window_login.CloseWindow();
}
//绘制登录界面
void _DrawLoginMenu(hiex::Window wnd, int width, int height)
{
//界面标题
	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(25, 0, L"幼圆");
	RECT rect = {0, 0, width, height/5};
	canvas.CenterText(L"登录", rect);
	wnd.Redraw();
}
//监控按钮确认登录
void _GetLoginMenu(hiex::Window wnd)
{
	//密码输入框
	hiex::SysEdit edit_password;
	edit_password.Create(wnd.GetHandle(), 25, 50, 150, 25, L"密码");
	//确认登录按钮
	hiex::SysButton btn_login;
	btn_login.Create(wnd.GetHandle(), 25, 80, 150, 50, L"登录");
	wnd.Redraw();

	//监控按钮
	while (wnd.IsAlive())
	{
		if (btn_login.IsClicked())
		{
			//密码正确则退出循环
			if (wcscmp(edit_password.GetText().c_str(), L"123456") == 0)
			{
				break;
			}
			//密码错误则提示
			else
			{
				MessageBox(wnd.GetHandle(), L"密码错误", L"错误", MB_OK);
			}
		}
		Sleep(50);
	}
}

//初始化管理系统的窗口
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
	hiex::Window wnd(width, height);
	wnd.SetTitle(title);
	EnableResizing(wnd.GetHandle(), false);
	return wnd;
}

//绘制初始界面
void _DrawSysMenu(hiex::Window window_main, int width, int height)
{
	//界面标题
	hiex::Canvas canvas;
	window_main.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(40, 0, L"幼圆");
	RECT rect = {0, 0, width, height/5};
	canvas.CenterText(L"管理系统", rect);
	window_main.Redraw();
}

//监控按钮改变程序状态
enum State _GetSysMenu(hiex::Window wnd)
{
	//按钮
	hiex::SysButton btn_viewstu;
	btn_viewstu.Create(wnd.GetHandle(), 75, 80, 150, 50, L"查看学生列表");
	hiex::SysButton btn_searchstu;
	btn_searchstu.Create(wnd.GetHandle(), 75, 130, 150, 50, L"查询学生信息");
	hiex::SysButton btn_addstu;
	btn_addstu.Create(wnd.GetHandle(), 75, 180, 150, 50, L"直接添加学生");
	hiex::SysButton btn_savequit;
	btn_savequit.Create(wnd.GetHandle(), 75, 230, 150, 50, L"保存退出系统");

	//监控按钮
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