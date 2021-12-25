#pragma once

struct QuadShape
{
    Point pointOne;
    Point pointTwo;
    Point pointThree;
    Point pointFour;

    QuadShape(){}

    QuadShape(Point pointOne, Point pointTwo, Point pointThree, Point pointFour)
    {
        this->pointOne = pointOne;
        this->pointTwo = pointTwo;
        this->pointThree = pointThree;
        this->pointFour = pointFour;
    }
};