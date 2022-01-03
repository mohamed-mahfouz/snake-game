#pragma once

class Food
{
	int score;
	bool isGenerated;
	short boardWidth;
	short boardHeight;
	Point position;
	Color rgbColor;

	void draw()
	{
		glColor3f(rgbColor.red, rgbColor.green, rgbColor.blue);
		glBegin(GL_QUADS);
		glVertex2d(position.x, position.y); glVertex2d(position.x + 1, position.y); glVertex2d(position.x + 1, position.y + 1); glVertex2d(position.x, position.y + 1);
		glEnd();

	}

public:
	Food( Point BoardCoordinates )
	{
		this->rgbColor = Color(0.7,0.9,0.0);
		this->score = score;
		this->isGenerated = false;
		this->boardHeight = BoardCoordinates.y;
		this->boardWidth = BoardCoordinates.x;
	}

	void changeScore(int score)
	{
		if (score < 10 || score > 30)
			throw exception("score must be between 10 and 30!");

		this->score = score;
	}

	void changeColor(Color rgbColor) 
	{
		this -> rgbColor = rgbColor;
	}

	void generateFood()
	{
		
		if (!isGenerated) 
		{
			position.x = 1 + rand() % boardWidth  - 2;
			position.y = 1 + rand() % boardHeight - 2;
			isGenerated = true;
		}
		draw();
	}

	void regenrate() 
	{
		isGenerated = false;
	}

	short getX() 
	{
		return position.x;
	}

	short getY() 
	{
		return position.y;
	}
};
