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
	RECT rect = {0, 0, width, height/3};
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
			//wchar_t*转uint8_t*
			unsigned char password[33] = { 0 };
			wcstombs((char*)password, edit_password.GetText().c_str(), 33);
			//MD5加密
			unsigned char md5[16] = { 0 };
			MD5_CTX ctx;
			MD5Init(&ctx);
			MD5Update(&ctx, password, strlen((char*)password));
			MD5Final(&ctx, md5);
			unsigned char answer[16] = { 0xe1,0x0a,0xdc,0x39,0x49,0xba,0x59,0xab,0xbe,0x56,0xe0,0x57,0xf2,0x0f,0x88,0x3e };
			//密码正确则退出
			if (!memcmp(answer, md5, 16))
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

//添加学生界面
void _AddStudentUI(Node* head)
{
	//初始化添加学生窗口
	hiex::Window window_addstu = _InitSysWindow(300, 200, L"直接添加学生");
	//绘制添加学生界面
	_DrawAddStudentMenu(window_addstu, 300, 200);
	//监控按钮确认添加
	_GetAddStudentMenu(window_addstu, head);

	//tobecontinued
	system("pause");
}

//绘制添加学生界面
void _DrawAddStudentMenu(hiex::Window wnd, int width, int height)
{
	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);
	//上方进度条
	canvas.Line(50, 50, 250, 50);
	canvas.SolidCircle(50, 50, 5, true, BLACK);
	canvas.FillCircle(150, 50, 5, true, BLACK, WHITE);
	canvas.FillCircle(250, 50, 5, true, BLACK, WHITE);
	canvas.SetTextWeight(800);
	canvas.SetTextStyle(15, 0, L"仿宋");
	RECT rect1 = {0, 20, 100, 40};
	RECT rect2 = {100, 20, 200, 40};
	RECT rect3 = {200, 20, 300, 40};
	canvas.CenterText(L"添加学生", rect1);
	canvas.CenterText(L"添加素质项目", rect2);
	canvas.CenterText(L"完成添加", rect3);

	//下方输入框上方提示
	RECT rect_name = {50, 70, 100, 90};
	RECT rect_gender = {50, 105, 100, 125};
	canvas.CenterText(L"姓名：", rect_name);
	canvas.CenterText(L"性别：", rect_gender);

	wnd.Redraw();
}

//监控按钮添加学生
Student* _GetAddStudentMenu(hiex::Window wnd, Node* head)
{
	//输入框
	hiex::SysEdit edit_name;
	edit_name.Create(wnd.GetHandle(), 100, 70, 155, 20, L"");
	hiex::SysEdit edit_gender;
	edit_gender.Create(wnd.GetHandle(), 100, 105, 155, 20, L"");
	//确认添加按钮
	hiex::SysButton btn_add;
	btn_add.Create(wnd.GetHandle(), 50, 140, 200, 50, L"确认添加");
	wnd.Redraw();

	//监控按钮
	while (wnd.IsAlive())
	{
		if (btn_add.IsClicked())
		{
			//添加学生
			Student* p = AddStudent(head);
			//检验输入长度
			if (2 * edit_name.GetText().length() >= NAME_MAX)
			{
				MessageBox(wnd.GetHandle(), L"姓名过长", L"错误", MB_OK);
				continue;
			}
			if (2 * edit_gender.GetText().length() >= GENDER_MAX)
			{
				MessageBox(wnd.GetHandle(), L"性别过长", L"错误", MB_OK);
				continue;
			}
			//修改学生信息
			char name[NAME_MAX] = { 0 };
			char gender[GENDER_MAX] = { 0 };
			wcstombs(name, edit_name.GetText().c_str(), NAME_MAX);
			wcstombs(gender, edit_gender.GetText().c_str(), GENDER_MAX);
			ModifyStudent(p, name, gender, NULL, NULL, NULL);
			//退出
			wnd.CloseWindow();
			return p;
		}
		Sleep(50);
	}
	return NULL;
}