#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual void draw()= 0;
	//virtual void move(float x, float y, float z) = 0;
	float rgb[3];
	float center[3];
};
#endif