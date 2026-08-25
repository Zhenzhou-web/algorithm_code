#pragma once
#include "stuct.h"
#include <graphics.h>
#include <windows.h>

class controlsnake {
public:
	std::vector<point> snake;
	point foodPos;
	int score = 0;

	void snakeinit();
	void keepinggaming();
};
