#pragma once

#include "resource.h"
#include "EasyX.h"
#include "HiEasyX.h"

#define ICON 101

//程序状态
enum State
{
	MENU = 1,
	VIEW,
	SEARCH,
	ADD,
	EXIT = 0
};

//初始化管理系统的窗口
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title);
//绘制初始界面
void _DrawSysMenu(hiex::Window window_main, int width, int height);
//监控按钮改变程序状态
enum State _GetSysMenu(hiex::Window wnd);