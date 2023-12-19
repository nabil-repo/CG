#include <iostream>
#include <GL/glut.h>

using namespace std;

void init()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void bFill(int x, int y, float* fillColor,float *dColor)
{
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]==dColor[0] && color[1]==dColor[1] && color[2]==dColor[2]))
    {
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        bFill(x+1,y,fillColor,dColor);
        bFill(x-2,y,fillColor,dColor);
        bFill(x,y+2,fillColor,dColor);
        bFill(x,y-2,fillColor,dColor);


       /* bFill(x-1,y+1,fillColor,dColor);
        bFill(x+1,y-1,fillColor,dColor);
        bFill(x-1,y-1,fillColor,dColor);
        bFill(x+1,y+1,fillColor,dColor);*/


    }
}

void display()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(150,100);
    glVertex2i(300,300);
    glVertex2i(450,100);
    glEnd();

   /* glBegin(GL_LINE_LOOP);
    glVertex2i(150,250);
    glVertex2i(300,50);
    glVertex2i(450,250);
    glEnd();*/

    glFlush();

    float dCol[] = {1,0,0};
    float fcol[] = {0,0,1};
    bFill(300,200,fcol,dCol);


}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Boundary FIll");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
