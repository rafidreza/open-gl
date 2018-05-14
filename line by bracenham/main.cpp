#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void display(void)
{
float dy,dx,x,y,d,dT,dS;
x=x1;
y=y1;
dx=x2-x1;
dy=y2-y1;
d=(2*dy)-dx;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,0,0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

while(x<x2)
  {x++;
    if(d<0)

           d=d+dS;
           else
           {
            y++;
            d=d+dT;
           }

        glBegin(GL_POINTS);
        glVertex2i(x,y);
         glEnd();

    }




glFlush();
}

void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
gluOrtho2D(0.0,400.0,0.0,400.0);
}

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (5,50);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
