#pragma once

class Wall : public IObstacle
{
	QuadShape quad;

	void draw()
	{
		glBegin(GL_QUADS);
		glColor3f(1.0, 0.8, 0.7);
		glVertex2f(quad.pointOne.x, quad.pointOne.y);
		glVertex2f(quad.pointTwo.x, quad.pointTwo.y);
		glColor3f(0.8, 0.5, 0.5);
		glVertex2f(quad.pointThree.x, quad.pointThree.y);
		glVertex2f(quad.pointFour.x, quad.pointFour.y);
		glEnd();
		glFlush();

	}

public:
	Wall(QuadShape quad)
	{

		this->quad = quad;
		draw();
	}

	int penalty()
	{
		int damageToSnake = 100;
		return damageToSnake;
	}

	pair<int,int> widthCoordinates() 
	{
		pair coordinates =  make_pair<int,int>(MAXINT,MININT);
		int widthCoordinates[4] = 
		{ 
			quad.pointOne.x ,
			quad.pointTwo.x , 
			quad.pointThree.x , 
			quad.pointFour.x 
		};

		for (int i = 0; i < 4; i++) 
		{
			if (widthCoordinates[i] < coordinates.first)
				coordinates.first = widthCoordinates[i];
		}


		for (int i = 0; i < 4; i++)
		{
			if (widthCoordinates[i] > coordinates.second)
				coordinates.second = widthCoordinates[i];
		}

		return coordinates;
	}

	pair<int, int> heightCoordinates()
	{
		pair coordinates = make_pair<int, int>(MAXINT, MININT);
		int heightCoordinates[4] =
		{
			quad.pointOne.y,
			quad.pointTwo.y,
			quad.pointThree.y,
			quad.pointFour.y
		};

		for (int i = 0; i < 4; i++)
		{
			if (heightCoordinates[i] < coordinates.first)
				coordinates.first = heightCoordinates[i];
		}


		for (int i = 0; i < 4; i++)
		{
			if (heightCoordinates[i] > coordinates.second)
				coordinates.second = heightCoordinates[i];
		}

		return coordinates;
	}
};
