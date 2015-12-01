#include "Game.h"
#include <string.h>
#include <cstring>
#include <Windows.h>
#include <GL/glut.h>
/* Created and designed by

AmirHossein Goudarzi 2010-11804

±è¿øÀç				 2011-11879

*/

int g_argc;
Game game;
void* glutFonts[7] = {
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_8_BY_13,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_10,
	GLUT_BITMAP_HELVETICA_12,
	GLUT_BITMAP_HELVETICA_18
};

void glutPrint(float x, float y, void* font, char* text, float r, float g, float b, float a)
{
	if (!text || !strlen(text)) return;
	bool blending = false;
	glEnable(GL_BLEND);
	glColor4f(r, g, b, a);
	glRasterPos2f(x, y);

	while (*text) {
		glutBitmapCharacter(font, *text);
		text++;
	}
}
void renderScene()
{
	// Clear Color and Depth Buffers
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Set the camera
	gluLookAt(-1.0, 2.0, 23.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

	glDisable(GL_DEPTH_TEST);


	// Setting the text values to print on different stages
	char *text = "Press s to start the GAME";
	char *exittxt = "Press 0 to EXIT";
	char *gameovertxt = "Game Over";
	char *ittook = "It took";
	char *seconds = "Seconds!!";
	std::string text1 = game.getTime();
	

	// Stage 1
	// Game is not started yet, this is just a start screen
	if (!game.starttrigger){ 
		glutPrint(-2.5, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, text, 0.5, 0.3, 0.7, 1.0);
		glutPrint(-0.8, -5.0, GLUT_BITMAP_TIMES_ROMAN_10, exittxt, 1.0, 0.0, 0.0, 1.0);
	}
	else
		{
			// Stage 3
			// Game is finished and you can see the value for time and  game over screen
			if (game.endTrigger()){
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
				glutPrint(-1.0, 2.0, GLUT_BITMAP_TIMES_ROMAN_24, gameovertxt, 0.0, 0.0, 0.0, 1.0);
				glutPrint(-0.5, -3.0, GLUT_BITMAP_9_BY_15, ittook, 0.0, 0.0, 0.0, 1.0);
				glutPrint(0.0, -3.5, GLUT_BITMAP_TIMES_ROMAN_10, game.getTime(), 1.0, 0.0, 0.0, 1.0);
				glutPrint(-0.5, -4.0, GLUT_BITMAP_9_BY_15, seconds, 0.0, 0.0, 0.0, 1.0);
			}
			else{
			// Stage 2
			// Game has started and ball is moving
			// Here we are seting the shading and trigerring the draw function
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				game.draw();
			}
		}	
	glutSwapBuffers();
}

void SpeciealKey(int key, int x, int y)
{
		switch (key)
		{
		case GLUT_KEY_RIGHT:
			game.control(0.2f, 0.0f, 0.0f);
			break;
		case GLUT_KEY_LEFT:
			game.control(-0.2f, 0.0f, 0.0f);
			break;
		
		default:
			break;
		}
	glutPostRedisplay();
}
void keyboardInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 's': // Using s to start the game
			game.trigger(); // This sets the start trigger to true
			game.init();

			break;
		case '+':
			game.largeStick(); // A little cheat that makes your stick bigger 
			break;
		case '0': // Destoying the windows and exit
			glutDestroyWindow(g_argc); 
			exit(0);
			break;
		default:
			break;
	}
}

void idle()
{
	game.collision();
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 720);
	g_argc = glutCreateWindow("Arkanoid"); // Setting windows id to be able to run exit function
	game.control(0.0f, -5.0f, 0.0f); // Setting the start point of stick
	glutSpecialFunc(SpeciealKey);
	glutKeyboardFunc(keyboardInput);
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);
	glutMainLoop();

}
