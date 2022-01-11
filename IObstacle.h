#pragma once

__interface IObstacle
{
	void draw();
	int penalty();
	pair<int,int> widthCoordinates();
	pair<int,int> heightCoordinates();

};