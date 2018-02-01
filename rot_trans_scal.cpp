#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
int hi=40,poly=4,x_=300,y_=300,iserase=0,xr,yr,rotat=0;
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
if(iserase==1)
{
    glColor3f(1,1,1);
}
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
float x1=0.5,y1=x1;
glVertex2f(x+hi*(x1)*cos(rotat),y+hi*(y1)*sin(rotat));
glVertex2f(x-hi*(x1)*sin(rotat),y+hi*(y1)*cos(rotat));
glVertex2f(x-hi*(x1)*cos(rotat),y-hi*(y1)*sin(rotat));
glVertex2f(x+hi*(x1)*sin(rotat),y-hi*(y1)*cos(rotat));
}
else
{
drawCircle(x,y,hi/2);
}
glEnd();
glColor3f(0,0,0);
glFlush();
}

void mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
{
float t=20;
int x1=x_,y1=y_;
for(int i=t-1;i>=0;i--)
{
iserase=1; display(x_,y_);
x_=x+(x1-x)*(i/t);
y_=y+(y1-y)*(i/t);
iserase=0; display(x_,y_);
for(int j=0;j<10000000;j++);
}
}
if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
{

}
if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
{
float t=20;
int x1=x_,y1=y_;
for(int i=t-1;i>=0;i--)
{
iserase=1; display(x_,y_);
x_=x+(x1-x)*(i/t);
iserase=0; display(x_,y_);
for(int j=0;j<10000000;j++);
}
for(int i=t-1;i>=0;i--)
{
iserase=1; display(x_,y_);
y_=y+(y1-y)*(i/t);
iserase=0; display(x_,y_);
for(int j=0;j<10000000;j++);
}
}
}

void keyboard(unsigned char a,int x,int y)
{
switch(a)
{
        case '+': iserase=1; display(x_,y_); iserase=0; if(hi<500) hi*=2;   display(x_,y_);                     break;
        case '-': iserase=1; display(x_,y_); iserase=0; if(hi>2) hi/=2;     display(x_,y_);                     break;
        case 'a': iserase=1; display(x_,y_); iserase=0; x_-=10;             display(x_,y_);                     break;
        case 's': iserase=1; display(x_,y_); iserase=0; y_+=10;             display(x_,y_);                     break;
        case 'd': iserase=1; display(x_,y_); iserase=0; x_+=10;             display(x_,y_);                     break;
        case 'w': iserase=1; display(x_,y_); iserase=0; y_-=10;             display(x_,y_);                     break;
        case 'r': iserase=1; display(x_,y_); iserase=0;rotat+=1;rotat%=360; display(x_,y_);                     break;
        case ' ': iserase=1; display(x_,y_); iserase=0; rotat=0;            display(x_,y_);                     break;
        default : glColor3f(0,0,0); poly=4; break;
}
}
void disp()
{
glColor3f(0,0,0);
display(x_,y_);
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
