#define _CRT_SECURE_NO_WARNINGS

#include "UI.h"
#include "List.h"

#define CH (char*)

//����״̬������visual.h��

int main()
{
	enum State state = MENU;	//����״̬

	//���ݽṹ������
	LoadList(head);

	//test
	char au1[MEMBER_MAX][NAME_MAX] = { "С��","С��","С��","С��","����","����","����" };
	Thesis the1 = { "����һ������" };
	memcpy(the1.author, au1, sizeof(au1));
	strcpy(the1.periodical, "����һ���ڿ�");
	strcpy(the1.pagination, "����ҳ��");
	the1.publishDate = { 2019, 1, 1 };
	the1.grade = 'T';
	the1.score = 0.2f;
	Student* s1 = ModifyStudent(AddStudent(head), CH"����", CH"��", NULL, NULL, NULL);
	AddThesis(s1, the1);

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
