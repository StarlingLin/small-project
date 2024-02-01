#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	// ����filename���ڴ洢�ļ�·��
	char* filename = (char*)malloc(1000);
	// ��ע���options_path�����������ȡ·�������������򴴽�·��
	HKEY hKey;	// ע�����
	DWORD dwDisposition;	// ���ڽ��շ���ֵ
	LONG lRet = RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Value\\isaac_options_path", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);	// ����ע�����
	if (lRet == ERROR_SUCCESS)	// �������ɹ�
	{
		DWORD dwType = REG_SZ;	// ���ڽ��շ���ֵ
		DWORD dwSize = 1000;	// ���ڽ��շ���ֵ
		lRet = RegQueryValueEx(hKey, "path", NULL, &dwType, (LPBYTE)filename, &dwSize);	// ��ȡע�����
		if (lRet != ERROR_SUCCESS)	// ����ȡʧ��
		{
			printf("û�в�ѯ��������options.ini����·����\n");
			printf("·���ұ�����ע����У����������ֻ�е�һ��������Ҫ��д��\n");
			printf("�ұ����ע���λ���ǣ�HKEY_CURRENT_USER\\Software\\Value\\isaac_options_path��ֵpath��\n");
			printf("������������options.ini����·����ȥ�ҵ�����ļ��Ҽ�����������ַ����˫����ȥ������");
			scanf("%[^\n]", filename);
			lRet = RegSetValueEx(hKey, "path", 0, REG_SZ, (LPBYTE)filename, strlen(filename) + 1);	// д��ע�����
			if (lRet != ERROR_SUCCESS)	// ��д��ʧ��
			{
				printf("д��ע���ʧ�ܣ�������ô���ˣ������������������\n");
				return 0;
			}
		}
	}
	else	// ������ʧ��
	{
		printf("����ע�����ʧ�ܣ�������ô���ˣ������������������\n");
		return 0;
	}
	RegCloseKey(hKey);	// �ر�ע�����
	// ���ļ�
	FILE* fp = fopen(filename, "r+");
	if (fp == NULL)	// ����ʧ��
	{
		printf("��options.ini�ļ�ʧ�ܣ����ڳ�ʼ�������ע������������һ�����š�\n");
		RegDeleteKey(HKEY_CURRENT_USER, "Software\\Value\\isaac_options_path");	// ���ע�����
		return 0;
	}
	// ��ѯEnableDebugConsole��ֵ
	char* str = (char*)malloc(1000);
	while (fgets(str, 1000, fp) != NULL)	// ���ж�ȡ�ļ�
	{
		if (strstr(str, "EnableDebugConsole"))	// ���ҵ�EnableDebugConsole
		{
			char* p = strchr(str, '=');	// �ҵ��Ⱥ�
			if (p == NULL)	// ��δ�ҵ��Ⱥ�
			{
				printf("δ�ҵ�EnableDebugConsole֮��ĵȺţ����options.ini�ļ��ǲ��������⣿\n");
				return 0;
			}
			p++;	// ָ��Ⱥź�ĵ�һ���ַ�
			if (*p == '0')	// ��Ϊ0
			{
				printf("���ֿ���̨�رա�\n");
				*p = '1';	// ��Ϊ1
				fseek(fp, -(int)strlen(str)-1, SEEK_CUR);	// �ƶ��ļ�ָ�뵽��ǰ�п�ͷ
				fputs(str, fp);	// д���ļ�
				printf("�Ѵ򿪿���̨��\n");
				break;
			}
			else if (*p == '1')	// ��Ϊ1
			{
				printf("���ֿ���̨�򿪡�\n");
				*p = '0';	// ��Ϊ0
				fseek(fp, -(int)strlen(str)-1, SEEK_CUR);	// �ƶ��ļ�ָ�뵽��ǰ�п�ͷ
				fputs(str, fp);	// д���ļ�
				printf("�ѹرտ���̨��\n");
				break;
			}
			else	// ����Ϊ0��1
			{
				printf("δ�ҵ�0��1�����options.ini�ļ��ǲ��������⣿\n");
				return 0;
			}
		}
	}
	fclose(fp);	// �ر��ļ�
	free(filename);	// �ͷ��ڴ�
	free(str);	// �ͷ��ڴ�


	return 0;
}