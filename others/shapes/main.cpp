#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-4, 4, -4, 4, -4, 4);

    //triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-2.0, -2.0);
    glVertex2f(2.0, -2.0);
    glVertex2f(0.0, 2.0);
    glEnd();

    //Rectangle
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-3.0, -3.0);
    glVertex2f(-1.0, -3.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-3.0, -1.0);
    glEnd();

    //lines
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-4.0, 0.0);
    glVertex2f(-2.0, 0.0);

    glVertex2f(-3.0, 1.0);
    glVertex2f(-3.0, -1.0);

    glVertex2f(2.0, 0.0);
    glVertex2f(4.0, 0.0);

    glVertex2f(3.0, 1.0);
    glVertex2f(3.0, -1.0);

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Geometric Shapes");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
