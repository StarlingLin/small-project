#define _CRT_SECURE_NO_WARNINGS

#include "visual.h"
#include "List.h"

#define CH (char*)

//����״̬������visual.h��

int main()
{
	enum State state = MENU;	//����״̬

	hiex::Window window_main = _InitSysWindow(300, 300, L"��������Ŀ�ɼ�����ϵͳ");

	while (state)
	{
		switch (state)
		{
		case MENU:
			_DrawSysMenu(window_main, 300, 300);
			state = _GetSysMenu(window_main);
			break;
		case VIEW:
			break;
		case SEARCH:
			break;
		case ADD:
			break;
		case EXIT:
			break;
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
