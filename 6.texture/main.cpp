#include <iostream>
#include <GL/glut.h>

#define chkImgWidth 64
#define chkImgHeight 64

static GLubyte chkImg[chkImgHeight][chkImgWidth][4];
static GLuint texName;

void makeCheckImg(void)
{
    int i, j, c;

    for (i = 0; i < chkImgHeight; i++)
    {
        for (j = 0; j < chkImgWidth; j++)
        {
            c = ((((i & 0x8) == 0) ^ ((j & 0x8) == 0)) * 255);
            chkImg[i][j][0] = (GLubyte)c;
            chkImg[i][j][1] = (GLubyte)c;
            chkImg[i][j][2] = (GLubyte)c;
            chkImg[i][j][3] = (GLubyte)255;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texName);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-2.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-2.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(2.41421, 1.0, -1.41421);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(2.41421, -1.0, -1.41421);
    glEnd();

    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture Mapping");

    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    makeCheckImg();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, chkImgWidth, chkImgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, chkImg);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
