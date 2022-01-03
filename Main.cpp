#include<iostream>
#include<vector>
#include<GL/glut.h>

using namespace std;

#include"EDirection.h"
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
Snake snake;
Food food(gameBoard.getCoordinates());

Direction snakeDirection;
int posY[] = { 10,10,10 };
int posX[] = { 10,9,8 };
void snakeHead()
{

	for (int i = 2; i > 0; i--) 
	{
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];
	}
	
	switch (snakeDirection)
	{
	case Direction::up:
		posY[0]++;
		break;
	case Direction::down:
		posY[0]--;	
		break;
	case Direction::left:
		posX[0]--;
		break;
	case Direction::right:
		posX[0]++;
		break;
	default:
		break;
	}

	for (int i = 0; i < 3; i++)
	{

		if (i == 0) 
			glColor3f(1.0f, 0.0f, 0.0f);

		else
			glColor3f(0.0f, 1.0f, 0.0f);

		glBegin(GL_QUADS);
		glVertex2d(posX[i], posY[i]); glVertex2d(posX[i] + 1, posY[i]); glVertex2d(posX[i] + 1, posY[i] + 1); glVertex2d(posX[i], posY[i] + 1);
		glEnd();

	}

	if (posX[0] == food.getX() && posY[0] == food.getY())
		food.regenrate();
}

bool isGameOver()
{
	short leftBorder = 0;
	short rightBorder = gameBoard.getCoordinates().x - 1;
	short bottomBorder = 0;
	short topBorder = gameBoard.getCoordinates().y - 1;

	if (posX[0] == 0 || posX[0] == rightBorder || posY[0] == 0 || posY[0] == topBorder)
		return true;

	return false;
}

void my_display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	gameBoard.displayBoundaries();
	//snake.draw();
	snakeHead();
	food.generateFood();
	glutSwapBuffers();

	if (isGameOver())
	{
		MessageBox(NULL, (LPCWSTR)"your score : ", (LPCWSTR)"Game Over", 0);
		exit(0);
	}

}

void my_reshape(GLsizei x, GLsizei y)
{
	glutReshapeWindow(gameBoard.getWidth(), gameBoard.getHeight());
	glMatrixMode(GL_MODELVIEW);
}

/*void my_keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
			snake.move(Direction::up);
		break;
	case GLUT_KEY_DOWN:

			snake.move(Direction::down);
		break;
	case GLUT_KEY_RIGHT:
			snake.move(Direction::right);
		break;
	case GLUT_KEY_LEFT:
			snake.move(Direction::left);
		break;
	}
}
*/

void my_keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		snakeDirection = Direction::up;
		break;
	case GLUT_KEY_DOWN:
		snakeDirection = Direction::down;
		break;
	case GLUT_KEY_RIGHT:
		snakeDirection = Direction::right;
		break;
	case GLUT_KEY_LEFT:
		snakeDirection = Direction::left;
		break;
	}
}


void myinit()
{
	gameBoard.initializeBoard(Color(0.2f, 0.4f, 0.3f));
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(100, timer_callback, 0);
}

int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));
	snakeDirection = Direction(rand() % 5);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	gameBoard.createBoard();

	glutDisplayFunc(my_display);
	glutReshapeFunc(my_reshape);
	glutSpecialFunc(my_keyboard);
	glutTimerFunc(100, timer_callback, 0);

	myinit();
	glutMainLoop();
	return 0;
}