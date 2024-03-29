#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#define pi (2*acos(0.0))
struct point
{
	double x,y,z;
};



void drawAxes()
{

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	
}


void drawGrid()
{
	int i;

		glColor3f(0.6, 0.6, 0.6);	//grey
		glBegin(GL_LINES);{
			for(i=-8;i<=8;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -90, 0);
				glVertex3f(i*10,  90, 0);

				//lines parallel to X-axis
				glVertex3f(-90, i*10, 0);
				glVertex3f( 90, i*10, 0);
			}
		}glEnd();
	
}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}

void drawBitlife(double a)
{
    
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	drawSquare(a);
	glPopMatrix(); 
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	drawSquare(a+1);
	glPopMatrix(); 

	
}


void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
        }
        glEnd();
    }
}


void draw_rec()
{
    glColor3f(0,1,0);
    //glRotatef(5*angle,0,0,1);
    //glTranslatef(incx,incy,0);
    //glRotatef(5*angle,0,0,1);
    drawSquare(10);

}

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * pi * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }

	glEnd();
}

void circleHead(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			glColor3f(i,i-1,i+1);
			angle = 2 * pi * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}
    }

	glEnd();
}

void hadoukenArt()
{
	//glRotatef(one.headOne.angle,0,0,1);
    circleHead(5,5);
}

void lifeMeter(int one,int two,int three,int four,int five)
{	
	if(five ==1)
	{
		glPushMatrix();
		glTranslatef(32,0,0);
		drawBitlife(3);
		glPopMatrix(); 
	}
	else
	{
		
	}
	if(four ==1)
	{
		glPushMatrix();
		glTranslatef(24,0,0);
		drawBitlife(3);
		glPopMatrix(); 
	}
	else
	{
		
	}
	if(three ==1)
	{
		glPushMatrix();
		glTranslatef(16,0,0);
		drawBitlife(3);
		glPopMatrix();
	}
	else
	{
		
	}
	if(two ==1)
	{
		glPushMatrix();
		glTranslatef(8,0,0);
		drawBitlife(3);
		glPopMatrix();
	}
	else
	{
		
	}
	if(one ==1)
	{
		drawBitlife(3);
	}
	else
	{
		
	}
	
}

void start()
{
	glPushMatrix();
	glTranslatef(80,-30,0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( 10, 20,2);
		glVertex3f( 10,-20,2);
		glVertex3f(-20,-10,2);
		glVertex3f(-20, 10,2);
	}glEnd();
	glPopMatrix(); 
}

