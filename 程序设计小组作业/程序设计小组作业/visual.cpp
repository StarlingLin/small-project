#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(ICON), MAKEINTRESOURCE(ICON));
	hiex::Window wnd(width, height);
	wnd.SetTitle(title);
	EnableResizing(wnd.GetHandle(), false);
	return wnd;
}

//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main)
{
	
}