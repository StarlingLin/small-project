#define _CRT_SECURE_NO_WARNINGS

#include "HiEasyX.h"	// HiEasyX
#include "List.h"

#define CH (char*)

int main()
{
	initgraph(800, 600);
	BEGIN_TASK();
	END_TASK();
	REDRAW_WINDOW();
	getmessage(EM_KEY);
	closegraph();
	return EXIT_SUCCESS;
}
