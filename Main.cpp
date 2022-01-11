#include<iostream>
#include<vector>
#include<GL/glut.h>

using namespace std;

#include"GameManager.h"



void displayCallback()
{

	GameManager::getInstacne()->displayCallback();

}

void reshapeCallback(GLsizei x, GLsizei y)
{
	GameManager::getInstacne()->reshapeCallback(x, y);
}

void inputCallback(int key, int x, int y)
{
	GameManager::getInstacne()->inputCallback(key, x, y);
}

void initialize()
{
	GameManager::getInstacne()->initialize();

}

void timerCallback(int t)
{
	glutPostRedisplay();
	glutTimerFunc(100, timerCallback, 0);
}

void menuCallback(int level)
{

	GameManager::getInstacne()->setLevel(level);

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

void rules()
{
	cout << "RULES : --->"<<endl;
	cout <<"\t*Main objective is to eat the food" << endl;
	cout << "\t*Use UP(^), DOWN(v), RIGHT(>), and LEFT(<) arrow keys to move your snake." << endl;
	cout << "\t*Try neither to CRASH with the WALLS nor with your BODY." << endl;
	cout << "\t*The more you eat food, your score increases and the bigger you become." << endl;
	cout << "\t*You have to eat 50 preys to win the challenge." << endl;
	cout << "\t*After starting the game, first right click using mouse and select the difficulty." << endl << endl;
	cout << "Press any key to start the game and have fun D:\n\n\n";

	getchar();

}

int main(int argc, char** argv)
{
	rules();
	GameManager::getInstacne()->run(argc, argv);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);
	glutSpecialFunc(inputCallback);
	glutTimerFunc(100, timerCallback, 0);

	initialize();
	createMenu();
	glutMainLoop();

	return 0;
}