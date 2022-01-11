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

void menuCallback(int level)
{

	gameManager.setLevel(level);
	
}

void createMenu()
{
	int submenu_id = glutCreateMenu(menuCallback);
	glutAddMenuEntry("Easy", 1);
	glutAddMenuEntry("Medium", 2);
	glutAddMenuEntry("Hard", 3);
	int menu_id = glutCreateMenu(menuCallback);
	glutAddSubMenu("Select Difficulty", submenu_id);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char** argv)
{
	
	gameManager.run(argc, argv);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(inputCallback);
	glutTimerFunc(100, timerCallback, 0);

	initialize();
	createMenu();
	glutMainLoop();
	
	return 0;
}