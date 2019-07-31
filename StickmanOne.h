#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "Stickman.h"

stickman one;

void initS1Head()
{
    one.headOne.radius.x=8;
    one.headOne.radius.y=8;
    one.headOne.translate.x = 0;
    one.headOne.translate.y = 60;
    one.headOne.angle = 90;

}

void initS1Body()
{
    one.bodyDown.x=0;
    one.bodyDown.y=25;
    one.bodyTranslate.x = 0;
    one.bodyTranslate.y = 0;
    one.toAndFro.x = 0 ;
    one.toAndFro.y = 0 ;
}

void initS1ArmOne()
{
     //------------------------>armOne
    one.armOne.top.x = 0;
    one.armOne.top.y = 45;
    one.armOne.middle.x = -15;
    one.armOne.middle.y = 30;
    one.armOne.bottom.x = -5;
    one.armOne.bottom.y = 20;
    //------> bicep
    one.armOne.bicep.a.x = one.armOne.top.x-5;
    one.armOne.bicep.a.y = one.armOne.top.y;
    one.armOne.bicep.b.x = one.armOne.top.x+5;
    one.armOne.bicep.b.y = one.armOne.top.y;
    one.armOne.bicep.c.x = one.armOne.middle.x+3;
    one.armOne.bicep.c.y = one.armOne.middle.y;
    one.armOne.bicep.d.x = one.armOne.middle.x-3;
    one.armOne.bicep.d.y = one.armOne.middle.y;
    //------> elbow
    one.armOne.elbow.a.x = one.armOne.bottom.x+2;
    one.armOne.elbow.a.y = one.armOne.bottom.y;
    one.armOne.elbow.b.x = one.armOne.bottom.x-2;
    one.armOne.elbow.b.y = one.armOne.bottom.y;
    one.armOne.elbow.c.x = one.armOne.middle.x-3;
    one.armOne.elbow.c.y = one.armOne.middle.y;
    one.armOne.elbow.d.x = one.armOne.middle.x+3;
    one.armOne.elbow.d.y = one.armOne.middle.y;
    
}

void initS1HandOne()
{
    one.handOne.radius.x=2;
    one.handOne.radius.y=one.handOne.radius.x+2;
    one.handOne.translate.x = one.armOne.bottom.x;
    one.handOne.translate.y = one.armOne.bottom.y;
    one.handOne.angle=-45;
}

void initS1ArmTwo()
{
    one.armTwo.top.x = 0;
    one.armTwo.top.y = 45;
    one.armTwo.middle.x = 15;
    one.armTwo.middle.y = 30;
    one.armTwo.bottom.x = 20;
    one.armTwo.bottom.y = 40;
}

void initS1HandTwo()
{
    one.handTwo.radius.x=2;
    one.handTwo.radius.y=one.handTwo.radius.x+2;
    one.handTwo.translate.x = one.armTwo.bottom.x;
    one.handTwo.translate.y = one.armTwo.bottom.y;
    one.handTwo.angle=-90;
}

void initS1LegOne()
{
    one.legOne.top.x=one.bodyDown.x;
    one.legOne.top.y=one.bodyDown.y;
    one.legOne.middle.x=-5;
    one.legOne.middle.y=10;
    one.legOne.bottom.x=-15;
    one.legOne.bottom.y=0;
}

void initS1FootOne()
{
    one.footOne.radius.x=2;
    one.footOne.radius.y=one.footOne.radius.x+3;
    one.footOne.translate.x = one.legOne.bottom.x+2;
    one.footOne.translate.y = one.legOne.bottom.y;
    one.footOne.angle=-90;
}

void initS1LegTwo()
{
    one.legTwo.top.x=one.bodyDown.x;
    one.legTwo.top.y=one.bodyDown.y;
    one.legTwo.middle.x=10;
    one.legTwo.middle.y=14;
    one.legTwo.bottom.x=8;
    one.legTwo.bottom.y=0;
}

void initS1FootTwo()
{
    one.footTwo.radius.x=2;
    one.footTwo.radius.y=one.footTwo.radius.x+3;
    one.footTwo.translate.x = one.legTwo.bottom.x+2;
    one.footTwo.translate.y = one.legTwo.bottom.y;
    one.footTwo.angle=-90;
}

void initS1Lengths()
{
    one.lengths.bicep = sqrt(pow((one.armOne.top.x - one.armOne.middle.x),2) + pow((one.armOne.top.y - one.armOne.middle.y),2));
    one.lengths.elbow = sqrt(pow(( one.armOne.middle.x - one.armOne.bottom.x ),2) + pow(( one.armOne.middle.y - one.armOne.bottom.y ),2)); 
    
}

void S1Punching()
{
    //line
		one.armOne.middle.x= one.armOne.top.x + one.lengths.bicep;
		one.armOne.middle.y = one.armOne.top.y;

		one.armOne.bottom.x = one.armOne.middle.x + one.lengths.elbow;
		one.armOne.bottom.y = one.armOne.top.y;

		//bicep
		one.armOne.bicep.a.x = one.armOne.top.x-2;
		one.armOne.bicep.a.y = one.armOne.top.y + 5;
		one.armOne.bicep.b.x = one.armOne.middle.x;
		one.armOne.bicep.b.y = one.armOne.top.y + 2;
		one.armOne.bicep.c.x = one.armOne.middle.x;
		one.armOne.bicep.c.y = one.armOne.top.y - 2;
		one.armOne.bicep.d.x = one.armOne.top.x;
		one.armOne.bicep.d.y = one.armOne.top.y - 5;

        //elbow
        one.armOne.elbow.a.x = one.armOne.bicep.b.x;
		one.armOne.elbow.a.y = one.armOne.bicep.b.y;
		one.armOne.elbow.b.x = one.armOne.bottom.x;
		one.armOne.elbow.b.y = one.armOne.bottom.y + 1.5;
		one.armOne.elbow.c.x = one.armOne.bottom.x;
		one.armOne.elbow.c.y = one.armOne.bottom.y - 1.5;
		one.armOne.elbow.d.x = one.armOne.bicep.c.x;
		one.armOne.elbow.d.y = one.armOne.bicep.c.y;

        one.handOne.translate.x = one.armOne.bottom.x ;
		one.handOne.translate.y = one.armOne.bottom.y ; 
        one.handOne.angle = 180;
}

void initializeStickmanOne()
{
    initS1Head();
    initS1Body();    
    initS1ArmOne();
    initS1HandOne();
    initS1ArmTwo();
    initS1HandTwo();
    initS1LegOne();
    initS1FootOne();
    initS1LegTwo();
    initS1FootTwo();
    initS1Lengths();
}

void initializeStates()
{
	
	one.states.punch = 0 ; 
}

void theHead()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(one.headOne.translate.x,one.headOne.translate.y,0);
    glRotatef(one.headOne.angle,0,0,1);
    circleHead(one.headOne.radius.x,one.headOne.radius.y);
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
                //bicep
                glVertex2f(one.armOne.bicep.a.x , one.armOne.bicep.a.y );   
                glVertex2f(one.armOne.bicep.b.x , one.armOne.bicep.b.y );
                glVertex2f(one.armOne.bicep.c.x , one.armOne.bicep.c.y );   
                glVertex2f(one.armOne.bicep.d.x , one.armOne.bicep.d.y );
                //elbow
                glVertex2f(one.armOne.elbow.a.x, one.armOne.elbow.a.y);
                glVertex2f(one.armOne.elbow.b.x, one.armOne.elbow.b.y);
                glVertex2f(one.armOne.elbow.c.x, one.armOne.elbow.c.y);
                glVertex2f(one.armOne.elbow.d.x, one.armOne.elbow.d.y); 
                          
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
    glPushMatrix();
    glTranslatef(one.toAndFro.x,one.toAndFro.y,0); // moving body front and back
    theHead();
    glPushMatrix(); // moving body up and down
    glTranslatef(one.bodyTranslate.x,one.bodyTranslate.y,0);
    handOne();
    armOne();
    body(); 
    handTwo();
    armTwo();
    legTwo();
    legOne();
    glPopMatrix(); // END of moving body up and down
    footOne();
    footTwo();
    glPopMatrix(); // END of moving body front and back
    
    drawAxes();
    drawGrid();
}

