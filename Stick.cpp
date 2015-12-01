#include "Stick.h"
#include <cmath> 
#include <GL/glut.h>
Stick::Stick()
{
	rgb[0] = 0.0;
	rgb[1] = 0.0;
	rgb[2] = 1.0;
	width = 2;
	height = 0.2;
}
void Stick::draw()
{
	
	GLfloat mat_d[] = { rgb[0], rgb[1], rgb[2], 1.0 };
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d);
	glTranslatef(center[0], center[1], center[2]);
	glScalef(width, height , 1);
	glutSolidCube(1);
	glPopMatrix();
}
void Stick::move(float x, float y, float z){
	center[0] += x;
	center[1] += y;
	center[2] += z;
}
void Stick::increasetWidth(){
	width = width + 0.2;
}
float Stick::Width(){
	return width;
}

bool Stick::collision(float x, float y, float z, float r){
	int tick = 0;
	if (x < (center[0] + width*0.6) && x >(center[0] - width*0.6)){
		if ((y - r) <= (center[1] + height) && (y-r) >= (center[1] + height*0.9)){
			tick = 1;
		}
	}
	return tick == 1 ? true : false;
}

