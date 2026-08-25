#include "control.h"
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	srand((unsigned)time(nullptr));
	initgraph(640, 500);

	controlsnake a;
	a.snakeinit();
	a.keepinggaming();

	cleardevice();
	settextstyle(30, 0, L"SimSun");
	outtextxy(250, 200, L"Game Over");

	settextstyle(20, 0, L"SimSun");
	wchar_t scoreText[64];
	swprintf_s(scoreText, 64, L"Score: %d", a.score);
	outtextxy(260, 250, scoreText);

	_getch();
	closegraph();
	return 0;
}
