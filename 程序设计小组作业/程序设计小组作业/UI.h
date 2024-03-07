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

//��¼����
void _LoginUI(int width, int height, LPCTSTR title);
//���Ƶ�¼����
void _DrawLoginMenu(hiex::Window wnd, int width, int height);
//��ذ�ťȷ�ϵ�¼
void _GetLoginMenu(hiex::Window wnd);

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title);
//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main, int width, int height);
//��ذ�ť�ı����״̬
enum State _GetSysMenu(hiex::Window wnd);