#pragma once
#include <cstdint>
#include <vector>

struct point {
	std::int16_t x;
	std::int16_t y;
};

class Food {
public:
	point pos;

	static void createfood(point& pos);
	static bool judge(const std::vector<point>& snake);
};
