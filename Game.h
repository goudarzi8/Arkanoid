#ifndef GMAE_H
#define GMAE_H
#include "Shape.h"
#include "Boundary.h"
#include "Ball.h"
#include "Stick.h"
#include <time.h>

class Game
{
public:
	Game();
	void init();
	void draw();
	void control(float x, float y, float z);
	void collision();
	void end();
	bool endTrigger();
	void trigger();
	void largeStick();
	bool starttrigger = 0;
	char* getTime();
	
private:
	bool _endTrigger = false;
	Ball ball;
	int Draw;
	Boundary boundary;
	Stick stick;
	clock_t start_timer, end_timer;
	char timetxt[3];
};
#endif