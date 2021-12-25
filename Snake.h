#pragma once
class Snake
{
	struct SnakeNode 
	{
		float positionX;
		float positionY;
		SnakeNode* next;

		void setColor(float red, float green, float blue) 
		{

		}
	};

	SnakeNode* head;
	SnakeNode* tail;
	int health;

public:
	Snake()
	{
		head = tail = NULL;
		health = 100;
	}

	void changeHealth(int penalty) 
	{
		if (penalty < 0 || penalty > 100)
			throw exception("health must be between 0 and 100!");

		this->health -= penalty;
	}

	void eat() 
	{

	}

	void move() 
	{

	}

};

