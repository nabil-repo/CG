#include <iostream>
#include <GL/glut.h>

int x1, y1, x2, y2;

void brezenham(int x1, int y1, int x2, int y2)
{
    glBegin(GL_POINTS);

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        glVertex2i(x1, y1);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }

    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    brezenham(100, 100, 100, 300);
    brezenham(100, 300, 300, 300);
    brezenham(300, 300, 300, 100);
    brezenham(300, 100, 100, 100);

    brezenham(100, 200, 200, 300);
    brezenham(200, 300, 300, 200);
    brezenham(300, 200, 200, 100);
    brezenham(200, 100, 100, 200);

    brezenham(150, 150, 150, 250);
    brezenham(150, 250, 250, 250);
    brezenham(250, 250, 250, 150);
    brezenham(250, 150, 150, 150);






    glFlush();
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
}

int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    init();
    glutMainLoop();

    return 0;
}
