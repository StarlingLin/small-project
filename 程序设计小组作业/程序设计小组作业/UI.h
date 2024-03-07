#pragma once

#include "EasyX.h"
#include "HiEasyX.h"
#include "resource1.h"

//程序状态
enum State
{
	MENU = 1,
	VIEW,
	SEARCH,
	ADD,
	EXIT = 0
};

//登录界面
void _LoginUI(int width, int height, LPCTSTR title);
//绘制登录界面
void _DrawLoginMenu(hiex::Window wnd, int width, int height);
//监控按钮确认登录
void _GetLoginMenu(hiex::Window wnd);

//初始化管理系统的窗口
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title);
//绘制初始界面
void _DrawSysMenu(hiex::Window window_main, int width, int height);
//监控按钮改变程序状态
enum State _GetSysMenu(hiex::Window wnd);