#pragma once

#include "resource.h"
#include "EasyX.h"
#include "HiEasyX.h"

#define ICON 101

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title);
//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main, int width, int height);