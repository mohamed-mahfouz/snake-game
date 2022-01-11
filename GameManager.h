#pragma once
#define maxScore 500;

#include"Point.h"
#include"Color.h"
#include"QuadShape.h"
#include"EDirection.h"
#include"IObstacle.h"
#include"Food.h"
#include"Snake.h"
#include"Wall.h"
#include"Board.h"
#include"Level.h"
#include"FoodManager.h"


class GameManager 
{
	
	int playerScore;
	int level;
	Board gameBoard;
	Snake snake;
	Food food;
	FoodManager foodManager;
	

	bool isSnakeHitWall() 
	{
		short leftWall = 0;
		short bottomWall = 0;
		short rightWall = gameBoard.getCoordinates().x - 1;
		short topWall = gameBoard.getCoordinates().y - 1;

		return  (snake.getHeadPosition().x == leftWall) ||
				(snake.getHeadPosition().x == rightWall) ||
				(snake.getHeadPosition().y == bottomWall) ||
				(snake.getHeadPosition().y == topWall);

	}

	bool isSnakeEatItSelf() 
	{
		return snake.isEatItSelf();
	}

	bool isPlayerWin() 
	{
		return playerScore == maxScore;
	}

	bool isSnakeEatFood() 
	{
		return
			snake.getHeadPosition().x == foodManager.getPosition().x &&
			snake.getHeadPosition().y == foodManager.getPosition().y;
	}

	void MsgBox(char* msg, int playerScore)
	{

		char score[4];
		const int size = 60;
		char text[size];
		_itoa_s(playerScore, score, 10);
		strcpy_s(text, msg);
		strcat_s(text, sizeof text, score);
		MessageBoxA(NULL, text, "Game Over", 0);
	}

	void managePlayer() 
	{
		
		if (isPlayerWin())  
		{
			char msg[] = "Winner!, your score is: ";
			MsgBox(msg , playerScore);
			exit(0);
		}
		else if (isSnakeEatItSelf() || isSnakeHitWall() || snake.getHealth() == 0) 
		{
			char msg[] = "Looser!, your score is: ";
			MsgBox(msg , playerScore);
			exit(0);
		}
			
	}

	void manageSnake()
	{
		if (level > 0) 
		{
			snake.move();

			if (isSnakeEatFood())
				snake.grow();
		}
	}

	void manageFood() 
	{
		if (level > 0) 
		{
			foodManager.Initialize();

			if (isSnakeEatFood())
			{
				foodManager.regenerate();
				playerScore += food.getScore();
			}
		}
	}
public:
	GameManager() 
	{
		level = playerScore = 0;
		gameBoard.setColor(Color(0.0f, 0.2f, 0.4f));
		food.setColor(Color(0.9f, 0.9f, 0.0f));
		food.setScore(10);
		foodManager.invokeFood(food);
		foodManager.invokeBoardBoundaries(gameBoard.getCoordinates());
	
	}

	void displayCallback()
	{

		glClear(GL_COLOR_BUFFER_BIT);
		gameBoard.displayBoundaries();
		managePlayer();
		manageSnake();
		manageFood();
		manageLevels();
		glutSwapBuffers();
		
	}

	void inputCallback(int key, int x, int y)
	{

		switch (key)
		{
		case GLUT_KEY_UP:
			if (snake.getDirection() != Direction::down)
				snake.setDirection(Direction::up);
			break;

		case GLUT_KEY_DOWN:
			if (snake.getDirection() != Direction::up)
				snake.setDirection(Direction::down);
			break;

		case GLUT_KEY_RIGHT:
			if (snake.getDirection() != Direction::left)
				snake.setDirection(Direction::right);
			break;

		case GLUT_KEY_LEFT:
			if (snake.getDirection() != Direction::right)
				snake.setDirection(Direction::left);
			break;
		}

	}

	void reshapeCallback(GLsizei x, GLsizei y)
	{

		glutReshapeWindow(gameBoard.getWidth(), gameBoard.getHeight());
		glMatrixMode(GL_MODELVIEW);

	}

	void initialize()
	{
		gameBoard.initializeBoard();
	}

	void run(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
		gameBoard.createBoard();

	}

	void setLevel(int level) 
	{
		this->level = level;
	}

	void manageLevels() 
	{
		
		switch (level)
		{
		case 2:
			applyLevel(mediumLevel());
			break;
		case 3:
			applyLevel(hardLevel());
			break;
		default:
			break;
		}

	}

	Level* mediumLevel() 
	{

		Wall* verticalWall = new Wall(QuadShape(Point(18, 10), Point(20, 10), Point(20, 30), Point(18, 30)));

		Level* levelToReturn = new Level;
		levelToReturn->addObstacle(verticalWall);
		return levelToReturn;

	}

	Level* hardLevel() 
	{

		Wall* verticalWall = new Wall(QuadShape(Point(18, 10), Point(20, 10), Point(20, 30), Point(18, 30)));
		Wall* horizentalWall = new Wall(QuadShape(Point(10, 19), Point(10, 22), Point(30, 22), Point(30, 19)));

		Level* levelToReturn = new Level;
		levelToReturn->addObstacle(verticalWall);
		levelToReturn->addObstacle(horizentalWall);
		return levelToReturn;
	}

	void applyLevel(Level* level) 
	{

		auto obstacles = level->getAllObstacles();
		
		for (int i = 0; i < obstacles.size(); i++) 
		{

			pair fromToEndWidthPair = obstacles[i]->widthCoordinates();
			pair fromToEndHeightPair = obstacles[i]->heightCoordinates();
			int widthBegin = fromToEndWidthPair.first;
			int widthEnd = fromToEndWidthPair.second;
			int heightBegin = fromToEndHeightPair.first;
			int heightEnd = fromToEndHeightPair.second;	

			if ((foodManager.getPosition().x >= widthBegin && foodManager.getPosition().x <= widthEnd)&&
				(foodManager.getPosition().y >= heightBegin && foodManager.getPosition().y <= heightEnd))
				
			{
				foodManager.regenerate();
			}
				
			if ((snake.getHeadPosition().x >= widthBegin   && snake.getHeadPosition().x <= widthEnd-1 ) &&
				(snake.getHeadPosition().y >= heightBegin  && snake.getHeadPosition().y <= heightEnd-1))
			{

				snake.setPenalty(obstacles[i]->penalty());
			}
				
		}
		
	}

};