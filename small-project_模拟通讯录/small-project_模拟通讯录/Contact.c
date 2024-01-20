#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"
#include "SeqList.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	//����
	assert(pc);
	SLInit(pc);
}
//����ͨѶ¼
void DestroyContact(Contact* pc)
{
	//����
	assert(pc);
	SLDestory(pc);
}

//��ɾ�Ĳ鿴��
//��
void AddContact(Contact* pc)
{
	//����
	assert(pc);
	//������ϵ�˽ṹ�����
	Info info;
	printf("���������ϵ��...\n");
	//��ʼ��
	printf("��������ϵ������:>");
	scanf("%s", info.name);
	printf("��������ϵ���Ա�:>");
	scanf("%s", info.gender);
	printf("��������ϵ������:>");
	scanf("%d", &info.age);
	printf("��������ϵ�˵绰:>");
	scanf("%s", info.tele);
	printf("��������ϵ�˵�ַ:>");
	scanf("%s", info.addr);
	printf("��������ϵ������:>");
	scanf("%s", info.mail);

	//���浽ͨѶ¼��
	SLPushBack(pc, info);
	printf("�����ϵ�˳ɹ���\n");
	Sleep(1000);
	system("cls");
}
//ɾ

//��

//��

//��
void ShowContact(Contact* pc)
{
	//����
	assert(pc);
	printf("���ڴ�ӡ��ϵ��...\n");
	Sleep(1000);
	system("cls");
	printf("*******************************\n");
	printf("**********��ϵ����Ϣ***********\n");
	printf("*******************************\n");
	for (int i = 0; i < pc->size; ++i)
	{
		printf("������%s\n", pc->arr[i].name);
		printf("�Ա�%s\n", pc->arr[i].gender);
		printf("���䣺%d\n", pc->arr[i].age);
		printf("�绰��%s\n", pc->arr[i].tele);
		printf("��ַ��%s\n", pc->arr[i].addr);
		printf("���䣺%s\n", pc->arr[i].mail);
		printf("*******************************\n");
	}
	printf("*******************************\n");
	printf("��ӡ��ɡ�\n");
	system("pause");
	system("cls");
}