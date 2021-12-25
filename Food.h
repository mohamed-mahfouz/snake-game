#pragma once

class Food 
{
	int score;
	Point position;
	Color rgbColor;

	void draw() 
	{
		glColor3f(rgbColor.red, rgbColor.green, rgbColor.blue);
		glBegin(GL_QUADS);

		glVertex2f(position.x, position.y);
		glVertex2f(position.x + 20.0, position.y);
		glVertex2f(position.x + 20.0, position.x - 20.0);
		glVertex2f(position.y, position.y - 20.0);

		/*
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2i(x, y);
		glVertex2i(x + 20, y);
		glColor3f(0.2, 0.5, 0.2);
		glVertex2i(x + 20, y - 20);
		glVertex2i(x, y - 20);
		glEnd();
		glFlush();

		glEnd();
		glFlush();
		*/
	}
public:
	Food(Color rgbColor)
	{
		this->rgbColor = rgbColor;
	    score = 10;
	}

	void changeScore(int score) 
	{
		if (score < 10 || score > 30)
			throw exception("score must be between 10 and 30!");

		this->score = score;
	}

	void generateFood() 
	{
		//bottomLeft = 0 , bottomRight = 600
		//upLeft     = 0 , upRight     = 600 
		//so positions must be between 10 and 590 !

		position.x = rand() % 590 + 10.0;
		position.y = rand() % 590 + 10.0;

		draw();
	}
};
