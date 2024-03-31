//����ʵ��ͨѶ¼

#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR
};

static void ContactMenu()
{
	printf("*******************************\n");
	printf("**********ͨѶ¼����***********\n");
	printf("*******************************\n");
	printf("****  1. ���     2. ɾ��  ****\n");
	printf("****  3. ����     4. �޸�  ****\n");
	printf("****  5. ��ʾ     6. ���  ****\n");
	printf("****  0. ���沢�˳�        ****\n");
	printf("*******************************\n");
	printf("*******************************\n");
}

int main()
{
	int op = EXIT;	//���ڼ�¼�û��Ĳ���
	Contact con;	//����ͨѶ¼
	InitContact(&con);	//��ʼ��ͨѶ¼
	do {
		ContactMenu();
		printf("��ѡ�����:>");
		scanf("%d", &op);
		system("cls");
		switch (op)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (op);
	DestroyContact(&con);	//����ͨѶ¼
	return EXIT_SUCCESS;
}