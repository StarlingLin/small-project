#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

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

void ContactMenu()
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
	int op = 0;	//���ڼ�¼�û��Ĳ���
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
			//SearchContact();
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			//ClearContact();
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

//int main()	//����ͨѶ¼
//{
//	Contact con;
//	InitContact(&con);
//	AddContact(&con);
//	AddContact(&con);
//
//
//
//
//
//	DestroyContact(&con);
//	return EXIT_SUCCESS;
//}