#pragma once

#include "EasyX.h"
#include "HiEasyX.h"
#include "resource1.h"

//����״̬
enum State
{
	MENU = 1,
	VIEW,
	SEARCH,
	ADD,
	EXIT = 0
};

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title);
//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main, int width, int height);
//��ذ�ť�ı����״̬
enum State _GetSysMenu(hiex::Window wnd);