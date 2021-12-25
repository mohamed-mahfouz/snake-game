#pragma once

struct Color
{
	float red;
	float green;
	float blue;

	Color()
	{
	}

	Color(float red , float green , float blue)
	{
		this->red = red;
		this->blue = blue;
		this->green = green;
	}
};