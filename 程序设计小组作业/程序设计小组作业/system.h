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
#define THESIS_MAX 10		//论文最大数量
#define PROJECT_MAX 10		//项目最大数量
#define AWARD_MAX 10		//获奖最大数量
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
	Thesis thesis[THESIS_MAX];		//论文
	Project project[PROJECT_MAX];	//项目
	Award award[AWARD_MAX];			//获奖
} Student;

//定义各函数
//添加学生
Student* AddStudent(Node* pList);
//修改学生信息（theses,projects,awards可置NULL）
Student* ModifyStudent(Student* stu, char* name, char* gender, Thesis* theses, Project* projects, Award* awards);
//添加论文、项目、获奖
void AddThesis(Student* stu, Thesis thesis);
void AddProject(Student* stu, Project project);
void AddAward(Student* stu, Award award);
//删除论文、项目、获奖
void DeleteThesis(Student* stu, int pos);
void DeleteProject(Student* stu, int pos);
void DeleteAward(Student* stu, int pos);
//修改论文、项目、获奖
void ModifyThesis(Student* stu);
void ModifyProject(Student* stu);
void ModifyAward(Student* stu);

//查询
