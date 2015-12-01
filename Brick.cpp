#include "Brick.h"
#include <GL/glut.h>

Brick::Brick(int col, int row) :
column(col),
row(row)
{
	width = 1;
	height = 0.5;
}
void Brick::init(){
	move(1.1*column*width - 5, 1.2*row*height - 1, 0.0);
	draw();
}
void Brick::draw()
{
	GLfloat mat_d[] = { rgb[0], rgb[1], rgb[2], 1.0 };
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d);
	glTranslatef(center[0], center[1], center[2]);
	glScalef(width, height, 1);
	glutSolidCube(1);
	glPopMatrix();
}
void Brick::move(float x, float y, float z){
	center[0] = x;
	center[1] = y;
	center[2] = z;
}
void Brick::setColor(float rgb0, float rgb1, float rgb2){
	rgb[0] = rgb0;
	rgb[1] = rgb1;
	rgb[2] = rgb2;
}
float& Brick::operator[](const std::size_t i) { return center[i]; }