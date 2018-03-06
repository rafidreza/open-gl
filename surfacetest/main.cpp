/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include<iostream>
#include<cmath>
#include<GL/glut.h>

using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(
              25.0,25.0,-25.0,
              0.0,0.0,0.0,
              0.0,1.0,0.0
              );
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-15.0,0.0,15.0);
        glVertex3f(15.0,0.0,15.0);
        glVertex3f(15.0,0.0,-15.0);
        glVertex3f(-15.0,0.0,-15.0);
    glEnd();
    glTranslated(5.0,1.0,5.0);
    glutWireCube(1.0);
    glFlush();
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Hello 3d");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
