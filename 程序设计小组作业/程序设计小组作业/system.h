#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include <time.h>

//������������󳤶�
#define NAME_MAX 20			//������󳤶�
#define GENDER_MAX 10		//�Ա���󳤶�
#define THESIS_MAX 10		//�����������
#define PROJECT_MAX 10		//��Ŀ�������
#define AWARD_MAX 10		//���������
#define MEMBER_MAX 10		//��Ա�����������Ŀ�����ġ��񽱣�
#define TITLE_MAX 50		//������󳤶�
#define PERIODICAL_MAX 50	//�ڿ���󳤶�
#define PAGINATION_MAX 10	//ҳ����󳤶�
#define ORGANIZATION_MAX 50	//��֯��󳤶�
#define LEVEL_MAX 10		//������󳤶�

//ǰ����������
typedef struct Node Node;

//������ṹ��
//���ڽṹ��
typedef struct Date
{
	int year;	//��
	int month;	//��
	int day;	//��
} Date;
//���Ľṹ��
typedef struct Thesis
{
	char title[TITLE_MAX];				//������Ŀ
	char author[MEMBER_MAX][NAME_MAX];	//���ߣ�athor[0]ΪͨѶ���ߣ�author[1]Ϊ��һ���ߣ�author[2]Ϊ�ڶ����ߣ��Դ����ƣ�
	char periodical[PERIODICAL_MAX];	//�ڿ�
	char pagination[PAGINATION_MAX];	//ҳ��/����/���ı��
	Date publishDate;					//��������
	char grade;							//���ļ���T��A��B��C��D��E��
	float score;						//���ļӷ�
} Thesis;
//��Ŀ�ṹ��
typedef struct Project
{
	char title[TITLE_MAX];				//��Ŀ����
	char member[MEMBER_MAX][NAME_MAX];	//��Ա��member[0]Ϊָ����ʦ��member[1]Ϊ��Ա1��member[2]Ϊ��Ա2���Դ����ƣ�
	int id;								//��Ŀ���
	Date startDate;						//��ʼ����
	Date endDate;						//��������
} Project;
//�񽱽ṹ��
typedef struct Award
{
	char title[TITLE_MAX];				//������
	char organization[ORGANIZATION_MAX];//�佱��֯
	char member[MEMBER_MAX][NAME_MAX];	//��Ա��member[0]Ϊ����1��member[1]Ϊ����2���Դ����ƣ�
	char level[LEVEL_MAX];				//�񽱼���
	Date awardDate;						//������
} Award;
//ѧ���ṹ��
typedef struct Student
{
	char name[NAME_MAX];			//����
	char gender[GENDER_MAX];		//�Ա�
	Thesis thesis[THESIS_MAX];		//����
	Project project[PROJECT_MAX];	//��Ŀ
	Award award[AWARD_MAX];			//��
} Student;

//���������
//���ѧ��
Student* AddStudent(Node* pList);
//�޸�ѧ����Ϣ��theses,projects,awards����NULL��
Student* ModifyStudent(Student* stu, char* name, char* gender, Thesis* theses, Project* projects, Award* awards);
//������ġ���Ŀ����
void AddThesis(Student* stu, Thesis thesis);
void AddProject(Student* stu, Project project);
void AddAward(Student* stu, Award award);
//ɾ�����ġ���Ŀ����
void DeleteThesis(Student* stu, int pos);
void DeleteProject(Student* stu, int pos);
void DeleteAward(Student* stu, int pos);
//�޸����ġ���Ŀ����
void ModifyThesis(Student* stu);
void ModifyProject(Student* stu);
void ModifyAward(Student* stu);

//��ѯ
