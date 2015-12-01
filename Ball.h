#ifndef BALL_H
#define BALL_H
#include "Shape.h"
#include <vector>
class Ball :public Shape{
public:
	Ball();
	void draw();
	void move();
	float Radius();
	void collision(float v_x, float v_y);
private:
	float radius;
	float vx,vy; // Speed
};
#endif