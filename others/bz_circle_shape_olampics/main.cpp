#include <iostream>
#include <GL/glut.h>

using namespace std;

int xc, yc, r;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {

        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x);
        setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc - x);

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle(230, 500, 50);
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(350, 500, 50);
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(480, 500, 50);


    glColor3f(1.0, 1.0, 0.0);
    drawCircle(300, 450, 50);
    glColor3f(0.0, 1.0, 0.0);
    drawCircle(410, 450, 50);


    glFlush();
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 800, -1, 1);
    glutDisplayFunc(display);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    init();
    glutMainLoop();

    return 0;
}
