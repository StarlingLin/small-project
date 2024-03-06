#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"

//初始化管理系统的窗口
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(ICON), MAKEINTRESOURCE(ICON));
	hiex::Window wnd(width, height);
	wnd.SetTitle(title);
	EnableResizing(wnd.GetHandle(), false);
	return wnd;
}

//绘制初始界面
void _DrawSysMenu(hiex::Window window_main)
{
	
}