#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include <time.h>

//定义各数组的最大长度
#define NAME_MAX 20			//姓名最大长度
#define GENDER_MAX 10		//性别最大长度
#define THESIS_MAX 5		//论文最大数量
#define PROJECT_MAX 5		//项目最大数量
#define AWARD_MAX 5			//获奖最大数量
#define MEMBER_MAX 10		//成员最大数量（项目、论文、获奖）
#define TITLE_MAX 50		//标题最大长度
#define PERIODICAL_MAX 50	//期刊最大长度
#define PAGINATION_MAX 10	//页码最大长度
#define ORGANIZATION_MAX 50	//组织最大长度
#define LEVEL_MAX 10		//级别最大长度

//前置声明链表
typedef struct Node Node;

//定义各结构体
//日期结构体
typedef struct Date
{
	int year;	//年
	int month;	//月
	int day;	//日
} Date;
//论文结构体
typedef struct Thesis
{
	char title[TITLE_MAX];				//论文题目
	char author[MEMBER_MAX][NAME_MAX];	//作者（athor[0]为通讯作者，author[1]为第一作者，author[2]为第二作者，以此类推）
	char periodical[PERIODICAL_MAX];	//期刊
	char pagination[PAGINATION_MAX];	//页码/卷期/论文编号
	Date publishDate;					//发表日期
	char grade;							//论文级别（T、A、B、C、D、E）
	float score;						//论文加分
} Thesis;
//项目结构体
typedef struct Project
{
	char title[TITLE_MAX];				//项目名称
	char member[MEMBER_MAX][NAME_MAX];	//成员（member[0]为指导老师，member[1]为成员1，member[2]为成员2，以此类推）
	int id;								//项目编号
	Date startDate;						//开始日期
	Date endDate;						//结束日期
} Project;
//获奖结构体
typedef struct Award
{
	char title[TITLE_MAX];				//获奖名称
	char organization[ORGANIZATION_MAX];//颁奖组织
	char member[MEMBER_MAX][NAME_MAX];	//成员（member[0]为获奖人1，member[1]为获奖人2，以此类推）
	char level[LEVEL_MAX];				//获奖级别
	Date awardDate;						//获奖日期
} Award;
//学生结构体
typedef struct Student
{
	char name[NAME_MAX];			//姓名
	char gender[GENDER_MAX];		//性别
	int thesisNum;					//论文数量
	int projectNum;					//项目数量
	int awardNum;					//获奖数量
	Thesis thesis[THESIS_MAX];		//论文
	Project project[PROJECT_MAX];	//项目
	Award award[AWARD_MAX];			//获奖
} Student;

//定义各函数
//添加学生
Student* AddStudent(Node* pList);
//按名称查询学生（返回位置）
int FindStudent(Node* pList, char* name);
//删除学生
void DeleteStudent(Node* pList, int pos);
//修改学生信息（theses,projects,awards可置NULL）
Student* ModifyStudent(Student* stu, char* name, char* gender, Thesis* theses, Project* projects, Award* awards);
//添加论文、项目、获奖
Student* AddThesis(Student* stu, Thesis thesis);
Student* AddProject(Student* stu, Project project);
Student* AddAward(Student* stu, Award award);
//删除论文、项目、获奖
Student* DeleteThesis(Student* stu, int pos);
Student* DeleteProject(Student* stu, int pos);
Student* DeleteAward(Student* stu, int pos);
//按名称查询论文、项目、获奖（返回位置）
int FindThesis(Student* stu, char* title);
int FindProject(Student* stu, char* title);
int FindAward(Student* stu, char* title);
//修改论文、项目、获奖
Student* ModifyThesis(Student* stu, int pos, Thesis thesis);
Student* ModifyProject(Student* stu, int pos, Project project);
Student* ModifyAward(Student* stu, int pos, Award award);
//按位置返回论文、项目、获奖
Thesis* GetThesis(Student* stu, int pos);
Project* GetProject(Student* stu, int pos);
Award* GetAward(Student* stu, int pos);

//论文结构体
//创建论文
Thesis CreateThesis(char* title, char author[MEMBER_MAX][NAME_MAX], char* periodical, char* pagination, Date publishDate, char grade, float score);
//修改论文具体信息（置NULL不改）
Thesis ModifyThesisDetail(Thesis thesis, char* title, char author[MEMBER_MAX][NAME_MAX], char* periodical, char* pagination, Date publishDate, char grade, float score);
//项目结构体
//创建项目
Project CreateProject(char* title, char member[MEMBER_MAX][NAME_MAX], int id, Date startDate, Date endDate);
//修改项目具体信息（置NULL不改）
Project ModifyProjectDetail(Project project, char* title, char member[MEMBER_MAX][NAME_MAX], int id, Date startDate, Date endDate);
//获奖结构体	
//创建获奖
Award CreateAward(char* title, char organization[ORGANIZATION_MAX], char member[MEMBER_MAX][NAME_MAX], char level[LEVEL_MAX], Date awardDate);
//修改获奖具体信息（置NULL不改）
Award ModifyAwardDetail(Award award, char* title, char organization[ORGANIZATION_MAX], char member[MEMBER_MAX][NAME_MAX], char level[LEVEL_MAX], Date awardDate);
//日期结构体
//创建日期
Date CreateDate(int year, int month, int day);
//修改日期具体信息（置0不改）
Date ModifyDateDetail(Date date, int year, int month, int day);

