#include<iostream>
#include<vector>
#include<GL/glut.h>

using namespace std;

#include"Point.h"
#include"Color.h"
#include"QuadShape.h"
#include"Food.h"
#include"Snake.h"
#include"IObstacle.h"
#include"Wall.h"
#include"Level.h"
#include"Board.h"


Board gameBoard(600, 600);
Food food(Color(0.5f, 0.6f, 0.7f));

float posX = 300 , posY = 300;

void snakeHead() 
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(posX, posY);
	glVertex2f(posX + 20.0f, posY);
	glVertex2f(posX + 20.0f, posY - 20.0f);
	glVertex2f(posX, posY - 20.0f);
	glEnd();
	glFlush();
}

void my_display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
    snakeHead();
	gameBoard.displayBoundaries();
	glutSwapBuffers();

}

void my_reshape(GLsizei x, GLsizei y)
{
	glutReshapeWindow(gameBoard.getWidth(), gameBoard.getHeight());
	glMatrixMode(GL_MODELVIEW);
}

void my_keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		posY++;
		break;
	case GLUT_KEY_DOWN:
		posY--;
		break;
	case GLUT_KEY_RIGHT:
		posX++;
		break;
	case GLUT_KEY_LEFT:
		posX--;
		break;
	}
}


void myinit()
{
	srand((unsigned int)time(NULL));
	gameBoard.initializeBoard(Color(0.2f,0.4f,0.3f));

}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(10, timer_callback, 0);
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	gameBoard.createBoard();

	glutDisplayFunc(my_display);
	glutReshapeFunc(my_reshape);
	glutSpecialFunc(my_keyboard);
	glutTimerFunc(10, timer_callback, 0);
	myinit();
	
	glutMainLoop();
	return 0;
}