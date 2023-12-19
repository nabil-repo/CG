#include <iostream>
#include <algorithm>
#include <GL/glut.h>


using namespace std;

struct Point
{
    int x, y;
};

void drawHorizontalLine(int x1, int x2, int y)
{
    glBegin(GL_LINES);
    glVertex2i(x1, y);
    glVertex2i(x2, y);
    glEnd();

}

void scanlineFill(Point vertices[], int numVertices)
{
    int minY = vertices[0].y, maxY = vertices[0].y;


    for (int i = 1; i < numVertices; ++i)
    {
        if (vertices[i].y < minY)
            minY = vertices[i].y;
        if (vertices[i].y > maxY)
            maxY = vertices[i].y;
    }


    for (int y = minY; y <= maxY; ++y)
    {

        Point intersectPoints[100];
        int numIntersects = 0;


        for (int i = 0; i < numVertices; ++i)
        {
            Point p1 = vertices[i];
            Point p2 = vertices[(i + 1) % numVertices];
            Point intersect1, intersect2;

            if ((p1.y <= y && p2.y > y) || (p2.y <= y && p1.y > y))
            {

                intersect1.x = static_cast<int>((y - p1.y) / static_cast<double>(p2.y - p1.y) * (p2.x - p1.x) + p1.x);
                intersect1.y = y;
                intersectPoints[numIntersects++] = intersect1;
            }
        }


        sort(intersectPoints, intersectPoints + numIntersects, [](const Point &a, const Point &b)
        {
            return a.x < b.x;
        });

        for (int i = 0; i < numIntersects; i += 2)
        {
            drawHorizontalLine(intersectPoints[i].x, intersectPoints[i + 1].x, y);

        }

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    Point vertices[] = {{150, 100}, {300, 300}, {450, 100}};
    int numVertices = sizeof(vertices) / sizeof(vertices[0]);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; ++i)
        glVertex2i(vertices[i].x, vertices[i].y);
    glEnd();

    glColor3f(0, 0, 1);

    scanlineFill(vertices, numVertices);

    glFlush();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 640, 0, 480, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Scanline Fill");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
