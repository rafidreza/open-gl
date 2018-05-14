#include <Windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

void mouse(int button, int state, int mx, int my)
{
    my =glutGet(GLUT_WINDOW_HEIGHT)-my;
    printf(" %d %d ",mx,my);
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(1,0,0);
            glVertex2i(mx-30,my);
            glColor3f(1,0,0);
            glVertex2i(mx+30,my);
            glColor3f(1,0,0);
            glVertex2i(mx,my+30);
            glEnd();
            glFlush();
        }

        if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
        }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(50,50);
    glutCreateWindow("lool");
    glutMouseFunc(mouse);
    gluOrtho2D(400,0,400);
    glClearColor(0.8,0.5,0.5,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutMainLoop();
    return 0;
}
