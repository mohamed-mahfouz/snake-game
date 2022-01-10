#pragma once

class Food
{
	short score;
	Color rgbColor;

public:
	Food()
	{
		this->rgbColor = Color(0.7,0.9,0.0);
		this->score = 10;
	}

	void setScore(short score)
	{
		if (score < 10 || score > 30)
			throw exception("score must be between 10 and 30!");

		this->score = score;
	}

	short getScore() 
	{
		return this->score;
	}

	void setColor(Color rgbColor) 
	{
		this -> rgbColor = rgbColor;
	}

	Color getColor() 
	{
		return rgbColor;
	}

};
