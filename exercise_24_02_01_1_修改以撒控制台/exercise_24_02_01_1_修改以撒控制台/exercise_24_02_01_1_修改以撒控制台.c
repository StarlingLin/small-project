#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	// 创建filename用于存储文件路径
	char* filename = (char*)malloc(1000);
	// 打开注册表options_path，若存在则读取路径，若不存在则创建路径
	HKEY hKey;	// 注册表句柄
	DWORD dwDisposition;	// 用于接收返回值
	LONG lRet = RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Value\\isaac_options_path", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);	// 创建注册表项
	if (lRet == ERROR_SUCCESS)	// 若创建成功
	{
		DWORD dwType = REG_SZ;	// 用于接收返回值
		DWORD dwSize = 1000;	// 用于接收返回值
		lRet = RegQueryValueEx(hKey, "path", NULL, &dwType, (LPBYTE)filename, &dwSize);	// 读取注册表项
		if (lRet != ERROR_SUCCESS)	// 若读取失败
		{
			printf("没有查询到以撒的options.ini所在路径捏。\n");
			printf("路径我保存在注册表中，如果不出错只有第一次运行需要填写。\n");
			printf("我保存的注册表位置是：HKEY_CURRENT_USER\\Software\\Value\\isaac_options_path的值path。\n");
			printf("请输入以撒的options.ini所在路径（去找到这个文件右键复制完整地址，把双引号去掉）：");
			scanf("%[^\n]", filename);
			lRet = RegSetValueEx(hKey, "path", 0, REG_SZ, (LPBYTE)filename, strlen(filename) + 1);	// 写入注册表项
			if (lRet != ERROR_SUCCESS)	// 若写入失败
			{
				printf("写入注册表失败，发生肾么事了，建议找我问问情况。\n");
				return 0;
			}
		}
	}
	else	// 若创建失败
	{
		printf("创建注册表项失败，发生肾么事了，建议找我问问情况。\n");
		return 0;
	}
	RegCloseKey(hKey);	// 关闭注册表项
	// 打开文件
	FILE* fp = fopen(filename, "r+");
	if (fp == NULL)	// 若打开失败
	{
		printf("打开options.ini文件失败，现在初始化程序和注册表项，重新运行一下逝逝。\n");
		RegDeleteKey(HKEY_CURRENT_USER, "Software\\Value\\isaac_options_path");	// 清除注册表项
		return 0;
	}
	// 查询EnableDebugConsole的值
	char* str = (char*)malloc(1000);
	while (fgets(str, 1000, fp) != NULL)	// 逐行读取文件
	{
		if (strstr(str, "EnableDebugConsole"))	// 若找到EnableDebugConsole
		{
			char* p = strchr(str, '=');	// 找到等号
			if (p == NULL)	// 若未找到等号
			{
				printf("未找到EnableDebugConsole之后的等号，你的options.ini文件是不是有问题？\n");
				return 0;
			}
			p++;	// 指向等号后的第一个字符
			if (*p == '0')	// 若为0
			{
				printf("发现控制台关闭。\n");
				*p = '1';	// 改为1
				fseek(fp, -(int)strlen(str)-1, SEEK_CUR);	// 移动文件指针到当前行开头
				fputs(str, fp);	// 写入文件
				printf("已打开控制台。\n");
				break;
			}
			else if (*p == '1')	// 若为1
			{
				printf("发现控制台打开。\n");
				*p = '0';	// 改为0
				fseek(fp, -(int)strlen(str)-1, SEEK_CUR);	// 移动文件指针到当前行开头
				fputs(str, fp);	// 写入文件
				printf("已关闭控制台。\n");
				break;
			}
			else	// 若不为0或1
			{
				printf("未找到0或1，你的options.ini文件是不是有问题？\n");
				return 0;
			}
		}
	}
	fclose(fp);	// 关闭文件
	free(filename);	// 释放内存
	free(str);	// 释放内存


	return 0;
}