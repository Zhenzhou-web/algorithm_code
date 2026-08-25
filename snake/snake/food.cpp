#include "stuct.h"
#include <cstdlib>

void Food::createfood(point& pos) {
	pos.x = (rand() % 32) * 20;
	pos.y = 20 + (rand() % 24) * 20;
}

bool Food::judge(const std::vector<point>& snake) {
	for (size_t i = 1; i < snake.size(); ++i) {
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			return true;
		}
	}
	return false;
}
