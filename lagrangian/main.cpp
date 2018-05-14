#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>

GLfloat x[10],f[10];
int n;
/* GLUT callback Handlers */



static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);
    int i,j;
    GLfloat mult,sum=0,a;
    a=x[0];
    glBegin(GL_POINTS);
    while(a<=x[n-1])
    {
        sum=0;
    for(i=0;i<=n-1;i++)
    {
    mult=1;
        for(j=0;j<=n-1;j++)
        {
            if(j!=i)
            mult*=(a-x[j])/(x[i]-x[j]);
        }
        sum+=mult*f[i];
    }
    glVertex2d(a,sum);
    a=a+0.05;
    }
    glEnd();

    //glutSwapBuffers();
    glFlush();
}


void init(){
 glClearColor(1.0,1.0,1.0,0);
 glColor3f(0.0,0.0,0.0);
 gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(150,150);
    glutCreateWindow("GLUT Shapes");
    init();
    int i;
    printf("Enter no of sample points ? ");
    scanf("%d",&n);
    printf("Enter all values of x and corresponding funtional value: ");
    for(i=0;i<n;i++)
        scanf("%f %f",&x[i],&f[i]);


   // glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
