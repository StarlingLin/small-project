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
	printf("���� �Ա� ���� �绰 ��ַ ����\n");
	for (int i = 0; i < pc->size; i++)
	{
		printf("%s %s %d %s %s %s\n",
			pc->arr[i].name,
			pc->arr[i].gender,
			pc->arr[i].age,
			pc->arr[i].tele,
			pc->arr[i].addr,
			pc->arr[i].mail
		);
	}
	printf("*******************************\n");
	printf("*******************************\n");
	printf("��ӡ��ɣ���������Լ���...\n");
	system("pause");
	system("cls");
}