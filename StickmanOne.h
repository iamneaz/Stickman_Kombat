#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "Stickman.h"

stickman one;

void initializeStickmanOne()
{
    one.headRadius=10;
    one.headSegments = 20;
    one.headTranslate.x = 0;
    one.headTranslate.y = 60;

    //------------------------>body
    one.bodyDown.x=0;
    one.bodyDown.y=25;
    one.bodyTranslate.x = 0;
    one.bodyTranslate.y = 0;

    //------------------------>armOne
    one.armOne.top.x = 0;
    one.armOne.top.y = 45;
    one.armOne.middle.x = -15;
    one.armOne.middle.y = 30;
    one.armOne.bottom.x = -5;
    one.armOne.bottom.y = 20;
    
    //----------->handOne
    one.handOne.radius.x=2;
    one.handOne.radius.y=one.handOne.radius.x+2;
    one.handOne.translate.x = one.armOne.bottom.x;
    one.handOne.translate.y = one.armOne.bottom.y;
    one.handOne.angle=-45;

    //------------------------>armTwo
    one.armTwo.top.x = 0;
    one.armTwo.top.y = 45;
    one.armTwo.middle.x = 15;
    one.armTwo.middle.y = 30;
    one.armTwo.bottom.x = 20;
    one.armTwo.bottom.y = 40;
    
    //----------->handTwo
    one.handTwo.radius.x=2;
    one.handTwo.radius.y=one.handTwo.radius.x+2;
    one.handTwo.translate.x = one.armTwo.bottom.x;
    one.handTwo.translate.y = one.armTwo.bottom.y;
    one.handTwo.angle=-90;


    //----------------------------->leg One
    one.legOne.top.x=one.bodyDown.x;
    one.legOne.top.y=one.bodyDown.y;
    one.legOne.middle.x=-5;
    one.legOne.middle.y=10;
    one.legOne.bottom.x=-15;
    one.legOne.bottom.y=0;

    //----------->foot One
    one.footOne.radius.x=2;
    one.footOne.radius.y=one.footOne.radius.x+3;
    one.footOne.translate.x = one.legOne.bottom.x+2;
    one.footOne.translate.y = one.legOne.bottom.y;
    one.footOne.angle=-90;

    //----------------------------->leg Two
    one.legTwo.top.x=one.bodyDown.x;
    one.legTwo.top.y=one.bodyDown.y;
    one.legTwo.middle.x=10;
    one.legTwo.middle.y=14;
    one.legTwo.bottom.x=8;
    one.legTwo.bottom.y=0;

    //----------->foot Two
    one.footTwo.radius.x=2;
    one.footTwo.radius.y=one.footTwo.radius.x+3;
    one.footTwo.translate.x = one.legTwo.bottom.x+2;
    one.footTwo.translate.y = one.legTwo.bottom.y;
    one.footTwo.angle=-90;
    
}

void head()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.headTranslate.x,one.headTranslate.y,0);
    drawCircle(one.headRadius,one.headSegments);
	glPopMatrix();
}

void handOne()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.handOne.translate.x,one.handOne.translate.y,0);
    glRotatef(one.handOne.angle, 0, 0, 1);
    circle(one.handOne.radius.x,one.handOne.radius.y);
	glPopMatrix();
}

void armOne()
{
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( one.armOne.top.x, one.armOne.top.y,0);
			glVertex3f( one.armOne.middle.x,one.armOne.middle.y,0);
			glVertex3f( one.armOne.middle.x,one.armOne.middle.y,0);
			glVertex3f( one.armOne.bottom.x,one.armOne.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();

    //area

    glPushMatrix();
    
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(one.armOne.top.x-5, one.armOne.top.y);   
                glVertex2f(one.armOne.top.x+5, one.armOne.top.y); 
                glVertex2f(one.armOne.middle.x+3, one.armOne.middle.y); 
                glVertex2f(one.armOne.middle.x-3, one.armOne.middle.y);
                
                glVertex2f(one.armOne.bottom.x+2, one.armOne.bottom.y);
                glVertex2f(one.armOne.bottom.x-2, one.armOne.bottom.y);
                glVertex2f(one.armOne.middle.x-3, one.armOne.middle.y);
                glVertex2f(one.armOne.middle.x+3, one.armOne.middle.y); 
                          
    glEnd();
	glPopMatrix();
}

void body()
{
    //line
    glPushMatrix(); 
		glTranslatef(one.headTranslate.x,one.headTranslate.y-60,0);
        
		glBegin(GL_LINES);{				
			glColor3f(0.0, 1.0, 0.0);
            glVertex2f( 0, 50);
			glVertex2f( one.bodyDown.x,one.bodyDown.y);	
		}glEnd();
    glPopMatrix();

    // area
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0,0,0);
    glBegin(GL_POLYGON);
                glVertex2f(-5, 25);   // bottom
                glVertex2f(-15, 50); // top
                glVertex2f(10, 45); // top
                glVertex2f(4, 25); // bottom
                
    glEnd();
	glPopMatrix();
}

void handTwo()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.handTwo.translate.x,one.handTwo.translate.y,0);
    glRotatef(one.handTwo.angle, 0, 0, 1);
    circle(one.handTwo.radius.x,one.handTwo.radius.y);
	glPopMatrix();

}

void armTwo()
{
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( one.armTwo.top.x, one.armTwo.top.y,0);
			glVertex3f( one.armTwo.middle.x,one.armTwo.middle.y,0);
			glVertex3f( one.armTwo.middle.x,one.armTwo.middle.y,0);
			glVertex3f( one.armTwo.bottom.x,one.armTwo.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();

    //area

    glPushMatrix();
    
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(one.armTwo.top.x-5, one.armTwo.top.y);   
                glVertex2f(one.armTwo.top.x+5, one.armTwo.top.y); 
                glVertex2f(one.armTwo.middle.x+3, one.armTwo.middle.y); 
                glVertex2f(one.armTwo.middle.x-3, one.armTwo.middle.y);
                
                glVertex2f(one.armTwo.bottom.x+2, one.armTwo.bottom.y);
                glVertex2f(one.armTwo.bottom.x-2, one.armTwo.bottom.y);
                glVertex2f(one.armTwo.middle.x-3, one.armTwo.middle.y);
                glVertex2f(one.armTwo.middle.x+3, one.armTwo.middle.y); 
                          
    glEnd();
	glPopMatrix();

}

void footOne()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.footOne.translate.x,one.footOne.translate.y,0);
    glRotatef(one.footOne.angle, 0, 0, 1);
    circle(one.footOne.radius.x,one.footOne.radius.y);
	glPopMatrix();
}

void legOne()
{
    footOne();
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( one.legOne.top.x, one.legOne.top.y,0);
			glVertex3f( one.legOne.middle.x,one.legOne.middle.y,0);
			glVertex3f( one.legOne.middle.x,one.legOne.middle.y,0);
			glVertex3f( one.legOne.bottom.x,one.legOne.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();
    
    //area

    glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(one.legOne.top.x-5, one.legOne.top.y);   
                glVertex2f(one.legOne.top.x+5, one.legOne.top.y); 
                glVertex2f(one.legOne.middle.x+3, one.legOne.middle.y); 
                glVertex2f(one.legOne.middle.x-3, one.legOne.middle.y);
                
                glVertex2f(one.legOne.bottom.x+2, one.legOne.bottom.y);
                glVertex2f(one.legOne.bottom.x-2, one.legOne.bottom.y);
                glVertex2f(one.legOne.middle.x-3, one.legOne.middle.y);
                glVertex2f(one.legOne.middle.x+3, one.legOne.middle.y); 
                          
    glEnd();
	glPopMatrix();

}

void footTwo()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.footTwo.translate.x,one.footTwo.translate.y,0);
    glRotatef(one.footTwo.angle, 0, 0, 1);
    circle(one.footTwo.radius.x,one.footTwo.radius.y);
	glPopMatrix();
}

void legTwo()
{
    footTwo();
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( one.legTwo.top.x, one.legTwo.top.y,0);
			glVertex3f( one.legTwo.middle.x,one.legTwo.middle.y,0);
			glVertex3f( one.legTwo.middle.x,one.legTwo.middle.y,0);
			glVertex3f( one.legTwo.bottom.x,one.legTwo.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();
    
    //area

    glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(one.legTwo.top.x-5, one.legTwo.top.y);   
                glVertex2f(one.legTwo.top.x+5, one.legTwo.top.y); 
                glVertex2f(one.legTwo.middle.x+3, one.legTwo.middle.y); 
                glVertex2f(one.legTwo.middle.x-3, one.legTwo.middle.y);
                
                glVertex2f(one.legTwo.bottom.x+2, one.legTwo.bottom.y);
                glVertex2f(one.legTwo.bottom.x-2, one.legTwo.bottom.y);
                glVertex2f(one.legTwo.middle.x-3, one.legTwo.middle.y);
                glVertex2f(one.legTwo.middle.x+3, one.legTwo.middle.y); 
                          
    glEnd();
	glPopMatrix();
}

void drawStickmanOne()
{
    
    head();
    glPushMatrix();
    glTranslatef(one.bodyTranslate.x,one.bodyTranslate.y,0);
    handOne();
    armOne();
    body(); 
    handTwo();
    armTwo();
    legOne();
    legTwo();
    glPopMatrix();
    drawAxes();
    drawGrid();
}

