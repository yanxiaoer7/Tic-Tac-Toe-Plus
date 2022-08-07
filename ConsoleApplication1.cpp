#include"game.h"
int main()
{
	initgraph(600, 600);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	game();

	ExMessage m2{};
	m2 = getmessage(EM_MOUSE | EM_KEY);
	_getch();
	closegraph();		
	return 0;
}
