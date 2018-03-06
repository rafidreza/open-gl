#include<windows.h>
#include<cstdio>
#include<cmath>
#include<GL/glut.h>

using namespace std;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		25.0,25.0,-25.0,
	        0.0,0.0,0.0,
	        0.0,1.0,0.0
		);

	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0,1.0,1.0); //white
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
       glClearColor(0.0,0.0,0.0,0.0); // black color
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluPerspective(70,1,0.1,100.0);

}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (900,900);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("Hello 3D");
	init(); // init display modes
	glutDisplayFunc(display); // display update
	glutMainLoop();
	return 0;
}
