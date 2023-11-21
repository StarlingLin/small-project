#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

//ɨ������������������Ϊ��λ��
#define ROW 9
#define COL 9

//����ʵ�ʴ�С�����Ǳ߼ʣ�
#define IROW ROW + 2
#define ICOL COL + 2

//�׵�����������̫����bug��Ӧʹ�������ܸ��������پŸ���
#define MINES 10

void menu();
void InitBoard(char arr[IROW][ICOL], int, int, char);
void DisplayBoard(char arr[IROW][ICOL], int, int);
void SetMine(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
int GetMine(char arr[IROW][ICOL], int, int);
void FindMine(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
void ShowArea(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
int Detected(char arr[IROW][ICOL]);
