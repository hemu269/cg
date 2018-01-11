#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
int hi=0;
void init()
{

glClearColor(0,0,0,0);
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
void hello(float x,float y,float z)
{
glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(100*z+x,100*z+y);
glVertex2f(500*z+x,100*z+y);
glVertex2f(300*z+x,446.4*z+y);
glVertex2f(500*z+x,100*z+y);
glVertex2f(300*z+x,446.4*z+y);
glVertex2f(100*z+x,100*z+y);
glEnd();

float x1[5],y1[5];
x1[1]=100*z+x;
x1[2]=500*z+x;
x1[3]=300*z+x;
y1[1]=100*z+y;
y1[2]=100*z+y;
y1[3]=446.4*z+y;
y1[4]=250*z+x;
x1[4]=250*z+y;

glBegin(GL_POINTS);

for(int i=0,j;i<1000000;i++)
{
j=rand()%3+1;
x1[4]=(x1[j]+x1[4])/2;
y1[4]=(y1[j]+y1[4])/2;
/*
if(j==1)
{
glColor3f(1,0,0);
}
else if(j==2)
{
glColor3f(0,1,0);
}
else
{
glColor3f(0,0,1);
}*/
glColor3f(rand()%2,rand()%2,rand()%2);
glVertex2f(x1[4],y1[4]);

}
glEnd();


}

void disp()
{
hello(0,0,1);
hello(227,165,.24);
/*
for(float i=0;i<1600;i+=500)
{
for(float j=0;j<1600;j+=500)
hello(i,j);
}*/
glFlush();
}

int main(int argc,char **argv)
{
srand(time(NULL));
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(1080,780);
glutInitWindowPosition(30,30);
glutCreateWindow("text program");
init();
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
