#include"game.h";
ExMessage m;
void print_game(char game[][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (game[i][j] == '*')
			{
				line(200 * j, 200 * i, 200 * j + 200, 200 * i + 200);
				line(200 * j + 200, 200 * i, 200 * j, 200 * i + 200);
			}
			else if (game[i][j] == 'o')
			{
				circle(200 * j + 100, 200 * i + 100, 100);
			}
		}
	}
}
void init_game(char game[][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			game[i][j] = ' ';
		}
	}
}
void human_in(char game[][3])
{
	int i = -1, j = -1;
Scanf:
	m = getmessage(EM_MOUSE | EM_KEY);
	if (m.message == WM_LBUTTONDOWN)
	{
		i = m.y / 200;
		j = m.x / 200;
	}
	if (game[i][j] != ' ')
	{
		goto Scanf;
	}
	game[i][j] = 'o';
}
void comp_in(char game[][3])
{
	Sleep(200);
	srand(time(NULL));
	int i = 0, j = 0;
re_init:
	i = rand() % 3;
	j = rand() % 3;
	if (game[i][j] != ' ')
	{
		goto re_init;
	}
	game[i][j] = '*';
}
int judge_game(char game[][3])
{
	for (int i = 0; i <= 2; i++)
	{
		if (game[i][0] == game[i][1] &&
			game[i][1] == game[i][2] &&
			game[i][2] != ' ')
		{
			return 0;
		}
	}
	for (int j = 0; j <= 2; j++)
	{
		if (game[0][j] == game[1][j] &&
			game[1][j] == game[2][j] &&
			game[2][j] != ' ')
		{
			return 0;
		}
	}
	if (game[0][0] == game[1][1] &&
		game[1][1] == game[2][2] &&
		game[2][2] != ' ')
	{
		return 0;
	}
	if (game[0][2] == game[1][1] &&
		game[1][1] == game[2][0] &&
		game[2][0] != ' ')
	{
		return 0;
	}
}
void game(void)
{
	char game[3][3] = { 0 };
	init_game(game);
	int i = 0;
	while (1)
	{
		human_in(game);
		print_game(game);
		i++;
		if (judge_game(game) == 0)
		{
			wchar_t s[] = _T("Human win!");
			outtextxy(250, 20, s);
			break;
		}
		if (i == 9)
		{
			wchar_t s[] = _T("Game over!");
			outtextxy(250, 20, s);
			break;
		}
		comp_in(game);
		print_game(game);
		i++;
		if (judge_game(game) == 0)
		{
			wchar_t s[] = _T("Computer win!");
			outtextxy(250, 20, s);
			break;
		}
	}
}