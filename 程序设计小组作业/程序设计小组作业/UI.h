#pragma once

#include "EasyX.h"
#include "HiEasyX.h"
#include "resource1.h"
#include "md5.h"
#include "List.h"

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

//添加学生界面
void _AddStudentUI(Node* head);
//绘制添加学生界面
void _DrawAddStudentMenu(hiex::Window wnd, int width, int height);
//监控按钮添加学生
Student* _GetAddStudentMenu(hiex::Window wnd, Node* head);
//添加项目界面
void _AddTermsUI(Student* stu);
//绘制添加项目界面
void _DrawAddTermsMenu(hiex::Window wnd, int width, int height);
//绘制添加学生表格
void _DrawAddStudentTable(hiex::Window wnd, RECT rect);