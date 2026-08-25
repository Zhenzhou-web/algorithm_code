#include "control.h"
#include <algorithm>
#include <cstdio>

void controlsnake::snakeinit() {
	snake.clear();
	snake.push_back({ 100, 100 });
	snake.push_back({ 80, 100 });
	snake.push_back({ 60, 100 });
	score = 0;
	Food::createfood(foodPos);
}

void controlsnake::keepinggaming() {
	int dx = 20, dy = 0;
	int direction = 1;
	bool gameover = false;

	auto onSnake = [this]() {
		for (const auto& s : snake) {
			if (s.x == foodPos.x && s.y == foodPos.y) {
				return true;
			}
		}
		return false;
	};

	BeginBatchDraw();
	while (!gameover) {
		if (GetAsyncKeyState('W') && direction != 2) {
			dx = 0;
			dy = -20;
			direction = 4;
		}
		if (GetAsyncKeyState('S') && direction != 4) {
			dx = 0;
			dy = 20;
			direction = 2;
		}
		if (GetAsyncKeyState('A') && direction != 1) {
			dx = -20;
			dy = 0;
			direction = 3;
		}
		if (GetAsyncKeyState('D') && direction != 3) {
			dx = 20;
			dy = 0;
			direction = 1;
		}

		int m = 0, n = 0;
		if (!snake.empty()) {
			m = snake.back().x;
			n = snake.back().y;
		}

		for (size_t i = snake.size() - 1; i > 0; --i) {
			snake[i] = snake[i - 1];
		}
		snake[0].x += dx;
		snake[0].y += dy;

		bool ate = (snake[0].x == foodPos.x && snake[0].y == foodPos.y);
		if (ate) {
			snake.push_back({ static_cast<std::int16_t>(m), static_cast<std::int16_t>(n) });
			++score;
		}

		if (snake[0].x < 0 || snake[0].x >= 640 ||
			snake[0].y < 20 || snake[0].y >= 500 ||
			Food::judge(snake)) {
			gameover = true;
		}

		if (ate && !gameover) {
			do {
				Food::createfood(foodPos);
			} while (onSnake());
		}

		cleardevice();
		setbkmode(TRANSPARENT);
		settextstyle(20, 0, L"SimSun");
		settextcolor(WHITE);
		wchar_t scoreText[64];
		swprintf_s(scoreText, 64, L"Score: %d", score);
		outtextxy(10, 2, scoreText);

		setfillcolor(GREEN);
		for (const auto& s : snake) {
			fillrectangle(s.x, s.y, s.x + 20, s.y + 20);
		}

		setfillcolor(RED);
		fillrectangle(foodPos.x, foodPos.y, foodPos.x + 20, foodPos.y + 20);
		FlushBatchDraw();

		int sleepTime = 200 - score * 5;
		if (sleepTime < 60) {
			sleepTime = 60;
		}
		Sleep(sleepTime);
	}
	EndBatchDraw();
}
