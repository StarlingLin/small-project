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
	printf("��������ϵ������:>");
	scanf("%d", &info.age);
	printf("��������ϵ���Ա�:>");
	scanf("%s", info.gender);
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