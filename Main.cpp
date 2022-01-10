#include<iostream>
#include<vector>
#include<GL/glut.h>


using namespace std;

#include"GameManager.h"

GameManager gameManager;

void displayCallback()
{
	
	gameManager.displayCallback();
	
}

void reshapeCallback(GLsizei x, GLsizei y)
{
	gameManager.reshapeCallback(x,y);
}

void inputCallback(int key, int x, int y)
{
	gameManager.inputCallback(key, x, y);
}

void initialize()
{
	gameManager.initialize();
	
}

void timerCallback(int t)
{
	glutPostRedisplay();
	glutTimerFunc(100, timerCallback, 0);
}

int main(int argc, char** argv)
{
	
	gameManager.run(argc, argv);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(inputCallback);
	glutTimerFunc(100, timerCallback, 0);

	initialize();
	glutMainLoop();
	
	return 0;
}