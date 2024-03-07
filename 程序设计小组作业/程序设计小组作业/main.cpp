#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"
#include "List.h"

#define CH (char*)

//����״̬������visual.h��

int main()
{
	enum State state = MENU;	//����״̬

	//��¼����
	_LoginUI(200, 150, L"��¼");	//��¼����

	//���ݽṹ������
	LoadList(head);

	//test
	//char au1[MEMBER_MAX][NAME_MAX] = { "С��","С��","С��","С��","����","����","����" };
	//Student* s1 = ModifyStudent(AddStudent(head), CH"����", CH"��", NULL, NULL, NULL);
	//AddThesis(s1, CreateThesis(CH"����һ������", au1, CH"����һ���ڿ�", CH"����ҳ��", { 2019, 1, 1 }, 'T', 0.2f));
	//AddProject(s1, CreateProject(CH"����һ����Ŀ", au1, 114514, { 2018, 1, 1 }, { 2019, 1, 1 }));
	//Student* s2 = ModifyStudent(AddStudent(head), CH"����", CH"��", NULL, NULL, NULL);
	//AddThesis(s2, CreateThesis(CH"����һ������", au1, CH"����һ���ڿ�", CH"����ҳ��", { 2019, 1, 1 }, 'T', 0.2f));
	//AddProject(s2, CreateProject(CH"����һ����Ŀ", au1, 114514, { 2018, 1, 1 }, { 2019, 1, 1 }));

	//UI
	hiex::Window window_main = _InitSysWindow(300, 300, L"��������Ŀ�ɼ�����ϵͳ");

	while (state)
	{
		switch (state)
		{
		case MENU:
			_DrawSysMenu(window_main, 300, 300);
			state = _GetSysMenu(window_main);
			break;
		case VIEW:
			break;
		case SEARCH:
			break;
		case ADD:
			break;
		}
	}

	//���ݽṹ�ı���
	SaveData(head);
	MessageBox(window_main.GetHandle(), L"����ɹ�", L"��ʾ", MB_OK);

	return EXIT_SUCCESS;
}
