#include "Game.h"
#include <iostream>
#include <string>
#include <GL/glut.h>

Game::Game(){}

void Game::init(){
	if (starttrigger){
		start_timer = clock(); // Recording the start time
	}
}
void Game::trigger(){
	starttrigger = 1;
}
void Game:: draw(){
	boundary.draw();
	ball.draw();
	stick.draw();
	Draw = 1;
}
void Game::control(float x, float y, float z){
	// Stick & Wall Collision Detection
	if (!(boundary.stickCollision(stick.center[0] + x, stick.center[1] + y, stick.center[2] + z, stick.Width() ))){ // passing the ball center value
		stick.move(x, y, z);
	}
}
void Game::collision(){
	if (Draw == 1) { //  Checking if Drawing is done
		// Ball & Brick Collision Detection
		if (boundary.destroyBrick(ball.center[0], ball.center[1], ball.center[2], ball.Radius())){ // passing the ball center value
			if (boundary.sideTick){ // Checking if ball is touching the sides or top/bottom
				ball.collision(-1, 1); // Turn -x direction
			}
			else
			ball.collision(1, -1); // Turns to -y direction
		}
		// Ball & Stick Collision Detection
		if (stick.collision(ball.center[0], ball.center[1], ball.center[2], ball.Radius())){ // passing the ball center value
			ball.collision(1, -1); // Turns to -y direction
		}
		// Ball & Side Wall Collision Detection
		if (boundary.sidecollision(ball.center[0], ball.center[1], ball.center[2], ball.Radius())){ // passing the ball center value
			ball.collision(-1, 1); // Turns to -x direction
		}
		// Ball & Side Wall Collision Detection
		if (boundary.tbcollision(ball.center[0], ball.center[1], ball.center[2], ball.Radius())){ // passing the ball center value
			if (boundary.GameEnd()){ // Checking if it touched the ground
				end();
			}
			else if (!boundary.GameEnd())
				ball.collision(1, -1); // Turns to -x direction
		}
		ball.move(); // moves the ball one step
	}
}
void Game::end(){
	
	ball.collision(0,0); // Stop the ball
	ball.center[0] = 0.0; // Set the ball in the middle 
	ball.center[1] = -2.5;
	end_timer = clock(); //  Recording the end time
	_endTrigger = true;
	long vIn = (end_timer - start_timer) / CLOCKS_PER_SEC;
	_itoa_s(vIn, timetxt, sizeof(timetxt), 10); //  Saving the Time elapseed in a char and reding the value from main.cpp
}
void Game::largeStick(){
	stick.increasetWidth();
}
bool Game::endTrigger(){
	if (_endTrigger)
		return true;
	else return false;
}
char* Game::getTime(){
	return timetxt;
}