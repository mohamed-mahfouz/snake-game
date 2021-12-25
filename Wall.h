#pragma once

class Wall : public IObstacle
{
    QuadShape quad;
    Color rgbColor;

    void draw()
    { 
        glBegin(GL_QUADS);
        glColor3f(rgbColor.red, rgbColor.green, rgbColor.blue);
        glVertex2f(quad.pointOne.x, quad.pointOne.y);
        glVertex2f(quad.pointTwo.x, quad.pointTwo.y);
        glVertex2f(quad.pointThree.x, quad.pointThree.y);
        glVertex2f(quad.pointFour.x, quad.pointFour.y);
        glEnd();
        glFlush();
        
    }

public:
    Wall(QuadShape quad , Color rgbColor = Color(0.0f,0.0f,0.0f))
    {
        this->rgbColor = rgbColor;
        this->quad = quad;

        draw();
    }

    void damage()
    {
        //TODO
        return;   
    }

};
