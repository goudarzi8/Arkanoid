#ifndef BOUNDARY_H
#define BOUNDARY_H
#include "Brick.h"
#include <list>

class Boundary {
public:
	Boundary();
	void draw();
	void drawBoundary(float x, float y, float width, float height);
	bool destroyBrick(float x, float y, float z, float r);
	bool sidecollision(float x, float y, float z, float r);
	bool tbcollision(float x, float y, float z, float r);
	bool stickCollision(float x, float y, float z,float w);
	bool GameEnd();
	bool sideTick;
private:
	std::list<Brick*> Bricks;
	float width;
	float height;
	bool gameEnd;
};
#endif