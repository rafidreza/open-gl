#include<windows.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>

float Dx,Dy,xi,yi,x,y;
int x1,x2,y1,y2,step,i;

void display()
{
    Dy = y2-y1;
    Dx = x2-x1;
    x=x1;
    y=y1;
    if(Dx>Dy)
    {
        step = Dx;
        xi = Dx/Dx;
        yi = Dy/Dx;
    }
    else
    {
        step = Dy;
        xi = 1/(Dy/Dx);
        yi = Dy/Dy;
    }
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    for(i=0;i<step;i++)
    {
        x = x+xi;
        y=y+yi;
        glVertex2d(x,y);
    }
    glEnd();
    glFlush();
}



void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,600);
}

int main(int argc, char** argv)
{
    printf("Enter start point");
    scanf("%d %d",&x1,&y1);

    printf("Enter end point");
    scanf("%d %d",&x2,&y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
