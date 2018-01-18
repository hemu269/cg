#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
int hi=12,poly=3;
void init()
{
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,600);
}

const float DEG2RAD = 3.14159/180;
 
void drawCircle(float j,float k,float radius)
{
   glBegin(GL_POLYGON);
 
   for (int i=0; i < 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(j+cos(degInRad)*radius,k+sin(degInRad)*radius);
   }
 
   glEnd();
}
void display(int x,int y)
{
y=600-y;
glBegin(GL_POLYGON);
if(poly==3)
{
float x1=0,x2=0.5,x3=-0.5,y1=0.57735,y2=-0.28867,y3=-0.28867;
glVertex2f(x+hi*(x1),y+hi*(y1));
glVertex2f(x+hi*(x2),y+hi*(y2));
glVertex2f(x+hi*(x3),y+hi*(y3));
}
else if(poly==4)
{
float x1=0.35355,y1=x1;
glVertex2f(x+hi*(x1),y+hi*(y1));
glVertex2f(x+hi*(-1*x1),y+hi*(y1));
glVertex2f(x+hi*(-1*x1),y+hi*(-1*y1));
glVertex2f(x+hi*(x1),y+hi*(-1*y1));
}
else
{
drawCircle(x,y,hi/2);
}
glEnd();
glFlush();
}

void mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
{
display(x,y);
}
}

void keyboard(unsigned char a,int x,int y)
{
switch(a)
{
        case '+': if(hi<50) hi+=4; break;
        case '-': if(hi>8) hi-=4; break;
        case '3': poly=3; break;
        case '4': poly=4; break;
        case '5': poly=5; break;
        case 'r': glColor3f(1,0,0); break;
        case 'g': glColor3f(0,1,0); break;
        case 'b': glColor3f(0,0,1); break;
        default : glColor3f(0,0,0); poly=3; break;
}
}
void disp()
{
glColor3f(0,0,0);
glFlush();
}
int main(int argc,char **argv)
{
srand(time(NULL));
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(600,600);
glutInitWindowPosition(0,0);
glutCreateWindow("text program");
init();
glutDisplayFunc(disp);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
