#include<windows.h>
#include<cstdio>
#include<cmath>
#include<GL/glut.h>
#include<stdio.h>
int h,k,r;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    double x=0;
    double y=r;
    double d=3-(2*r);
    while(x<=y)
    {
        glBegin(GL_POINTS);
            glColor3f(1.0,1.0,1.0);
            glVertex2d(x+h,y+k);
            glVertex2d(-x+h,-y+k);
            glVertex2d(-x+h,y+k);
            glVertex2d(x+h,-y+k);
            glVertex2d(y+h,x+k);
            glVertex2d(-y+h,x+k);
            glVertex2d(y+h,-x+k);
            glVertex2d(-y+h,-x+k);
       glEnd();

      if(d<0)
      {
          d=d+(4*x)+6;
          x=x+1;
      }
      else
      {
          d=d+4*(x-y)+10;
          x=x+1;
          y=y-1;
      }

    glFlush();
}
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
   glOrtho(-200,200,-200,200,-200,200);
}


int main(int argc, char** argv)
{
    printf("Enter the initial values: ");
    scanf("%d%d",&h,&k);
      printf("Enter the RADIUS: ");
    scanf("%d",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CIRCLE");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
