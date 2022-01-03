#pragma once
class Snake
{
	struct SnakeNode
	{
		Point position;
		Color snakeColor;
		SnakeNode* next;

		SnakeNode()
		{
			this->next = NULL;
			this->snakeColor = Color(1.0f, 0.0f, 0.0f);
			position = Point(300, 300);


		}

		void setColor(Color snakeColor)
		{
			this->snakeColor = snakeColor;
		}

		void drawSnakeHead()
		{
			glColor3f(snakeColor.red, snakeColor.green, snakeColor.blue);
			glBegin(GL_QUADS);
			glVertex2f(position.x, position.y);
			glVertex2f(position.x + 20.0f, position.y);
			glVertex2f(position.x + 20.0f, position.y - 20.0f);
			glVertex2f(position.x, position.y - 20.0f);
			glEnd();
		}

	};

	SnakeNode* head;
	SnakeNode* tail;
	bool isMove = false;
	Direction direction;
	int health;

public:
	Snake()
	{
		head = tail = new SnakeNode();
		head->setColor(Color(1.0f, 0.0f, 0.0f));
		direction = Direction::left;
		move(direction);
		health = 100;
	}

	void changeHealth(int penalty)
	{
		if (penalty < 10 || penalty > 100)
			throw exception("health must be between 0 and 100!");

		this->health -= penalty;
	}

	void eat()
	{

	}

	void move(Direction dir)
	{
		switch (dir)
		{
		case Direction::up:
			head->position.y++;
			break;
		case Direction::down:
			head->position.y--;
			break;
		case Direction::left:
			head->position.x--;
			break;
		case Direction::right:
			head->position.x++;
			break;
		default:
			break;
		}

	}

	void draw()
	{
			head->drawSnakeHead();

			SnakeNode* temp = new SnakeNode();
			temp->setColor(Color(0.0f, 0.8f, 0.4f));
			temp->position.x += 20;
			glColor3f(temp->snakeColor.red, temp->snakeColor.green, temp->snakeColor.blue);
			glBegin(GL_QUADS);
			glVertex2f(temp->position.x, temp->position.y);
			glVertex2f(temp->position.x + 20.0f, temp->position.y);
			glVertex2f(temp->position.x + 20.0f, temp->position.y - 20.0f);
			glVertex2f(temp->position.x, temp->position.y - 20.0f);
			glEnd();

		

		/*Point newNodePosition = head->position;
		for (int i = 0; i < 2; i++)
		{

			SnakeNode* newNode = new SnakeNode();
			newNodePosition.x += 20;
			newNode->position = newNodePosition;
			temp->next = newNode;
			temp = temp->next;

			temp->setColor(Color(0.0f, 0.8f, 0.4f));
			glColor3f(temp->snakeColor.red, temp->snakeColor.green, temp->snakeColor.blue);
			glBegin(GL_QUADS);
			glVertex2f(temp->position.x, temp->position.y);
			glVertex2f(temp->position.x + 20.0f, temp->position.y);
			glVertex2f(temp->position.x + 20.0f, temp->position.y - 20.0f);
			glVertex2f(temp->position.x, temp->position.y - 20.0f);
			glEnd();
		}
		*/
	}
};


