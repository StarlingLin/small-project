#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"

//��¼����
void _LoginUI(int width, int height, LPCTSTR title)
{
	//��ʼ����¼����
	hiex::Window window_login = _InitSysWindow(width, height, title);
	//���Ƶ�¼����
	_DrawLoginMenu(window_login, width, height);
	//��ذ�ťȷ�ϵ�¼
	_GetLoginMenu(window_login);
	window_login.CloseWindow();
}
//���Ƶ�¼����
void _DrawLoginMenu(hiex::Window wnd, int width, int height)
{
//�������
	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(25, 0, L"��Բ");
	RECT rect = {0, 0, width, height/3};
	canvas.CenterText(L"��¼", rect);
	wnd.Redraw();
}
//��ذ�ťȷ�ϵ�¼
void _GetLoginMenu(hiex::Window wnd)
{
	//���������
	hiex::SysEdit edit_password;
	edit_password.Create(wnd.GetHandle(), 25, 50, 150, 25, L"����");
	//ȷ�ϵ�¼��ť
	hiex::SysButton btn_login;
	btn_login.Create(wnd.GetHandle(), 25, 80, 150, 50, L"��¼");
	wnd.Redraw();

	//��ذ�ť
	while (wnd.IsAlive())
	{
		if (btn_login.IsClicked())
		{
			//wchar_t*תuint8_t*
			unsigned char password[33] = { 0 };
			wcstombs((char*)password, edit_password.GetText().c_str(), 33);
			//MD5����
			unsigned char md5[16] = { 0 };
			MD5_CTX ctx;
			MD5Init(&ctx);
			MD5Update(&ctx, password, strlen((char*)password));
			MD5Final(&ctx, md5);
			unsigned char answer[16] = { 0xe1,0x0a,0xdc,0x39,0x49,0xba,0x59,0xab,0xbe,0x56,0xe0,0x57,0xf2,0x0f,0x88,0x3e };
			//������ȷ���˳�
			if (!memcmp(answer, md5, 16))
			{
				break;
			}
			//�����������ʾ
			else
			{
				MessageBox(wnd.GetHandle(), L"�������", L"����", MB_OK);
			}
		}
		Sleep(50);
	}
}

//��ʼ������ϵͳ�Ĵ���
hiex::Window _InitSysWindow(int width, int height, LPCTSTR title)
{
	hiex::SetCustomIcon(MAKEINTRESOURCE(IDI_ICON1), MAKEINTRESOURCE(IDI_ICON1));
	hiex::Window wnd(width, height);
	wnd.SetTitle(title);
	EnableResizing(wnd.GetHandle(), false);
	return wnd;
}

//���Ƴ�ʼ����
void _DrawSysMenu(hiex::Window window_main, int width, int height)
{
	//�������
	hiex::Canvas canvas;
	window_main.BindCanvas(&canvas);
	canvas.SetTextWeight(1000);
	canvas.SetTextStyle(40, 0, L"��Բ");
	RECT rect = {0, 0, width, height/5};
	canvas.CenterText(L"����ϵͳ", rect);
	window_main.Redraw();
}

//��ذ�ť�ı����״̬
enum State _GetSysMenu(hiex::Window wnd)
{
	//��ť
	hiex::SysButton btn_viewstu;
	btn_viewstu.Create(wnd.GetHandle(), 75, 80, 150, 50, L"�鿴ѧ���б�");
	hiex::SysButton btn_searchstu;
	btn_searchstu.Create(wnd.GetHandle(), 75, 130, 150, 50, L"��ѯѧ����Ϣ");
	hiex::SysButton btn_addstu;
	btn_addstu.Create(wnd.GetHandle(), 75, 180, 150, 50, L"ֱ�����ѧ��");
	hiex::SysButton btn_savequit;
	btn_savequit.Create(wnd.GetHandle(), 75, 230, 150, 50, L"�����˳�ϵͳ");

	//��ذ�ť
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

//���ѧ������
void _AddStudentUI(Node* head)
{
	//��ʼ�����ѧ������
	hiex::Window window_addstu = _InitSysWindow(300, 200, L"ֱ�����ѧ��");
	//�������ѧ������
	_DrawAddStudentMenu(window_addstu, 300, 200);
	//��ذ�ťȷ�����
	_GetAddStudentMenu(window_addstu, head);

	//tobecontinued
	system("pause");
}

//�������ѧ������
void _DrawAddStudentMenu(hiex::Window wnd, int width, int height)
{
	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);
	//�Ϸ�������
	canvas.Line(50, 50, 250, 50);
	canvas.SolidCircle(50, 50, 5, true, BLACK);
	canvas.FillCircle(150, 50, 5, true, BLACK, WHITE);
	canvas.FillCircle(250, 50, 5, true, BLACK, WHITE);
	canvas.SetTextWeight(800);
	canvas.SetTextStyle(15, 0, L"����");
	RECT rect1 = {0, 20, 100, 40};
	RECT rect2 = {100, 20, 200, 40};
	RECT rect3 = {200, 20, 300, 40};
	canvas.CenterText(L"���ѧ��", rect1);
	canvas.CenterText(L"���������Ŀ", rect2);
	canvas.CenterText(L"������", rect3);

	//�·�������Ϸ���ʾ
	RECT rect_name = {50, 70, 100, 90};
	RECT rect_gender = {50, 105, 100, 125};
	canvas.CenterText(L"������", rect_name);
	canvas.CenterText(L"�Ա�", rect_gender);

	wnd.Redraw();
}

//��ذ�ť���ѧ��
Student* _GetAddStudentMenu(hiex::Window wnd, Node* head)
{
	//�����
	hiex::SysEdit edit_name;
	edit_name.Create(wnd.GetHandle(), 100, 70, 155, 20, L"");
	hiex::SysEdit edit_gender;
	edit_gender.Create(wnd.GetHandle(), 100, 105, 155, 20, L"");
	//ȷ����Ӱ�ť
	hiex::SysButton btn_add;
	btn_add.Create(wnd.GetHandle(), 50, 140, 200, 50, L"ȷ�����");
	wnd.Redraw();

	//��ذ�ť
	while (wnd.IsAlive())
	{
		if (btn_add.IsClicked())
		{
			//���ѧ��
			Student* p = AddStudent(head);
			//�������볤��
			if (2 * edit_name.GetText().length() >= NAME_MAX)
			{
				MessageBox(wnd.GetHandle(), L"��������", L"����", MB_OK);
				continue;
			}
			if (2 * edit_gender.GetText().length() >= GENDER_MAX)
			{
				MessageBox(wnd.GetHandle(), L"�Ա����", L"����", MB_OK);
				continue;
			}
			//�޸�ѧ����Ϣ
			char name[NAME_MAX] = { 0 };
			char gender[GENDER_MAX] = { 0 };
			wcstombs(name, edit_name.GetText().c_str(), NAME_MAX);
			wcstombs(gender, edit_gender.GetText().c_str(), GENDER_MAX);
			ModifyStudent(p, name, gender, NULL, NULL, NULL);
			//�˳�
			wnd.CloseWindow();
			return p;
		}
		Sleep(50);
	}
	return NULL;
}