#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"

//初始化管理系统的窗口
void InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(ICON), MAKEINTRESOURCE(ICON));
	hiex::Window window_main(width, height);
	window_main.SetTitle(title);
}