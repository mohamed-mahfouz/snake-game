#pragma once
#define maxLength 150 

class Snake
{

	class SnakeIterator
	{
		int index;
		const Snake* snake;

	public:
		SnakeIterator(const Snake* snake)
		{
			this->snake = snake;
		}

		void first()
		{
			index = 0;
		}

		void next()
		{
			index++;
		}

		bool isEnd()
		{
			return index == snake->snakeLength;
		}

		Point cuurentItem()
		{
			return snake->positions[index];
		}

	};

	Direction direction;
	Point positions[maxLength] = {Point(10,6),Point(10,5),Point(10,4)};
	int snakeLength = 3;
	short health = 100;
	bool eatItSelf = false;

	bool _isEatItSelf(Point position)
	{
		if (getHeadPosition().x == position.x && getHeadPosition().y == position.y)
			return true;

		return false;

	}

	void draw()
	{

		for (int i = 0; i < snakeLength; i++)
		{

			int headIndex = 0;
			if (i > headIndex && _isEatItSelf(positions[i]))
			{
				eatItSelf = true;
			}
			
			if (i == headIndex)
				glColor3f(1.0f, 0.0f, 0.0f);

			else
				glColor3f(0.0f, 1.0f, 0.0f);

			glBegin(GL_QUADS);
			glVertex2d(positions[i].x, positions[i].y); glVertex2d(positions[i].x + 1, positions[i].y);
			glVertex2d(positions[i].x + 1, positions[i].y + 1); glVertex2d(positions[i].x, positions[i].y + 1);
			glEnd();

		}

	}

public:
	Snake()
	{
		srand(time(NULL));
		direction = (Direction)(rand() % 3);
			
	}

	void setDirection(Direction input)
	{
		direction = input;
	}

	Direction getDirection()
	{
		return direction;
	}

	Point getHeadPosition()
	{
		return positions[0];
	}

	void move()
	{

		for (int i = snakeLength - 1; i > 0; i--)
		{
			positions[i] = positions[i - 1];

		}

		switch (direction)
		{
		case Direction::up:
			positions[0].y++;
			break;
		case Direction::down:
			positions[0].y--;
			break;
		case Direction::left:
			positions[0].x--;
			break;
		case Direction::right:
			positions[0].x++;
			break;
		default:
			break;
		}

		draw();

	}

	void grow()
	{
		this->snakeLength++;
	}

	SnakeIterator* getIterator()
	{
		return new SnakeIterator(this);
	}

	bool isEatItSelf() 
	{
		return eatItSelf;
	}

	void setPenalty(short penalty) 
	{
		if (penalty < 0 || penalty > 100) 
			throw exception("Penalty should be between 0 and 100!");
		
		this->health -= penalty;
	}

	short getHealth() 
	{
		return health;
	}

};


