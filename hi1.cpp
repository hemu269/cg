#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
void init()
{

glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,700,0,700);
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


void disp()
{
glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(100,50);
glVertex2f(450,50);
glVertex2f(450,300);
glVertex2f(100,300);
glEnd();
glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2f(250,550);
glVertex2f(500,300);
glVertex2f(50,300);
glEnd();
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(150,125);
glVertex2f(180,125);
glVertex2f(180,200);
glVertex2f(150,200);
glEnd();
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(370,125);
glVertex2f(400,125);
glVertex2f(400,200);
glVertex2f(370,200);
glEnd();
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(235,100);
glVertex2f(315,100);
glVertex2f(315,250);
glVertex2f(235,250);
glEnd();

glColor3f(1,1,0);
drawCircle(50,450,20);
glColor3f(0,1,0);
drawCircle(275,200,20);
glBegin(GL_LINES);
for(int i=-2;i<3;i++)
{
glVertex2f(275+i,200);
glVertex2f(275+i,125);
}
for(int i=-1,j=-40;i<2;i++)
{
glVertex2f(275+i,165+i);
glVertex2f(260+i,150+i);
glVertex2f(275+i,165+i);
glVertex2f(290+i,150+i);
glVertex2f(275+i,165+i+j);
glVertex2f(260+i,150+i+j);
glVertex2f(275+i,165+i+j);
glVertex2f(290+i,150+i+j);
}

glEnd();

glColor3f(1,0,1);
int k=300;
drawCircle(k+275,200,20);
glBegin(GL_LINES);
for(int i=-2;i<3;i++)
{
glVertex2f(k+275+i,200);
glVertex2f(k+275+i,125);
}
for(int i=-1,j=-40;i<2;i++)
{
glVertex2f(k+275+i,175+i);
glVertex2f(k+260+i,150+i);
glVertex2f(k+275+i,175+i);
glVertex2f(k+290+i,150+i);
glVertex2f(k+275+i,175+i+j);
glVertex2f(k+260+i,150+i+j);
glVertex2f(k+275+i,175+i+j);
glVertex2f(k+290+i,150+i+j);
}

glEnd();

glColor3f(0,0,1);
k=350;
drawCircle(k+275,200,20);
glBegin(GL_LINES);
for(int i=-2;i<3;i++)
{
glVertex2f(k+275+i,200);
glVertex2f(k+275+i,125);
}
for(int i=-1,j=-40;i<2;i++)
{
glVertex2f(k+275+i,175+i);
glVertex2f(k+260+i,150+i);
glVertex2f(k+275+i,175+i);
glVertex2f(k+290+i,150+i);
glVertex2f(k+275+i,175+i+j);
glVertex2f(k+260+i,150+i+j);
glVertex2f(k+275+i,175+i+j);
glVertex2f(k+290+i,150+i+j);
}

glEnd();



glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("text program");
init();
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
