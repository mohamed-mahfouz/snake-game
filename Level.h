#pragma once

class Level 
{
	vector<IObstacle*> obstacles;

public:

	~Level()
	{
		if (!obstacles.empty()) 
		{
			for (int i = 0; i < obstacles.size(); i++)
			{
				delete obstacles[i];
			}
		}
	}

	void addObstacle(IObstacle* obstacle) 
	{
		obstacles.push_back(obstacle);
	}

	const vector<IObstacle*> getAllObstacles() 
	{
		return obstacles;
	}

};