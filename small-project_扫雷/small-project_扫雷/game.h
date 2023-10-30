#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

//扫雷行数与列数，至多为两位数
#define ROW 9
#define COL 9

//数组实际大小（考虑边际）
#define IROW ROW + 2
#define ICOL COL + 2

//雷的数量（不能太多会出bug，应使雷数比总格数至少少九个）
#define MINES 10

void menu();
void InitBoard(char arr[IROW][ICOL], int, int, char);
void DisplayBoard(char arr[IROW][ICOL], int, int);
void SetMine(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
int GetMine(char arr[IROW][ICOL], int, int);
void FineMine(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
void ShowArea(char arr1[IROW][ICOL], char arr2[IROW][ICOL], char arr3[IROW][ICOL]);
int Detected(char arr[IROW][ICOL]);
