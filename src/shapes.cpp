#include "shapes.h"

circlebrush::circlebrush(float x, float y, float r)
    :cx(x), cy(y), r(r)
{

}

void circlebrush::drawShape()
{
    int num_segments = 50;
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii += 1)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void circlebrush::drawHollow()
{
    int num_segments = 50;
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii += 1)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

squarebrush::squarebrush(float x, float y, float r)
    :cx(x), cy(y), r(r)
{

}

void squarebrush::drawShape()
{
    glBegin(GL_POLYGON);
    int l = 2 * r;
    glVertex2f(cx + r, cy + r);
    glVertex2f(cx + r, cy - r);
    glVertex2f(cx - r, cy - r);
    glVertex2f(cx - r, cy + r);
    glEnd();
}

void squarebrush::drawHollow()
{
    glBegin(GL_LINE_LOOP);
    int l = 2 * r;
    glVertex2f(cx + r, cy + r);
    glVertex2f(cx + r, cy - r);
    glVertex2f(cx - r, cy - r);
    glVertex2f(cx - r, cy + r);
    glEnd();
}



trianglebrush::trianglebrush(float x, float y, float r)
    :cx(x), cy(y), r(r)
{

}

void trianglebrush::drawShape() 
{
    float x1 = cx;
    float x2 = cx + 2 * r * cos(3.414 / 3); // for some reason without multiplying by 2 ( 2*r*cos... ) the triangle was looking wierd
    float x3 = cx - 2 * r * cos(3.414 / 3);

    float y1 = cy + r;
    float y2 = cy - r * sin(3.414 / 3);
    float y3 = y2;

    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}


void trianglebrush::drawHollow()
{
    float x1 = cx;
    float x2 = cx + 2 * r * cos(3.414 / 3); // for some reason without multiplying by 2 ( 2*r*cos... ) the triangle was looking wierd
    float x3 = cx - 2 * r * cos(3.414 / 3);

    float y1 = cy + r;
    float y2 = cy - r * sin(3.414 / 3);
    float y3 = y2;

    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}