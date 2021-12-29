#pragma once

class Level 
{
	vector<IObstacle*> obstacles;
	int score;
	int speed;
public:
	Level(int speed )
	{
		this->obstacles = obstacles;
		this->speed = speed;
	}

	void setScore(int score) 
	{
		this->score = score;
	}

	int getScore() 
	{
		return score;
	}

	void setSpeed(int speed) 
	{
		this->speed = speed;
	}

	int getSpeed() 
	{
		return this->speed;
	}

	void addObstacle(IObstacle* obstacle) 
	{
		obstacles.push_back(obstacle);
	}

};