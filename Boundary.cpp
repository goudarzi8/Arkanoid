#include "Boundary.h"
#include <math.h>
#include <GL/glut.h>
Boundary::Boundary(){
	
		for (int row = 0; row < 10; ++row){
			for (int col = 0; col < 10; ++col){
				Bricks.push_back(new Brick(col, row)); // Making the structure of brick liskt
			}
	}	
	// Setting the boundary
	height = 6; 
	width = 6; 
	gameEnd = 0; // determines the game end and sets the speed to zero => check game.end()
}
void Boundary::draw(){
	// Initiate drawing bricks
	for (std::list<Brick*>::iterator it = Bricks.begin(); it != Bricks.end(); ++it){
		
		(*it)->setColor(0.5, 0.0, 0.5); // Set the color of brick
		(*it)->init(); // Draw brick in brick.cpp
	}	

	// Draw boundary
	drawBoundary(6.0 , 0.0, 0.1, 2 * height); // Right side boundary
	drawBoundary(-6.0 , 0.0, 0.1, 2 * height); // Left side boundary
	drawBoundary(0, 6.0, 2 * width, 0.1); // Top boundary
}
void Boundary::drawBoundary(float x, float y,float width, float height){
	GLfloat mat_d[] = { 0.5, 0.5, 0.0, 1.0 };
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_d);
	glTranslatef(x, y, 0.0);
	glScalef(width, height, 1);
	glutSolidCube(1);
	glPopMatrix();
}
bool Boundary::destroyBrick(float x, float y, float z, float r){
	int tick = 0; // Checks the collision
	sideTick = false;
	if (Bricks.empty()){
		gameEnd = 1;
		return false;
	}
	else{
		for (std::list<Brick*>::iterator it = Bricks.begin(); it != Bricks.end(); ++it){
			// Checking if the Ball is touching top or bottom of Brick
			if (x < ((**it)[0] + ((*it)->width) ) && x >((**it)[0] - ((*it)->width) )){
				if (( (y + r ) >= (**it)[1] - ((*it)->height)) && ( (y - r) <= (**it)[1] + ((*it)->height))){
					tick = 1;
				}
			}
			// Checking of the Ball is touching left or right side of Brick
			if (y < ((**it)[1] + ((*it)->height)) && y >((**it)[1] - ((*it)->height))){ 
				if (( (x + r) >= (**it)[0] - ((*it)->width)) && ( (x - r) <= (**it)[0] + ((*it)->width))){
					tick = 1;
					sideTick = true; // Setting the value to check the side collision
				}
			}
			if (tick == 1){ 
				Bricks.erase(it);  // if collision happned removes the brick
				break;
			}
		}
		return tick == 1 ? true : false;
	}
}

bool Boundary::sidecollision(float x, float y, float z, float r){ // side collision
	int tick = 0;
	if ((x + r >= width) || (x - r <= -(width))){
		tick = 1;
	}
	return tick == 1 ? true : false;
}
bool Boundary::tbcollision(float x, float y, float z, float r){ // top bottom collision
	int tick = 0;
	if ((y + r >= height)){
		tick = 1;
	}
	else if ((y - r <= -(height)))
	{
		gameEnd = 1;
		tick = 1;
	}
	return tick == 1 ? true : false;
}
bool Boundary::stickCollision(float x, float y, float z, float w){
	int tick = 0;
	if (((x + w) >= (width + 0.9) ) || ((x - w) <= -(width + 0.9))){
		tick = 1;
	}
	return tick == 1 ? true : false;
}
bool Boundary::GameEnd(){
	return gameEnd;
}