#include<iostream>
#include<GL/glut.h>

using namespace std;

#include"Point.h"
#include"Color.h"
#include"QuadShape.h"
#include"Food.h"
#include"Snake.h"
#include"IObstacle.h"
#include"Wall.h"

void my_display()
{
	 
    Food food(Color(0.5f, 0.6f, 0.7f));
	food.generateFood();

	QuadShape quad(Point(0.0, 0.0), Point(10.0, 0.0), Point(10.0, 600.0), Point(0.0, 600.0));
	Wall testWall(quad);

	/*glVertex2f(0.0, 0.0);
	glVertex2f(10.0, 0.0);
	glVertex2f(10.0, 600.0);
	glVertex2f(0.0, 600.0);
	*/

}

void my_reshape(GLsizei x, GLsizei y)
{
	glutReshapeWindow(600, 600);
}

void my_keyboard(int key, int x, int y)
{

}


void myinit()
{
	srand((unsigned int)time(NULL));
	//default clear color so when we use glClear() it will be displayed(Window Color)
	glClearColor(0.0f, 0.3f, 0.0f, 0.0f);

	//Clear the frame buffer (area where we draw things)
	//we then draw things we want after cleaning it 
	//but to display data we need to use glFlush()
	glClear(GL_COLOR_BUFFER_BIT);

	//set up what we want to see (viewing fuckn staff)
	glMatrixMode(GL_PROJECTION);

	//make matrix to it's current state (if you multiply with another vector the resuklt is same!!)
	//resets the matrix (coordinate system)
	glLoadIdentity();

	//make left size = 0 and right side = 600 and bottom = 0 and up = 600
	//make the positions in window equals to the width = 600 and height = 600
	//starting for width and height is (0 , 0)
	gluOrtho2D(0, 600.0, 0, 600.0);

	glFlush();

}



int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Snake");

	glutDisplayFunc(my_display);
	glutReshapeFunc(my_reshape);
	glutSpecialFunc(my_keyboard);

	myinit();

	glutMainLoop();
	return 0;
}