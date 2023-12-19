#include <GL/glut.h>

void drawHouse() {
    // Base of the house
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 200);
    glVertex2i(200, 200);
    glEnd();

    // Roof
    glBegin(GL_LINE_STRIP);
    glVertex2i(200, 200);
    glVertex2i(250, 250);
    glVertex2i(300, 200);
    glEnd();

    // Additional roof lines
    glBegin(GL_LINES);
    glVertex2i(250, 250);
    glVertex2i(400, 250);
    glVertex2i(300, 200);
    glVertex2i(420, 200);
    glVertex2i(400, 250);
    glVertex2i(420, 200);
    glEnd();

    // Side wall
    glBegin(GL_LINE_STRIP);
    glVertex2i(420, 200);
    glVertex2i(420, 100);
    glVertex2i(200, 100);
    glEnd();

    // Door
    glBegin(GL_LINE_LOOP);
    glVertex2i(230, 100);
    glVertex2i(230, 170);
    glVertex2i(260, 170);
    glVertex2i(260, 100);
    glEnd();
}

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    drawHouse();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House Drawing");
    glOrtho(0, 800, 0, 800, -1, 1);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
