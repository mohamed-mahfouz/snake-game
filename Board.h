#pragma once

class Board
{
	Color rgbColor;
	GLdouble rows;
	GLdouble columns;
	short width;
	short height;
	
	
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
		gluOrtho2D(0.0, rows, 0.0, columns);
	}

public:
	Board()
	{
		 
		 this->rows = this->columns = 40;
		 this->width = 700;
		 this->height = 700;
		 this->rgbColor = Color(0.2f, 0.4f, 0.3f);
		
	}

	void initializeBoard()
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

	void displayBoundaries()
	{
		short boundaryWidth = 10;
		glLineWidth(boundaryWidth);
		glColor3f(0.9, 0.2, 0.0);
		glBegin(GL_LINES);
		glVertex2d(0, 0); glVertex2d(0, columns);
		glVertex2d(0, 0); glVertex2d(rows, 0);
		glVertex2d(rows, columns); glVertex2d(0, columns);
		glVertex2d(rows, columns); glVertex2d(rows, 0);
		glEnd();
	}

	void setColor(Color rgbColor)
	{
		this->rgbColor = rgbColor;
	}

	short getWidth()
	{
		return width;
	}

	short getHeight()
	{
		return height;
	}


	Point getCoordinates() 
	{
		return Point(rows , columns );
	}

		

};