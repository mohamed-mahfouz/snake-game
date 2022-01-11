#pragma once

class FoodManager
{
	bool isGenerated;
	Food food;
	Point boardBoundaries;
	Point position;

	void draw()
	{

		glColor3f(food.getColor().red, food.getColor().green, food.getColor().blue);
		glBegin(GL_QUADS);
		glVertex2d(position.x, position.y); glVertex2d(position.x + 1, position.y); glVertex2d(position.x + 1, position.y + 1); glVertex2d(position.x, position.y + 1);
		glEnd();

	}


public:
	FoodManager()
	{
		isGenerated = false;
		srand(time(NULL));
	}

	FoodManager(Food food , Point boardBoundaries)
	{
		srand(time(NULL));
		this->food = food;
		this->boardBoundaries = boardBoundaries;

	}

	void Initialize() 
	{

		if (!isGenerated)
		{
			position.x = 1 + rand() % (boardBoundaries.x - 2);
			position.y = 1 + rand() % (boardBoundaries.y - 2);
			isGenerated = true;
		}

		draw();
	}

	void regenerate()
	{
		isGenerated = false;
	}

	Point getPosition() 
	{
		return position;
	}

	void invokeFood(Food food) 
	{
		this->food = food;
	}

	void invokeBoardBoundaries(Point boundaries) 
	{
		this->boardBoundaries = boundaries;
	}

};