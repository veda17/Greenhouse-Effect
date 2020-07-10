#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <MMsystem.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;
float e=0;
float cx=0;
float cy=0;
float angle=0;
float time1=0;
float time2=0;
float time3=0;
float time4=0;
char option11[]="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
char option12[]="BANGALORE INSTITUTE OF TECHNOLOGY";
char option13[]="Computer Graphics Laboratory with Mini Project";
char option0[]="GREENHOUSE EFFECT";
char option1[]="press W to know WHAT IS GREENHOUSE EFFECT";
char option2[]="press C to know THE CAUSES OF GREENHOUSE EFFECT";
char option3[]="press A to know HOW TO AVOID GREENHOUSE EFFECT";
char option4[]="press E to know THE IMPACTS OF GREENHOUSE EFFECT";
char option5[]="press Q to Quit";
char name1[]="G Vedashree : 1BI17CS053";
char name2[]="Shefali Shankar : 1BI17CS204";
char nm[]="Under the guidance of :";
char nm1[]="Presented by:";
char name3[]="Prof.K J Bhanushree";
char name4[]="Prof.Bhavana K V";
char a1[]="Cycling";
char a2[]="Aerosol Cylinders Emitting CFC";
char a3[]="Using Catalytic Converters";
char a4[]="Use Windmills";
char e1[]="Dying Fishes";
char f[]="Factories";
char f1[]="Burning of Fossil Fuels";
char def[]="Deforestation";
char af[]="Afforestation";
char v[]="Emissions from Vehicles";
char re1[]="REDUCE";
char re2[]="REUSE";
char re3[]="RECYCLE";
char ozone1[]="Ozone Hole";
char ozone2[]="Melting of Polar Ice Caps and Glaciers";
char e2[]="leading to a rise in sea level";
char text1[]="Suns Rays falling on the earth and ozone layer";
char text2[]="Ozone reflects some of the suns rays into space";
char text3[]="Atmosphere traps heat from the earth, keeping it warm";
//char h1[]="WHAT IS GREENHOUSE EFFECT";
char h2[]="PRESS C -> CAUSES OF GREENHOUSE EFFECT";
char h3[]="PRESS A -> HOW TO AVOID GREENHOUSE EFFECT";
char h4[]="PRESS E -> IMPACTS OF GREENHOUSE EFFECTS";
char h5[]="PRESS H -> HOME PAGE";
bool start=true;
bool what =false;
bool cause=false;
bool effect=false;
bool avoid=false;
char ozen[]="Ozone Layer";
float c=0;
//line 10//
float s=0.0;
float o=0.0;
float angle1=0.0;
float angle2=120.0;
float  angle3=240.0;

//before drawScene()//

void DrawPixel(GLint cx,GLint cy)
{
glBegin(GL_POINTS);
glVertex2i(cx,cy);
glEnd();
}

void PlotPixels(GLint h,GLint k, GLint x,GLint y)
{
DrawPixel(x+h,y+k);
DrawPixel(-x+h,y+k);
DrawPixel(x+h,-y+k);
DrawPixel(-x+h,-y+k);
DrawPixel(y+h,x+k);
DrawPixel(-y+h,x+k);
DrawPixel(y+h,-x+k);
DrawPixel(-y+h,-x+k);
}
void circle(GLint h,GLint k, GLint r)
{
GLint d=1-r,x=0,y=r;
while(y>x)
{
PlotPixels(h,k,x,y);
if(d<0) d+=2*x+3;
else
{
d+=2*(x-y)+5;
--y;
}
++x;
}
PlotPixels(h,k,x,y);
}


//Initializes 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w,int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
    switch( key )
    {

    case 'w':
        start=false;
        cause=false;
        effect=false;
        what=true;
        avoid=false;
        glutPostRedisplay();
        break;

    case 'c':
        start=false;
        cause=true;
        effect=false;
        what=false;
        avoid=false;
        glutPostRedisplay();
        break;


    case 'e':
        start=false;
        cause=false;
        effect=true;
        what=false;
        avoid=false;
        glutPostRedisplay();
        break;

    case 'a':
            start=false;
            cause=false;
            effect=false;
            what=false;
            avoid=true;
            glutPostRedisplay();
            break;
    case 'h':
        start=true;
        avoid=false;
        effect=false;
        cause=false;
        what=false;
        time1=0;
        time2=0;
        time3=0;
        time4=0;
        c=0;
        glutPostRedisplay();
        break;
    case 'q': exit(0);
    }
}

void print(float x, float y,float r, float g,float b, char *st)
{

    int l,i;

    l=strlen(st);//see how many characters are in the text string.
    glColor3f(r,g,b);
    //glEnable(GL_LIGHTING);
    glRasterPos2f(x, y);
    for(i=0;i<l;i++)
    {

        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void print1(float x, float y,float r, float g,float b, char *st)
{

    int l,i;

    l=strlen(st);//see how many characters are in the text string.
    glColor3f(r,g,b);
    //glEnable(GL_LIGHTING);
    glRasterPos2f(x, y);
    for(i=0;i<l;i++)
    {

        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
}

void drawCross(float x, float y)
{
    glPushMatrix();
    //glSingle(l,i,0);
    glTranslatef(x,y,0);
    glColor3f(1, 0, 0);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex3f(-.975,-.975,0);
    glVertex3f(-.85,-.75,0);
    glEnd();
    glLineWidth(1);
    glPopMatrix();
}

void drawTimber(float x,float y)
{

    glPushMatrix();
    glScalef(4,5,0);
    glTranslatef(x,y, 0.0);
    glColor3f(0.8235294118, 0.4117647059, 0.1176470588);
    glBegin(GL_POLYGON);

    glVertex3f(.0125,.01,0.0);
    glVertex3f(0.1,.00575,0.0);
    glVertex3f(.005,0.0,0.0);
    glVertex3f(.01,.0025,0.0);
    glVertex3f(.013,.00375,0.0);
    glVertex3f(.0175,.0025,0.0);
    glVertex3f(.0225,.0,0.0);
    glVertex3f(.02,.0025,0.0);
    glVertex3f(.01825,.007,0.0);
    glVertex3f(.0225,.0075,0.0);
    glVertex3f(.0225,.0075,0.0);
    glVertex3f(.0275,.005,0.0);
    glVertex3f(.03,.00425,0.0);
    glVertex3f(.0325,.005,0.0);
    glVertex3f(.03,.0065,0.0);
    glVertex3f(.0275,.01,0.0);
    glVertex3f(.0275,.0225,0.0);
    glVertex3f(.0125,.0225,0.0);
    glEnd();
    glPopMatrix();
}

void drawSmoke(float x,float y)
{
    glPushMatrix();
    glTranslatef(0.02+x, 0.6+y, 0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.07+x, 0.6+y, 0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
     glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.07+x, 0.65+y, 0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.052;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
     glEnd();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.0+x, 0.65+y, 0.0);
    glColor3f(0.247,0.196,0.199);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void drawSmoke1(float x,float y)
{
    glPushMatrix();
    glTranslatef(0.65+x, 0.7+y, 0.0);
    glColor3f(0.50, 0.50, 0.50);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.70+x, 0.7+y, 0.0);
    glColor3f(0.50, 0.50, 0.50);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
     glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.70+x, 0.75+y, 0.0);
    glColor3f(0.50, 0.50, 0.50);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.052;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
     glEnd();
    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.70+x, 0.75+y, 0.0);
    glColor3f(0.50, 0.50, 0.50);
    glBegin(GL_POLYGON);

    for(int i=0;i<600;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=0.05;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}


 void drawCar(float _angle,float d,float e)
 {

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-2.98+d, 0.55+e, 0.0);
     glRotatef(_angle, 0.0, 0.0, -1.0);
     glColor3f(0.10, 0.10, 0.10);
     glutSolidSphere(.10,40,25);
     glPopMatrix();

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-2.3+d, 0.55+e, 0.0);
     glRotatef(_angle, 0.0, 0.0, -1.0);
     glColor3f(0.10, 0.10, 0.10);
     glutSolidSphere(.10,40,5);
     glPopMatrix();

     //glass

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-0.40,0.35+e,0.0);
     glColor3f(0.40,0.40,0.40);
     glBegin(GL_POLYGON);
     glVertex3f(-1.77+d, 0.46, 0.0);
     glVertex3f(-1.87+d, 0.63, 0.0);
     glVertex3f(-2.04+d, 0.63, 0.0);
     glVertex3f(-2.04+d, 0.46, 0.0);
     glEnd();
     glPopMatrix();

     //Body

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-0.40,0.350+e,0.0);
     glColor3f(0.70, 0.70, 0.70);
     glBegin(GL_POLYGON);
     glVertex3f(-2.05+d, 0.15, 0.0);
     glVertex3f(-1.65+d, 0.15, 0.0);
     glVertex3f(-1.6+d, 0.20, 0.0);
      glVertex3f(-1.60+d, 0.28, 0.0);
     glVertex3f(-1.62+d, 0.28, 0.0);
    glVertex3f(-1.64+d, 0.40, 0.0);
     glVertex3f(-1.76+d, 0.48, 0.0);
     glVertex3f(-1.86+d, 0.64, 0.0);
     glVertex3f(-2.05+d, 0.64, 0.0);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-0.40,0.35+e,0.0);
     glColor3f(0.20, 0.20, 0.20);
     glBegin(GL_POLYGON);
     glVertex3f(-2.05+d, 0.74, 0.0);
     glVertex3f(-2.75+d, 0.74, 0.0);
     glVertex3f(-2.75+d, 0.14, 0.0);
     glVertex3f(-2.05+d, 0.14, 0.0);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glScalef(0.5,0.5,0);
     glTranslatef(-0.40,0.35+e,0.0);
     glColor3f(0.140, 0.140, 0.140);
     glBegin(GL_POLYGON);
     glVertex3f(-2.77+d, 0.19, 0.0);
     glVertex3f(-2.75+d, 0.19, 0.0);
     glVertex3f(-2.75+d, 0.19, 0.0);
     glVertex3f(-2.77+d, 0.19, 0.0);
     glEnd();
     glPopMatrix();
}


 void drawCar1(float _angle, float d, float e)
  {
      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-2.98+d, 0.55+e, 0.0);
      glRotatef(_angle, 0.0, 0.0, -1.0);
      glColor3f(0.10, 0.10, 0.10);
      glutSolidSphere(.10,40,25);
      glPopMatrix();

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-2.3+d, 0.55+e, 0.0);
      glRotatef(_angle, 0.0, 0.0, -1.0);
      glColor3f(0.10, 0.10, 0.10);
      glutSolidSphere(.10,40,5);
      glPopMatrix();

      //glass

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-0.40,0.35+e,0.0);
      glColor3f(0.40,0.40,0.40);
      glBegin(GL_POLYGON);
      glVertex3f(-1.77+d, 0.46, 0.0);
      glVertex3f(-1.87+d, 0.63, 0.0);
      glVertex3f(-2.04+d, 0.63, 0.0);
      glVertex3f(-2.04+d, 0.46, 0.0);
      glEnd();
      glPopMatrix();

      //Body

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-0.40,0.350+e,0.0);
      glColor3f(0.70, 0.70, 0.70);
      glBegin(GL_POLYGON);
      glVertex3f(-2.05+d, 0.15, 0.0);
      glVertex3f(-1.65+d, 0.15, 0.0);
      glVertex3f(-1.6+d, 0.20, 0.0);
       glVertex3f(-1.60+d, 0.28, 0.0);
      glVertex3f(-1.62+d, 0.28, 0.0);
     glVertex3f(-1.64+d, 0.40, 0.0);
      glVertex3f(-1.76+d, 0.48, 0.0);
      glVertex3f(-1.86+d, 0.64, 0.0);
      glVertex3f(-2.05+d, 0.64, 0.0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-0.40,0.35+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_POLYGON);
      glVertex3f(-2.05+d, 0.74, 0.0);
      glVertex3f(-2.75+d, 0.74, 0.0);
      glVertex3f(-2.75+d, 0.14, 0.0);
      glVertex3f(-2.05+d, 0.14, 0.0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-0.40,0.35+e,0.0);
      glColor3f(0.140, 0.140, 0.140);
      glBegin(GL_POLYGON);
      glVertex3f(-2.77+d, 0.19, 0.0);
      glVertex3f(-2.75+d, 0.19, 0.0);
      glVertex3f(-2.75+d, 0.19, 0.0);
      glVertex3f(-2.77+d, 0.19, 0.0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glScalef(0.1,0.1,0);
      glTranslatef(-3.7,-4.1+e,0.0);
      glColor3f(0.50, 0.50, 0.50);
      glBegin(GL_POLYGON);
      glVertex3f(-2.05+d, 0.74, 0.0);
      glVertex3f(-2.75+d, 0.74, 0.0);
      glVertex3f(-2.75+d, 0.14, 0.0);
      glVertex3f(-2.05+d, 0.14, 0.0);
      glEnd();
      glPopMatrix();


  }

 void drawCycle(float _angle, float d, float e)
  {
      //wheels
  glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-2.98+d, 0.55+e, 0.0);
      glRotatef(_angle, 0.0, 0.0, -1.0);
      glColor3f(0.10, 0.10, 0.10);
      glutWireSphere(.2,20,2);
      glPopMatrix();

      glPushMatrix();
      glScalef(0.5,0.5,0);
      glTranslatef(-2.3+d, 0.55+e, 0.0);
      glRotatef(_angle, 0.0, 0.0, -1.0);
      glColor3f(0.10, 0.10, 0.10);
      glutWireSphere(.2,20,2);
      glPopMatrix();
 //body
 glPushMatrix();
      glScalef(0.1,0.2,0);
      glTranslatef(-1.0,-1.2+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_LINE_LOOP);
      glVertex3f(-1.05+d, 0.74, 0.0);
      glVertex3f(-2.75+d, 0.74, 0.0);
      glVertex3f(-3.75+d, 0.14, 0.0);
      glVertex3f(-2.05+d, 0.14, 0.0);
      glEnd();
      glPopMatrix();

 glPushMatrix();
 glScalef(0.1,0.2,0);
 glTranslatef(0.2,-1.8+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_LINES);
      glVertex3f(-2.75+d, 2.5, 0.0);
      glVertex3f(-2.0+d, 0.74, 0.0);
       glEnd();
      glPopMatrix();

 glPushMatrix();
 glScalef(0.1,0.2,0);
 glTranslatef(-1.0,-1.8+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_LINES);
      glVertex3f(0.0+d, 2.5, 0.0);
      glVertex3f(-2.75+d, 2.5, 0.0);
       glEnd();
      glPopMatrix();

 glPushMatrix();
 glScalef(0.1,0.1,0);
 glTranslatef(-4.0,-2.15+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_LINES);
      glVertex3f(-0.5+d, 0.0, 0.0);
      glVertex3f(1.0+d,0.0,0.0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
 glScalef(0.1,0.1,0);
 glTranslatef(-3.75,-2.65+e,0.0);
      glColor3f(0.20, 0.20, 0.20);
      glBegin(GL_LINES);
      glVertex3f(0.0+d, -0.05, 0.0);
      glVertex3f(0.0+d,0.5,0.0);
      glEnd();
      glPopMatrix();

  }

  void windturbine()
{
glPushMatrix();
glScalef(3.5,3.5,0.0);
glTranslatef(-0.185,0.078,0.0);
glRotatef(angle1,0.0,0.0,1.0);
glTranslatef(-0.125,-0.600,0.0);
glBegin(GL_POLYGON);
glColor3f(0.764706,0.764706,0.764706);
glVertex2f(0.125,0.600);
glVertex2f(0.120,0.600);
glVertex2f(0.120,0.660);
glVertex2f(0.130,0.660);
glVertex2f(0.130,0.600);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(3.5,3.5,0.0);
glTranslatef(-0.185,0.078,0.0);
glRotatef(angle2,0.0,0.0,1.0);
glTranslatef(-0.125,-0.600,0.0);
glBegin(GL_POLYGON);
glColor3f(0.764706,0.764706,0.764706);
glVertex2f(0.125,0.600);
glVertex2f(0.120,0.600);
glVertex2f(0.120,0.660);
glVertex2f(0.130,0.660);
glVertex2f(0.130,0.600);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(3.5,3.5,0.0);
glTranslatef(-0.185,0.078,0.0);
glRotatef(angle3,0.0,0.0,1.0);
glTranslatef(-0.125,-0.600,0.0);
glBegin(GL_POLYGON);
glColor3f(0.764706,0.764706,0.764706);
glVertex2f(0.125,0.600);
glVertex2f(0.120,0.600);
glVertex2f(0.120,0.660);
glVertex2f(0.130,0.660);
glVertex2f(0.130,0.600);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);
glColor3f(0.498039,0.498039,0.498039);
glVertex2f(-0.620,0.250);
glVertex2f(-0.620,-0.180);
glVertex2f(-0.670,-0.180);
glVertex2f(-0.670,0.250);
glEnd();
glPopMatrix();
}


 void drawArrowHorizontal(float x,float y,float a,float b,float c)
  {
      glColor3f(a,b,c);
      glPushMatrix();
      glLineWidth(2.0);
      glTranslatef(x,y,0.0);

      glLineWidth(2.0);
      glBegin(GL_LINES);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(-0.22,0.0,0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f(-0.21,-0.05,0.0);
      glVertex3f(-0.22,0.0,0.0);
      glEnd();
      glBegin(GL_LINES);
      glVertex3f(-0.21,0.05,0.0);
      glVertex3f(-0.22,0.0,0.0);
      glEnd();
      glLineWidth(1.0);
      glPopMatrix();
  }



 void drawArrowIncoming(float x, float y, float a, float b, float c)
 {
     glColor3f(a,b,c);
     glPushMatrix();
     glPushMatrix();
     glTranslatef(x,y,0.0);

     glLineWidth(2.0);
     glBegin(GL_LINES);
     glVertex3f(-0.033,0.2,0.0);
     glVertex3f(0.12,0.1,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(0.055,0.1,0.0);
     glVertex3f(0.12,0.1,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(0.13,0.12,0.0);
     glVertex3f(0.12,0.1,0.0);
     glEnd();
     glPopMatrix();
 }

 void drawArrowOutgoing(float x, float y, float a, float b, float c)
 {
  glColor3f(a,b,c);
     glPushMatrix();
     glLineWidth(2.0);
     glTranslatef(x,y,0.0);

     glLineWidth(2.0);
     glBegin(GL_LINES);
     glVertex3f(0.07,0.1,0.0);
     glVertex3f(0.22,0.2,0.0);
     glEnd();
     glBegin(GL_LINES);
     //glBegin(GL_LINES);
     glVertex3f(0.15,0.18,0.0);
     glVertex3f(0.22,0.2,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(0.22,0.18,0.0);
     glVertex3f(0.22,0.2,0.0);
     glEnd();
     glLineWidth(1.0);
     glPopMatrix();

 }

 void drawArrowStraight(float x,float y,float a,float b,float c)
 {
     glColor3f(a,b,c);
     glPushMatrix();
     glLineWidth(2.0);
     glTranslatef(x,y,0.0);

     glLineWidth(2.0);
     glBegin(GL_LINES);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.0,0.15,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(-0.02,0.14,0.0);
     glVertex3f(0.0,0.15,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(0.02,0.14,0.0);
     glVertex3f(0.0,0.15,0.0);
     glEnd();
     glLineWidth(1.0);
     glPopMatrix();
 }

 void drawArrowDown(float x, float y, float a, float b, float c)
 {
     glColor3f(a,b,c);
     glPushMatrix();
     glLineWidth(2.0);
     glTranslatef(x,-y,0.0);

     glLineWidth(2.0);
     glBegin(GL_LINES);
     glVertex3f(0.0,0.0,0.0);
     glVertex3f(0.0,0.15,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(-0.02,0.01,0.0);
     glVertex3f(0.0,0.0,0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex3f(0.02,0.01,0.0);
     glVertex3f(0.0,0.0,0.0);
     glEnd();
     glLineWidth(1.0);
     glPopMatrix();
 }

 void drawCfc(float x, float y)
 {
     glPushMatrix();
     glScalef(7,7,0);
     glTranslatef(x,y, 0.0);
     glColor3f(0.432941176, 0.0, 0.0667);
     glBegin(GL_POLYGON);
     glVertex3f(0.0005,0.02125,0.0);
     glVertex3f(.0005,0.00125,0.0);
     glVertex3f(.0025,.00075,0.0);
     glVertex3f(.005,.0005,0.0);
     glVertex3f(.0075,.00125,0.0);
     glVertex3f(.0075,.02125,0.0);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glScalef(7,7,0);
     glTranslatef(x,y, 0.0);
     glColor3f(0.2509803922, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glVertex3f(0.000125,0.0225,0.0);
     glVertex3f(0.0005,0.02125,0.0);
     glVertex3f(0.0025,0.0205,0.0);
     glVertex3f(0.005,0.02,0.0);
     glVertex3f(0.0075,0.02025,0.0);
     glVertex3f(0.0075,.0225,0.0);
     glVertex3f(0.005,0.022,0.0);
     glVertex3f(0.0025,0.022,0.0);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glScalef(7,7,0);
     glTranslatef(x,y, 0.0);
     glColor3f(0.5019607843, 0.2509803922, 0.2509803922);
     glBegin(GL_POLYGON);
     glVertex3f(0.003,0.025,0.0);
     glVertex3f(0.00125,0.0225,0.0);
     glVertex3f(0.0025,0.022,0.0);
     glVertex3f(0.005,0.022,0.0);
     glVertex3f(0.0075,0.0225,0.0);
     glVertex3f(0.00725,.024,0.0);
     glVertex3f(0.00625,0.025,0.0);
     glVertex3f(0.0005,0.02375,0.0);
     glVertex3f(0.00375,0.024,0.0);
     glEnd();
     glPopMatrix();

     glPushMatrix();
     glScalef(7,7,0);
     glTranslatef(x,y, 0.0);
     glColor3f(0.5019607843, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glVertex3f(0.00375,0.02725,0.0);
     glVertex3f(0.003,0.025,0.0);
     glVertex3f(0.00375,0.024,0.0);
     glVertex3f(0.005,0.02375,0.0);
     glVertex3f(0.00625,0.025,0.0);
     glVertex3f(0.006,.0275,0.0);
     glVertex3f(0.00675,0.03,0.0);
     glVertex3f(0.00475,0.0295,0.0);
     glEnd();
     glPopMatrix();

 }

 void drawBrickFieldLeft(float x, float y)
 {
     glColor3f(0.6f,0.2f,0.0f);
     glPushMatrix();
     glTranslatef(x,y,0);
     glBegin(GL_POLYGON);
     glVertex3f(-.475,-.375,0);
     glVertex3f(-.5,-.5,0);
     glVertex3f(-.375,-.5,0);
     glVertex3f(-.4,-.375,0);
     glVertex3f(-.375,-.25,0);
     glVertex3f(-.5,-.25,0);
     glEnd();
     glPopMatrix();
 }

void drawBrickFieldRight(float x,float y)
{
     glColor3f(0.6f,0.2f,0.0f);
     glPushMatrix();
     glScalef(1.4,-1.3,0);
     glTranslatef(x-0.23,y,0);
     glBegin(GL_POLYGON);
     glVertex3f(-.475,-.375,0);
     glVertex3f(-.5,-.5,0);
     glVertex3f(-.375,-.5,0);
     glVertex3f(-.4,-.375,0);
     glVertex3f(-.375,-.25,0);
     glVertex3f(-.5,-.25,0);
     glEnd();
     glPopMatrix();
 }

void drawTree(float x, float y)
{
glPushMatrix();
glScalef(15,20,0);
glTranslatef(x,y,0.0);
glColor3f(0.5,0.35,0.05);
glBegin(GL_POLYGON);
glVertex3f(0.0,0.01425,0.0);
glVertex3f(-.00225,0.015,0.0);
glVertex3f(-.005,.0175,0.0);
glVertex3f(-.00675,.01675,0.0);
glVertex3f(-.0025,.01325,0.0);
glVertex3f(-.00025,.01,0.0);
glVertex3f(0,0,0.0);
glVertex3f(.0025,0.0,0.0);
glVertex3f(.00475,.0125,0.0);
glVertex3f(.005,.015,0.0);
glVertex3f(.009,.0225,0.0);
glVertex3f(.007,.02325,0.0);
glVertex3f(.00525,.01875,0.0);
glVertex3f(.0025,.015,0.0);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(20,20,0);
glTranslatef(x,y,0.0);
glColor3f(0.305,0.541,0.192);
glBegin(GL_POLYGON);
glVertex3f(-0.0105,0.02225,0.0);
glVertex3f(-0.0025,0.027,0.0);
glVertex3f(-0.014,0.02,0.0);
glVertex3f(-0.0025,0.027,0.0);
glVertex3f(-0.01425,0.0175,0.0);
glVertex3f(-0.001225,0.015,0.0);
glVertex3f(-0.00875,0.0155,0.0);
glVertex3f(-0.00475,0.01875,0.0);
glVertex3f(-0.00325,0.023,0.0);
glVertex3f(-0.0005,0.0195,0.0);
glVertex3f(0.00325,0.02,0.0);
glVertex3f(0.00525,0.0225,0.0);
glVertex3f(0.0065,0.024,0.0);
glVertex3f(0.01,0.023,0.0);
glVertex3f(0.0105,0.01925,0.0);
glVertex3f(0.01375,0.01875,0.0);
glVertex3f(0.0175,0.0225,0.0);
glVertex3f(0.01725,0.025,0.0);
glVertex3f(0.015,0.027,0.0);
glVertex3f(0.0125,0.0275,0.0);
glVertex3f(0.0105,0.0265,0.0);
glVertex3f(0.01,0.03,0.0);
glVertex3f(0.0075,0.0325,0.0);
glVertex3f(0.0025,0.03225,0.0);
glVertex3f(-0.00175,0.029,0.0);
glVertex3f(-0.0025,0.027,0.0);
glVertex3f(-0.0075,0.0275,0.0);
glVertex3f(-0.01,0.0265,0.0);
glVertex3f(-0.01125,0.025,0.0);
glEnd();
glPopMatrix();
}

void fish5 ()
{
 glColor3f (0.0,0.0,1.0); // blue fish
  glBegin (GL_POLYGON);
   glVertex2f (0.3-e, -0.5);
   glVertex2f (0.25-e, -0.55);
   glVertex2f (0.225-e, -0.55);
   glVertex2f (0.15-e, -0.5);
   glVertex2f (0.225-e, -0.45);
   glVertex2f (0.25-e, -0.45);
  glEnd ();

  glBegin (GL_TRIANGLES);
   glVertex2f (0.17-e, -0.5);
   glVertex2f (0.1-e, -0.54);
   glVertex2f (0.1-e, -0.46);
  glEnd ();

  glBegin (GL_TRIANGLES);
    glVertex2f (0.225-e, -0.45);
 glVertex2f (0.21-e, -0.375);
 glVertex2f (0.25-e, -0.45);
  glEnd ();

 glBegin (GL_TRIANGLES);
    glVertex2f (0.25-e, -0.55);
 glVertex2f (0.205-e, -0.6);
 glVertex2f (0.225-e, -0.55);
  glEnd ();

  glColor3f (0.0,0.0,0.0);
  glPointSize (4.0);
  glBegin (GL_POINTS);
  glVertex2f (0.27-e, -0.485);
  glEnd ();
}

void fish55 ()
{
 glColor3f (0.0,0.0,1.0); // blue fish
  glBegin (GL_POLYGON);
   glVertex2f (0.7, -0.25);
   glVertex2f (0.75, -0.3);
   glVertex2f (0.775, -0.3);
   glVertex2f (0.85, -0.25);
   glVertex2f (0.775, -0.2);
   glVertex2f (0.75, -0.2);
  glEnd ();

  glBegin (GL_TRIANGLES);
   glVertex2f (0.83, -0.25);
   glVertex2f (0.9, -0.29);
   glVertex2f (0.9, -0.21);
  glEnd ();

  glBegin (GL_TRIANGLES);
    glVertex2f (0.775, -0.2);
 glVertex2f (0.79, -0.125);
 glVertex2f (0.75, -0.2);
  glEnd ();

 glBegin (GL_TRIANGLES);
    glVertex2f (0.75, -0.3);
 glVertex2f (0.795, -0.35);
 glVertex2f (0.775, -0.3);
  glEnd ();

  glColor3f (0.0,0.0,0.0);
  glPointSize (4.0);
  glBegin (GL_POINTS);
  glVertex2f (0.73, -0.235);
  glEnd ();

}

void fish6 ()
{
 glColor3f (0.0,0.0,1.0); // blue fish
  glBegin (GL_POLYGON);
   glVertex2f (0.5, -0.375);
   glVertex2f (0.55, -0.425);
   glVertex2f (0.575, -0.425);
   glVertex2f (0.65, -0.375);
   glVertex2f (0.575, -0.325);
   glVertex2f (0.55, -0.325);
  glEnd ();

  glBegin (GL_TRIANGLES);
   glVertex2f (0.63, -0.375);
   glVertex2f (0.7, -0.415);
   glVertex2f (0.7, -0.335);
  glEnd ();

  glBegin (GL_TRIANGLES);
    glVertex2f (0.575, -0.325);
 glVertex2f (0.59, -0.25);
 glVertex2f (0.55, -0.325);
  glEnd ();

 glBegin (GL_TRIANGLES);
    glVertex2f (0.55, -0.425);
 glVertex2f (0.595, -0.475);
 glVertex2f (0.575, -0.425);
  glEnd ();

  glColor3f (0.0,0.0,0.0);
  glPointSize (4.0);
  glBegin (GL_POINTS);
  glVertex2f (0.53, -0.36);
  glEnd ();

}

void drawCloud(float x,float y)
{
glPushMatrix();
glTranslatef(0.0+x,0.6+y,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(0.08+x, 0.6+y,0.0);
glColor3f(1.0,1.0,1.0);


glBegin(GL_POLYGON);
for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();


glPushMatrix();
glTranslatef(0.15+x, 0.6+y,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0+x, 0.65+y,0.0);
glColor3f(1.0,1.0,1.0);


glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.08+x, 0.65+y,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.15+x, 0.65+y,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.06+x, 0.62+y,0.0);
glColor3f(1.0,1.0,1.0);
//line670
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.19+x, 0.62+y,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.05;
float x= r * cos(A);
float y= r * sin(A);
glVertex2f(x,y );
}
glEnd();
glPopMatrix();

}

void Sun(){
glPushMatrix();
glTranslatef(-0.9,0.9,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.2;
float x=r*cos(A);
float y=r*sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}

void drawEllipse(float radiusX, float radiusY, float a, float b, float c) {
glPushMatrix();
int i;
glTranslatef(a,b,c);
glColor3f(0.45,0.45,1.0);
glBegin(GL_POLYGON);

for(i=0; i<360; i++) {
float rad = i*3.1416/180;
glVertex2f(cos(rad)*radiusX,
          sin(rad)*radiusY);
}

glEnd();

glPopMatrix();

}

//line702
void drawScene()
{
glClearColor(0.45,0.45,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);

float _angle=0;
float d=2.5;
float e=-1.8;

if(start){
//glClearColor(0.0,0.45,0.66,0.0);
glClearColor(0.75,0.75,0.75,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
print1(-.6,.8,0.0,0.0,0.0,option12);
print1(-.75,.7,0.0,0.0,0.0,option11);
print1(-.6,.6,0.0,0.0,0.0,option13);
print1(-.3,.4,0.0,0.0,0.0,option0);
print1(-.7,.2,0.0,0.0,0.0,option1);
print1(-.7,.1,0.0,0.0,0.0,option2);
print1(-.7,.0,0.0,0.0,0.0,option4);
print1(-.7,-0.1,0.0,0.0,0.0,option3);
print1(-.7,-0.2,0.0,0.0,0.0,option5);
print1(-0.9,-0.6,0.0,0.0,0.0,nm1);
print1(-0.9,-.7,0.0,0.0,0.0,name1);
print1(-0.9,-.8,0.0,0.0,0.0,name2);
print1(0.3,-0.6,0.0,0.0,0.0,nm);
print1(0.3,-0.7,0.0,0.0,0.0,name3);
print1(0.3,-0.8,0.0,0.0,0.0,name4);
}

else if(what){
mciSendString("play para1.way",NULL,0,NULL);

////sun////
Sun();
drawCloud(-0.4,0.2);
drawCloud(0.6,0.2);

//clouds//
//drawCloud(1,0);
//drawCloud(-.1,-.04);
print(.6,.6,0.0,0.0,0.0,ozen);
if (time1>0 && time1<3000)
{
//print1(-.4,0.0,0.0,0.0,0.0,h1);
}
if(time1<4000)
{

drawArrowIncoming(-.9+cx,.8+cy,1,0,0);
drawArrowIncoming(-.9+cx/2,.8+cy,1,0,0);
drawArrowIncoming(-.9+cx/5,.8+cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text1);

}

else if(time1>4000 && time1<6000)
{
drawArrowIncoming(-.9+cx,.8+cy,.603,.27,.603);
print(-.5,-.4,0.0,0.0,0.0,text1);
}

else if(time1>6000 && time1<7000)
{
drawArrowOutgoing(-.6+cx,.45+cy,.603,.27,.603);
print(-.5,-.4,0.0,0.0,0.0,text2);
}

else if(time1>7000 && time1<8000)
{
drawArrowIncoming(-.9+cx,.8+cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text2);
}

else if(time1>8000 && time1<10000)
{
drawArrowStraight(cx,cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text3);
}
else if(time1>10000 && time1<12000)
{
drawArrowIncoming(-.9+cx,.8+cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text3);
}

else if(time1>12000 && time1<15000)
{
drawArrowStraight(cx,cy,1,0,0);
drawArrowStraight(-.05+cx,cy,1,0,0);
drawArrowStraight(.05+cx,cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text3);
}

else if(time1>15000 && time1<20000)
{
drawArrowDown(cx,-.4+cy,1,0,0);
drawArrowDown(-.05+cx,-.4+cy,1,0,0);
drawArrowDown(.05+cx,-.4+cy,1,0,0);
print(-.5,-.4,0.0,0.0,0.0,text3);
}



if(time1>22000)
{
mciSendString("stop para1.way",NULL,0,NULL);
start=false;
cause=true;
effect=false;
what=false;
avoid=false;
glutPostRedisplay();

}

//atmosphere//
for(float r=2.0;r<=2.2;r+=.01){
glPushMatrix();
glPointSize(2.0);
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.752,0.752,0.752);
glBegin(GL_LINE_STRIP);
for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.2;
float x=r*cos(A);
float y=r*sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}

//earth//
glPushMatrix();
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=1.7;
float x=r * cos(A);
float y=r * sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

print(.6,.6,0.0,0.0,0.0,ozen);

}

else if(cause){

mciSendString("stop para1.way",NULL,0,NULL);
mciSendString("stop para3.way",NULL,0,NULL);

print(.6,.6,0.0,0.0,0.0,ozen);

//sun//
Sun();


//clouds//
drawCloud(-0.4,0.2);
drawCloud(0.6,0.2);

if(time2>0){
mciSendString("play para2.way",NULL,0,NULL);
print(.6,.6,0.0,0.0,0.0,ozen);
}
if(time2>0 && time2<2000){
print1(-.4,0.0,0.0,0.0,0.0,h2);
print1(-.4,-0.1,0.0,0.0,0.0,h5);
//drawTimber(-0.130,-0.02);


}

/*if(time2>700){
//drawTimber(-.150,-.01);
drawTree(-.015,-0.01);
drawTree(-0.025,-.005);
}*/

if(time2>3000){
drawTree(-.015,-0.01);
drawTree(-0.025,-.005);
//drawTimber(-.170,-.02);
}

if(time2>3200){
drawTimber(-.170,-.02);
drawTimber(-0.150,-0.04);
}
//if(time2>1200){
//drawTimber(-0.115,-0.04);
//}
if(time2>3500){
drawTimber(-.185,-.04);
print(-.5,-.3,0.0,0.0,0.0,def);
}

if(time2>5000){
drawCfc(.01,0);
drawCfc(.02,0);
print(-.1,-.1,0.0,0.0,0.0,a2);
}

if(time2>7000 ){
drawCar(_angle,d,e);
print(-.3,-.8,0.0,0.0,0.0,v);
}
if(time2>8500 && time2<12000){
drawSmoke(-.45,-1.2+c);
}

if(time2>12000){
drawSmoke(-.45,-1.2);

}

if(time2>10000){
drawBrickFieldLeft(1,.2);
print(.6,-.5,0.0,0.0,0.0,f);
}

if(time2>10000){
drawBrickFieldRight(1.2,0.55);
print(.5,-.55,0.0,0.0,0.0,f1);
}
if(time2>10000 && time2<12000){
drawSmoke(.5,-.55+c);
drawSmoke(.6,-.4+c);
drawSmoke(.7,-.55+c);
//drawSmoke(.75,-.25);
}

if(time2>12000){
drawSmoke(.5,-.55);
drawSmoke(.6,-.4);
drawSmoke(.7,-.55);
//drawSmoke(.75,-.25);

}



if(time2>16500){


mciSendString("stop para1.way",NULL,0,NULL);
mciSendString("stop para2.way",NULL,0,NULL);
mciSendString("stop para3.way",NULL,0,NULL);
start=false;
cause=false;
effect=true;
what=false;
avoid=false;
glutPostRedisplay();


}

//atmosphere//
for(float r=2.0;r<=2.2;r+=.01){
glPushMatrix();
glPointSize(2.0);
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.752,0.752,0.752);
glBegin(GL_LINE_STRIP);
for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.2;
float x=r*cos(A);
float y=r*sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}

//earth//
glPushMatrix();
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=1.7;
float x=r * cos(A);
float y=r * sin(A);
glVertex2f(x,y);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}


else if(effect){

mciSendString("stop para1.way",NULL,0,NULL);
mciSendString("stop para3.way",NULL,0,NULL);

print(.6,.6,0.0,0.0,0.0,ozen);

//sun//
Sun();


//clouds//
drawCloud(-0.4,0.2);
drawCloud(0.6,0.2);
//drawCloud(0.4,0.15);

if(time4>0 && time4<2000)
{
print1(-.4,0.0,0.0,0.0,0.0,h4);
print1(-.4,-0.1,0.0,0.0,0.0,h5);
}


if(time4>3500){
//middle ozone hole
drawEllipse(0.1, 0.05,0.0,0.6,0.0);
//left ozone hole
drawEllipse(0.06,0.06,-0.6,0.5,0.0);
//right ozone hole1
//drawEllipse(0.08,0.06,0.6,0.5,0.0);
//right ozone hole2
drawEllipse(0.15,0.08,0.8,0.4,0.0);
print(-0.1,0.5,0.0,0.0,0.0,ozone1);

}
if(time4>5000){

//Mountains
glPushMatrix();
glTranslatef(-0.4,-0.4,0.0);
//glColor3f(0.50196,0.25098,0.0);
glBegin(GL_POLYGON);
glColor3f(0.95686,0.54901,0.25882);
glVertex2f(-0.700,0.250);
glColor3f(1.0,1.0,1.0);
glVertex2f(-0.450,0.850);
glColor3f(0.50196,0.25098,0.0);
glVertex2f(-0.145,0.250);
glEnd();

//glColor3f(0.50196,0.25098,0.0);
glBegin(GL_POLYGON);
glVertex2f(-0.400,0.250);
glColor3f(1.0,1.0,1.0);
glVertex2f(-0.100,0.750);
glColor3f(0.50196,0.25098,0.0);
glVertex2f(0.100,0.250);
glEnd();


//glColor3f(0.50196,0.25098,0.0);
glBegin(GL_POLYGON);
glVertex2f(-0.090,0.250);
glColor3f(1.0,1.0,1.0);
glVertex2f(0.400,0.550);
glColor3f(1.0,1.0,1.0);
glVertex2f(0.700,0.250);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.50196,0.25098,0.0);
glVertex2f(-0.200,0.250);
glColor3f(1.0,1.0,1.0);
glVertex2f(0.100,0.750);
glColor3f(0.50196,0.25098,0.0);
glVertex2f(0.400,0.250);
glEnd();

glPopMatrix();

print(-0.8,-0.3,0.0,0.0,0.0,ozone2);
print(-0.8,-0.35,0.0,0.0,0.0,e2);
}
if(time4>6000)
{
    fish5();
    fish55();
    fish6();
    print(0.3,-0.8,0.0,0.0,0.0,e1);
}
if(time4>9500){
drawArrowIncoming(-.9+cx,.8+cy,1,0,0);
drawArrowIncoming(-.9+cx/2,.8+cy,1,0,0);
drawArrowIncoming(-.9+cx/5,.8+cy,1,0,0);

print(-0.7,.7,0.0,0.0,0.0,text1);
}

else if(time4>13000 && time4<16000)
{
drawArrowIncoming(-.9+cx,.8+cy,.603,.27,.603);
print(-.5,-.4,0.0,0.0,0.0,text1);
}


if(time4>20000){

mciSendString("stop para1.way",NULL,0,NULL);
mciSendString("stop para2.way",NULL,0,NULL);
mciSendString("stop para3.way",NULL,0,NULL);
start=false;
cause=false;
effect=false;
what=false;
avoid=true;
glutPostRedisplay();

}

//atmosphere//
for(float r=2.0;r<=2.2;r+=.01){
glPushMatrix();
glPointSize(2.0);
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.752,0.752,0.752);
glBegin(GL_LINE_STRIP);
for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=0.2;
float x=r*cos(A);
float y=r*sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}



//earth//
glPushMatrix();
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.50,0.80,0.90);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=1.7;
float x=r * cos(A);
float y=r * sin(A);
glVertex2f(x,y);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();

}



if(avoid){
mciSendString("stop para1.way",NULL,0,NULL);
mciSendString("stop para2.way",NULL,0,NULL);
print(.6,.6,0.0,0.0,0.0,ozen);
Sun();
drawCloud(-0.4,0.2);
drawCloud(0.6,0.2);

//sun//


//clouds//



mciSendString("play para3.way",NULL,0,NULL);




//if(time2>0){
//mciSendString("play para2.way",NULL,0,NULL);
//drawTimber(-0.130,-0.02);
//}

/*if(time2>300){
drawTree(-.015,-0.01);
}

if(time2>400){
drawTree(-0.025,-.005);
}*/
if(time3>0 && time3<2000){
print1(-.4,0.0,0.0,0.0,0.0,h3);
print1(-.4,-0.1,0.0,0.0,0.0,h5);
}


//if(time3>700){

//drawTimber(-.170,-.02);
//drawTimber(-.150,-.01);
//}


//if(time2>1200){
//drawTimber(-0.115,-0.04);
//}

if(time3>4000 && time3<10000){
//glEnable(GL_LIGHTING);
drawTree(-.014,-0.01);
drawTree(-0.028,-.005);
drawTree(-.039,-.005);
}

if(time3>4500 && time3<10000){
//drawTimber(-.185,-.04);
print(-.6,-.3,0.0,0.0,0.0,af);
}

if(time3>5500 && time3<10000){
//drawTree(-.045,-.026);
//drawTimber(-0.150,-0.04);

drawArrowIncoming(0.6,-0.20,0.184314,0.309804,0.184314);
drawArrowHorizontal(0.65,-0.20,0.184314,0.309804,0.184314);
drawArrowOutgoing(0.28,-0.20,0.184314,0.309804,0.184314);

print(.5,-0.075,0.0,0.0,0.0,re1);
print(.5,-0.125,0.0,0.0,0.0,re2);
print(.5,-0.175,0.0,0.0,0.0,re3);
}

if(time3>6500 && time3<10000){
    drawCycle(_angle,d,e);
    print(-.1,-.8,0.0,0.0,0.0,a1);
}

if(time3>10500){
if((int)time3%500<200)
{
drawCross(1.05,1);
}
drawCfc(.01,0);
drawCfc(.02,0);
print(-.3,-.1,0.0,0.0,0.0,a2);
windturbine();
print(-.75,-.3,0.0,0.0,0.0,a4);
}


if(time3>13500){
if((int)time3%500<200)
{
drawCross(1.5,.7);
//drawCross(1.6,.8);
drawCross(1.65,.65);
}

}
//line 1097
if(time3>14000){
drawCar1(_angle,d,e);
}
if(time3>14500){
drawSmoke1(-1.18,-1.2);
print(-.3,-.8,0.0,0.0,0.0,a3);
}



if(time3>13500){
drawBrickFieldLeft(1,.2);
print(-.3,-.1,0.0,0.0,0.0,a2);
}

if(time3>13500){
drawBrickFieldRight(1.2,0.55);
//print(.4,-.4,0.0,0.0,0.0,f1);
print(.6,-.5,0.0,0.0,0.0,f);
print(.5,-.55,0.0,0.0,0.0,f1);

if(time3>14000){
drawSmoke(.5,-.55);
drawSmoke(.6,-.4);
drawSmoke(.7,-.55);
//drawSmoke(.75,-.25);
}
}



if(time3>25000)
{
    start=true;
    avoid=false;
    effect=false;
    cause=false;
    what=false;
    time1=0;
    time2=0;
    time3=0;
    time4=0;
    c=0;
    glutPostRedisplay();
//mciSendString("stop para3.way",NULL,0,NULL);
}



//earth//
glPushMatrix();
glTranslatef(0.0,-1.5,0.0);

glColor3f(0.0,1.0,0.0);
glBegin(GL_POLYGON);

for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float r=1.7;
float x=r * cos(A);
float y=r * sin(A);
glVertex2f(x,y);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}

//atmosphere//
for(float r=2.0;r<=2.2;r+=.01){
glPushMatrix();
glPointSize(2.0);
glTranslatef(0.0,-1.5,0.0);
glColor3f(0.752,0.752,0.752);
glBegin(GL_LINE_STRIP);
for(int i=0;i<600;i++)
{
float pi=3.1416;
float A=(i*2*pi)/100;
float x=r*cos(A);
float y=r*sin(A);
glVertex2f(x,y);
}
glEnd();
glPopMatrix();
}



glutSwapBuffers();

}

void update(int value){
if(what){
time1+=25;

if(time1<4000){
cx+=.01;
cy-=.01;
angle=300;
if(cy<-0.7)
{
cx=0;
cy=0;
}
if(time1>3800)
{
cx=0;
cy=0;
}
}
else if(time1>4000 && time1<6000){
cx+=.01;
cy-=.01;
if(cy<-0.3){
cx=0;
cy=0;
}
if(time1>5900)
{
cx=0;
cy=0;
}
}
else if(time1>6000 && time1<7000){
cx+=.01;
cy+=.01;
if(cy>0.2)
{
cx=0;
cy=0;
}
if(time1>6900)
{
    cx=0;
    cy=0;
}
}
else if(time1>7000 && time1<8000){
cx+=.01;
cy-=.01;
angle=300;
if(cy<-0.7)
{
cx=0;
cy=0;
}
if(time1>7900)
{
cx=0;
       cy=0;
}
}

else if(time1>8000 && time1<10000){
//cx+=.01;
cy+=.01;
if(cy>0.3)
{
cx=0;
cy=0;
}
if(time1>9900)
{
cx=0;
cy=0;
}
}
else if(time1>10000 && time1<12000){
cx+=.01;
cy+=.01;
angle=300;
if(cy<-0.7)
{
cx=0;
cy=0;

}
if(time1>11900)
{
cx=0;
cy=0;
}

}
else if(time1>12000 && time1<15000){
//cx+=.01;
cy+=.01;
if(cy>0.3)
{
cx=0;
cy=0;
}
if(time1>14900)
{
cx=0;
cy=0;
}
}

else if(time1>15000 && time1<24000){
//cx+=.01;
cy+=.01;
if(cy>0.3)
{
cx=0;
cy=0;
}
if(time1>23900)
{
cx=0;
cy=0;
}
}

}

if(cause)
{
time2+=25;
if(time2>6000)
{
c+=.001;
}
}

if(effect)
{
time4+=25;
if(time4>2000)
{
c+=.001;
}
if(time4<12000){
cx+=.01;
cy-=.01;
angle=300;
if(cy<-0.7)
{
cx=0;
cy=0;
}
if(time4>11800)
{
cx=0;
cy=0;
}
}
else if(time4>12000 && time4<14000){
cx+=.01;
cy-=.01;
if(cy<-0.3){
cx=0;
cy=0;
}
if(time4>13900)
{
cx=0;
cy=0;
}
}
}
if(avoid)
{
angle1-=0.5;
angle2-=0.5;
angle3-=0.5;
time3+=25;
}

glutPostRedisplay(); //tell glut that display has changed

//Tell GLUT to call update again in 25 milliseconds
glutTimerFunc(25,update,0);

}

int main(int argc, char** argv){

//Initialize GLUT
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(800,800);

//Create Window
glutCreateWindow("Green House Effect");
initRendering();

//Set handler functions
glutDisplayFunc(drawScene);
glutReshapeFunc(handleResize);

glutKeyboardFunc(NormalKey);

glutTimerFunc(25,update,0); //Add a timer

glutMainLoop();
return 0;

}


