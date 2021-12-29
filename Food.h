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
		glVertex2f(position.x + 20.0f, position.y);
		glColor3f(rgbColor.red - 0.3f, rgbColor.green - 0.2f, rgbColor.blue + 0.1f);
		glVertex2f(position.x + 20.0f, position.y - 20.0f);
		glVertex2f(position.x, position.y - 20.0f);
		glEnd();
		glFlush();

	}
public:
	Food(Color rgbColor, int score = 10)
	{
		this->rgbColor = rgbColor;
		this->score = score;
	}

	void changeScore(int score)
	{
		if (score < 10 || score > 30)
			throw exception("score must be between 10 and 30!");

		this->score = score;
	}

	void generateFood()
	{
		position.x = rand() % 570 + 15.0f;
		position.y = rand() % 570 + 15.0f;
		draw();
	}
};
