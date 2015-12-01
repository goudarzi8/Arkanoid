#include "Ball.h"
#include <math.h>
#include <GL/glut.h>
#include "Boundary.h"
// test
Ball::Ball()
{
	rgb[0] = 1.0;
	rgb[1] = 0.0;
	rgb[2] = 0.0;
	radius = 0.1;
	vx = 0.004;
	vy = 0.002;
	center[0] = 0.0;
	center[1] = -2.5;
	center[2] = 0.0;
}
void Ball::draw()
{
	GLfloat mat_d[] = { rgb[0], rgb[1], rgb[2], 1.0 };
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d);
	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, 30, 30);
	glPopMatrix();
}

void Ball::move(){
	center[0] += vx;
	center[1] += vy;
	center[2] += 0;
}
void Ball::collision(float v_x, float v_y)
{
	vx = v_x * vx;
	vy = v_y * vy;
}
float Ball::Radius(){
	return radius;
}