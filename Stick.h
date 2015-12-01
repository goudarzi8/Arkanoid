#ifndef STICK_H
#define STICK_H
#include "Shape.h"
class Stick :public Shape{
public:
	Stick();
	void draw();
	void move(float x, float y, float z);
	void increasetWidth();
	float Width();
	bool collision(float a, float b, float c, float d);
private:
	float width;
	float height;
};
#endif