#ifndef BRICK_H
#define BRICK_H
#include <iostream>
#include "Shape.h"
class Brick : Shape{
public:
	Brick(int col, int row);
	void draw();
	void move(float x, float y, float z);
	void setColor(float rgb0, float rgb1, float rgb2);
	void init();
	float& Brick::operator[](const std::size_t i);
	friend class Boundary;
private:
	int column;
	int row;
	float width;
	float height;
};
#endif