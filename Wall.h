#pragma once

class Wall : public IObstacle
{
    QuadShape quad;
    Color rgbColor;

    void draw()
    {
        glColor3f(rgbColor.red, rgbColor.green, rgbColor.blue);
      
        glBegin(GL_QUADS);
        glColor3f(rgbColor.red - 1.0, rgbColor.green - 2.0, rgbColor.blue - 1.0);
        glVertex2f(quad.pointOne.x, quad.pointOne.y);
        glVertex2f(quad.pointTwo.x, quad.pointTwo.y);
        glVertex2f(quad.pointThree.x, quad.pointThree.y);
        glVertex2f(quad.pointFour.x, quad.pointFour.y);

        glEnd();
        glFlush();
        
    }

public:
    Wall(QuadShape quad)
    {
        rgbColor.red = rgbColor.green = rgbColor.blue = 0.0;
        this->quad = quad;
    }

    void changeColor(Color rgbColor)
    {
        this->rgbColor = rgbColor;
    }

    void damage()
    {
        //TODO
        return;   
    }

};
