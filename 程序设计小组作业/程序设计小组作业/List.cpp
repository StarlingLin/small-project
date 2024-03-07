#define _CRT_SECURE_NO_WARNINGS
//ʵ������ͷ�ļ��Ľӿ�
#include "List.h"

//��ʼ������
void InitList(Node* pList)
{
	//����
	assert(pList != NULL);
	pList->data = NULL;
	pList->next = NULL;
}
//��������
void DestroyList(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList->next;
	Node* q = NULL;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pList->next = NULL;
}

//��ȡ������
int GetLength(Node* pList)
{
	//����
	assert(pList != NULL);
	int n = 0;
	Node* p = pList->next;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//ͷ��/β������
void PushFront(Node* pList, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = pList->next;
	pList->next = pNew;
}
void PushBack(Node* pList, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	pNew->data = data;
	pNew->next = NULL;
	p->next = pNew;
}
//ͷ��/β��ɾ��
void PopFront(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList->next;
	if (p != NULL)
	{
		pList->next = p->next;
		free(p);
	}
}
void PopBack(Node* pList)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = NULL;
	free(q);
}
//����λ�ò���/ɾ��
void Insert(Node* pList, int pos, ListDataType* data)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL)
	{
		Node* pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("�ڴ����ʧ�ܣ�\n");
			exit(EXIT_FAILURE);
		}
		pNew->data = data;
		pNew->next = p->next;
		p->next = pNew;
	}
}
void Erase(Node* pList, int pos)
{
	//����
	assert(pList != NULL);
	Node* p = pList;
	int i = 0;
	while (p != NULL && i < pos)
	{
		p = p->next;
		i++;
	}
	if (p != NULL && p->next != NULL)
	{
		Node* q = p->next;
		p->next = q->next;
		free(q);
	}
}

//����/��������
bool SaveData(Node* pList)
{
	//����
	assert(pList != NULL);
	
	//txt�ļ�����
	FILE* fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		perror("�ļ���ʧ�ܣ�");
		return false;
	}
	Node* p = pList->next;
	while (p != NULL)
	{
		fprintf(fp, "������%s\t�Ա�%s\n", p->data->name, p->data->gender);
		fprintf(fp, "��������%d\t��Ŀ����%d\t������%d\n", 
			p->data->thesisNum,
			p->data->projectNum,
			p->data->awardNum
		);
		fprintf(fp, "------------------------\n");
		for (int i = 0; i < p->data->thesisNum; ++i)
		{
			fprintf(fp, "����%d����%s��\n", i + 1, p->data->thesis[i].title);
			fprintf(fp, "���ߣ�����ͨѶ���ߣ���\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->thesis[i].author[j]);
			}
			fprintf(fp, "�ڿ���%s\nҳ��/����/���ı�ţ�%s\n�������ڣ�%d��%d��%d��\n���ļ���%c\n���ļӷ֣�%.2f\n",
				p->data->thesis[i].periodical, 
				p->data->thesis[i].pagination,
				p->data->thesis[i].publishDate.year, 
				p->data->thesis[i].publishDate.month, 
				p->data->thesis[i].publishDate.day,
				p->data->thesis[i].grade,
				p->data->thesis[i].score
			);
			fprintf(fp, "------------------------\n");
		}
		for (int i = 0; i < p->data->projectNum; ++i)
		{
			fprintf(fp, "��Ŀ%d��%s\n", i+1, p->data->project[i].title);
			fprintf(fp, "��Ա������ָ����ʦ����\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->project[i].member[j]);
			}
			fprintf(fp, "��Ŀ��ţ�%d\n��ʼ���ڣ�%d��%d��%d��\n�������ڣ�%d��%d��%d��\n",
				p->data->project[i].id,
				p->data->project[i].startDate.year,
				p->data->project[i].startDate.month,
				p->data->project[i].startDate.day,
				p->data->project[i].endDate.year,
				p->data->project[i].endDate.month,
				p->data->project[i].endDate.day
			);
			fprintf(fp, "------------------------\n");
		}
		for (int i = 0; i < p->data->awardNum; ++i)
		{
			fprintf(fp, "����%d��%s\n�佱������%s\n", i + 1, 
				p->data->award[i].title, 
				p->data->award->organization
			);
			fprintf(fp, "���ˣ���Ψһ����\n");
			for (int j = 0; j < MEMBER_MAX; ++j)
			{
				fprintf(fp, "%s\n", p->data->award[i].member[j]);
			}
			fprintf(fp, "�񽱼���%s\n�����ڣ�%d��%d��%d��\n",
				p->data->award[i].level,
				p->data->award[i].awardDate.year,
				p->data->award[i].awardDate.month,
				p->data->award[i].awardDate.day
			);
			fprintf(fp, "------------------------\n");
		}
		fprintf(fp, "========================\n");
		p = p->next;
	}
	fclose(fp);

	//�������ļ�����
	fp = fopen("data.bin", "wb");
	if (fp == NULL)
	{
		perror("�ļ���ʧ�ܣ�");
		return false;
	}
	p = pList->next;
	while (p != NULL)
	{
		fwrite(p->data, sizeof(ListDataType), 1, fp);
		p = p->next;
	}
	fclose(fp);

	return true;
}
bool LoadData(Node* pList)
{
	//����
	assert(pList != NULL);

	//txt�ļ�����
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		perror("�ļ���ʧ�ܣ�");
		return false;
	}
	ListDataType* data = (ListDataType*)malloc(sizeof(ListDataType));
	if (data == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	//while (fscanf(fp, "������%s\t�Ա�%s\n", data->name, data->gender) != EOF)
	//{
	//	fscanf(fp, "��������%d\t��Ŀ����%d\t������%d\n",
	//		&data->thesisNum,
	//		&data->projectNum,
	//		&data->awardNum
	//	);
	//	for (int i = 0; i < data->thesisNum; ++i)
	//	{
	//		fscanf(fp, "����%d����%s��\n", i + 1, data->thesis[i].title);
	//		for (int j = 0; j < MEMBER_MAX; ++j)
	//		{
	//			fscanf(fp, "%s\n", data->thesis[i].author[j]);
	//		}
	//		fscanf(fp, "�ڿ���%s\nҳ��/����/���ı�ţ�%s\n�������ڣ�%d��%d��%d��\n���ļ���%c\n���ļӷ֣�%f\n",
	//			data->thesis[i].periodical,
	//			data->thesis[i].pagination,
	//			&data->thesis[i].publishDate.year,
	//			&data->thesis[i].publishDate.month,
	//			&data->thesis[i].publishDate.day,
	//			&data->thesis[i].grade,
	//			&data->thesis[i].score
	//		);
	//	}
	//	for (int i = 0; i < data->projectNum; ++i)
	//	{
	//		fscanf(fp, "��Ŀ%d��%s\n", i + 1, data->project[i].title);
	//		for (int j = 0; j < MEMBER_MAX; ++j)
	//		{
	//			fscanf(fp, "%s\n", data->project[i].member[j]);
	//		}
	//		fscanf(fp, "��Ŀ��ţ�%d\n��ʼ���ڣ�%d��%d��%d��\n�������ڣ�%d��%d��%d��\n",
	//			&data->project[i].id,
	//			&data->project[i].startDate.year,
	//			&data->project[i].startDate.month,
	//			&data->project[i].startDate.day,
	//			&data->project[i].endDate.year,
	//			&data->project[i].endDate.month,
	//			&data->project[i].endDate.day
	//		);
	//	}
	//	for (int i = 0; i < data->awardNum; ++i)
	//	{
	//		fscanf(fp, "����%d��%s\n�佱������%s\n",
	//			i + 1,
	//			data->award[i].title,
	//			data->award->organization
	//		);
	//		for (int j = 0; j < MEMBER_MAX; ++j)
	//		{
	//			fscanf(fp, "%s\n", data->award[i].member[j]);
	//		}
	//		fscanf(fp, "�񽱼���%s\n�����ڣ�%d��%d��%d��\n",
	//			data->award[i].level,
	//			&data->award[i].awardDate.year,
	//			&data->award[i].awardDate.month,
	//			&data->award[i].awardDate.day
	//		);
	//	}
	//	PushBack(pList, data);
	//}
	//fclose(fp);

	//�������ļ�����
	fp = fopen("data.bin", "rb");
	if (fp == NULL)
	{
		perror("�ļ���ʧ�ܣ�");
		return false;
	}
	while (fread(data, sizeof(ListDataType), 1, fp) != 0)
	{
		PushBack(pList, data);
	}
	fclose(fp);

	return true;
}
