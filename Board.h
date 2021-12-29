#pragma once

class Board
{
	short width;
	short height;
	GLdouble rows;
	GLdouble columns;
	Color boardColor;

	void boardPosition(int x = 100, int y = 100)
	{
		glutInitWindowPosition(x, y);
	}

	void boardHeaderName(const char* name = "Snake")
	{
		glutCreateWindow(name);
	}

	void boardMode()
	{
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

	}

	void coordinates()
	{
		boardMode();
		gluOrtho2D(0.0, this->rows, 0.0, this->columns);
	}

public:
	Board(short width, short height)
	{
		this->height = height;
		this->width = width;
		this->rows = this->columns = 600;
		
	}

	short getWidth()
	{
		return width;
	}

	short getHeight()
	{
		return height;
	}

	void initializeBoard(Color rgbColor = Color(0.0f, 0.0f, 0.0f))
	{
		glClearColor(rgbColor.red, rgbColor.green, rgbColor.blue, 1.0f);
		coordinates();
	}

	void createBoard()
	{
		glutInitWindowSize(width, height);
		boardPosition();
		boardHeaderName();
	}

	void changeHeaderName(const char* name)
	{
		boardHeaderName(name);
	}

	void changeBoardPosition(int x, int y)
	{
		boardPosition(x, y);
	}


	void changeCoordinates(GLdouble rows, GLdouble columns)
	{
		this->rows = rows;
		this->columns = columns;
	}

	void displayBoundaries()
	{
		
		glLineWidth(10.0);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(0, 0); glVertex2d(0 , columns);
		glVertex2d(0, 0); glVertex2d(rows, 0);
		glVertex2d(rows, columns); glVertex2d(0, columns);
		glVertex2d(rows, columns); glVertex2d(rows, 0);
		glEnd();

	}

};