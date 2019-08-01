#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "initialization/initStickman.h"

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
                
                glVertex2f(one.armTwo.elbow.a.x,one.armTwo.elbow.a.y );
                glVertex2f(one.armTwo.elbow.b.x,one.armTwo.elbow.b.y );
                glVertex2f(one.armTwo.elbow.c.x,one.armTwo.elbow.c.y );
                glVertex2f(one.armTwo.elbow.d.x,one.armTwo.elbow.d.y );
                
                          
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
                //thigh
                glVertex2f(one.legOne.thigh.a.x,one.legOne.thigh.a.y );   
                glVertex2f(one.legOne.thigh.b.x,one.legOne.thigh.b.y );   
                glVertex2f(one.legOne.thigh.c.x,one.legOne.thigh.c.y );   
                glVertex2f(one.legOne.thigh.d.x,one.legOne.thigh.d.y );   
                
                //knee
                glVertex2f(one.legOne.knee.a.x,one.legOne.knee.a.y );
                glVertex2f(one.legOne.knee.b.x,one.legOne.knee.b.y );
                glVertex2f(one.legOne.knee.c.x,one.legOne.knee.c.y );
                glVertex2f(one.legOne.knee.d.x,one.legOne.knee.d.y );
                
                          
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
    glTranslatef(-50,0,0); // moving stickman one to the left side
    glPushMatrix();
    glTranslatef(one.toAndFro.x,one.toAndFro.y,0); // moving body front and back
    theHead();
    glPushMatrix(); // moving body up and down
    glTranslatef(one.bodyTranslate.x,one.bodyTranslate.y,0);
    handOne();
    armOne();
    legOne();
    body(); 
    handTwo();
    armTwo();
    legTwo();
    footOne();
    footTwo();
    glPopMatrix(); // END of moving body up and down
    glPopMatrix(); // END of moving body front and back
    glPopMatrix();
    
    drawAxes();
    drawGrid();
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
        //hand
        one.handOne.translate.x = one.armOne.bottom.x ;
		one.handOne.translate.y = one.armOne.bottom.y ; 
        one.handOne.angle = 180;
}

void S1Kicking()
{
    //line
		one.legOne.middle.x= one.legOne.top.x + one.lengths.thigh;
		one.legOne.middle.y = one.legOne.top.y;

		one.legOne.bottom.x = one.legOne.middle.x + one.lengths.knee;
		one.legOne.bottom.y = one.legOne.top.y;
    //thigh
		one.legOne.thigh.a.x = one.legOne.top.x;
		one.legOne.thigh.a.y = one.legOne.top.y + 5;
		one.legOne.thigh.b.x = one.legOne.middle.x;
		one.legOne.thigh.b.y = one.legOne.top.y + 3;
		one.legOne.thigh.c.x = one.legOne.middle.x;
		one.legOne.thigh.c.y = one.legOne.top.y - 3;
		one.legOne.thigh.d.x = one.legOne.top.x;
		one.legOne.thigh.d.y = one.legOne.top.y - 5;
    //knee
        one.legOne.knee.a.x = one.legOne.thigh.b.x;
		one.legOne.knee.a.y = one.legOne.thigh.b.y;
		one.legOne.knee.b.x = one.legOne.bottom.x;
		one.legOne.knee.b.y = one.legOne.bottom.y + 1.5;
		one.legOne.knee.c.x = one.legOne.bottom.x;
		one.legOne.knee.c.y = one.legOne.bottom.y - 1.5;
		one.legOne.knee.d.x = one.legOne.thigh.c.x;
		one.legOne.knee.d.y = one.legOne.thigh.c.y;
    //hand
        one.footOne.translate.x = one.legOne.bottom.x ;
		one.footOne.translate.y = one.legOne.bottom.y ; 
        one.footOne.angle = 180;
}

void S1Hadouken()
{
    S1Punching();
    //line
    one.armTwo.bottom.x = one.armTwo.middle.x+ one.lengths.elbow2;
    one.armTwo.bottom.y = one.armTwo.middle.y;
    //elbow
    one.armTwo.elbow.a.x = one.armTwo.middle.x;
    one.armTwo.elbow.a.y = one.armTwo.middle.y+3;
    one.armTwo.elbow.b.x = one.armTwo.middle.x+one.lengths.elbow2;
    one.armTwo.elbow.b.y = one.armTwo.middle.y+1.5;
    one.armTwo.elbow.c.x = one.armTwo.middle.x+one.lengths.elbow2;
    one.armTwo.elbow.c.y = one.armTwo.middle.y-1.5;
    one.armTwo.elbow.d.x = one.armTwo.middle.x-3.5;
    one.armTwo.elbow.d.y = one.armTwo.middle.y-.5;

    //hand
    one.handTwo.translate.x = one.armTwo.bottom.x ;
	one.handTwo.translate.y = one.armTwo.bottom.y ; 
    one.handTwo.angle = 180;

    one.lengths.hadoukenCenter = (one.armOne.bottom.y + one.armTwo.bottom.y)/2;
    one.lengths.hadoukenX = one.armTwo.bottom.x;

    

}

//-------------------------------------------------------------------------------------> Stickman Two
void initializeStickmanTwo()
{
    initS2Head();
    initS2Body();    
    initS2ArmOne();
    initS2HandOne();
    initS2ArmTwo();
    initS2HandTwo();
    initS2LegOne();
    initS2FootOne();
    initS2LegTwo();
    initS2FootTwo();
    initS2Lengths();
}

void S2Head()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(two.headOne.translate.x,two.headOne.translate.y,0);
    glRotatef(two.headOne.angle,0,0,1);
    circleHead(two.headOne.radius.x,two.headOne.radius.y);
	glPopMatrix();
}

void S2handOne()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(two.handOne.translate.x,two.handOne.translate.y,0);
    glRotatef(two.handOne.angle, 0, 0, 1);
    circle(two.handOne.radius.x,two.handOne.radius.y);
	glPopMatrix();
}

void S2armOne()
{
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( two.armOne.top.x, two.armOne.top.y,0);
			glVertex3f( two.armOne.middle.x,two.armOne.middle.y,0);
			glVertex3f( two.armOne.middle.x,two.armOne.middle.y,0);
			glVertex3f( two.armOne.bottom.x,two.armOne.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();

    //area

    glPushMatrix();
    
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                //bicep
                glVertex2f(two.armOne.bicep.a.x , two.armOne.bicep.a.y );   
                glVertex2f(two.armOne.bicep.b.x , two.armOne.bicep.b.y );
                glVertex2f(two.armOne.bicep.c.x , two.armOne.bicep.c.y );   
                glVertex2f(two.armOne.bicep.d.x , two.armOne.bicep.d.y );
                //elbow
                glVertex2f(two.armOne.elbow.a.x, two.armOne.elbow.a.y);
                glVertex2f(two.armOne.elbow.b.x, two.armOne.elbow.b.y);
                glVertex2f(two.armOne.elbow.c.x, two.armOne.elbow.c.y);
                glVertex2f(two.armOne.elbow.d.x, two.armOne.elbow.d.y); 
                          
    glEnd();
	glPopMatrix();
}

void S2body()
{
    //line
    glPushMatrix(); 
		glTranslatef(two.headTranslate.x,two.headTranslate.y-60,0);
        
		glBegin(GL_LINES);{				
			glColor3f(0.0, 1.0, 0.0);
            glVertex2f( 0, 50);
			glVertex2f( two.bodyDown.x,two.bodyDown.y);	
		}glEnd();
    glPopMatrix();

    // area
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0,0,0);
    glBegin(GL_POLYGON);
                glVertex2f(-5, 25);   // bottom
                glVertex2f(-10, 45); // top
                glVertex2f(15, 50); // top
                glVertex2f(4, 25); // bottom
                
    glEnd();
	glPopMatrix();
}

void S2handTwo()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(two.handTwo.translate.x,two.handTwo.translate.y,0);
    glRotatef(two.handTwo.angle, 0, 0, 1);
    circle(two.handTwo.radius.x,two.handTwo.radius.y);
	glPopMatrix();

}

void S2armTwo()
{
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( two.armTwo.top.x, two.armTwo.top.y,0);
			glVertex3f( two.armTwo.middle.x,two.armTwo.middle.y,0);
			glVertex3f( two.armTwo.middle.x,two.armTwo.middle.y,0);
			glVertex3f( two.armTwo.bottom.x,two.armTwo.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();

    //area

    glPushMatrix();
    
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(two.armTwo.top.x-5, two.armTwo.top.y);   
                glVertex2f(two.armTwo.top.x+5, two.armTwo.top.y); 
                glVertex2f(two.armTwo.middle.x+3, two.armTwo.middle.y); 
                glVertex2f(two.armTwo.middle.x-3, two.armTwo.middle.y);
                
                glVertex2f(two.armTwo.elbow.a.x,two.armTwo.elbow.a.y );
                glVertex2f(two.armTwo.elbow.b.x,two.armTwo.elbow.b.y );
                glVertex2f(two.armTwo.elbow.c.x,two.armTwo.elbow.c.y );
                glVertex2f(two.armTwo.elbow.d.x,two.armTwo.elbow.d.y );
                
                          
    glEnd();
	glPopMatrix();

}

void S2footOne()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(two.footOne.translate.x,two.footOne.translate.y,0);
    glRotatef(two.footOne.angle, 0, 0, 1);
    circle(two.footOne.radius.x,two.footOne.radius.y);
	glPopMatrix();
}

void S2legOne()
{
    
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( two.legOne.top.x, two.legOne.top.y,0);
			glVertex3f( two.legOne.middle.x,two.legOne.middle.y,0);
			glVertex3f( two.legOne.middle.x,two.legOne.middle.y,0);
			glVertex3f( two.legOne.bottom.x,two.legOne.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();
    
    //area

    glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                //thigh
                glVertex2f(two.legOne.thigh.a.x,two.legOne.thigh.a.y );   
                glVertex2f(two.legOne.thigh.b.x,two.legOne.thigh.b.y );   
                glVertex2f(two.legOne.thigh.c.x,two.legOne.thigh.c.y );   
                glVertex2f(two.legOne.thigh.d.x,two.legOne.thigh.d.y );   
                
                //knee
                glVertex2f(two.legOne.knee.a.x,two.legOne.knee.a.y );
                glVertex2f(two.legOne.knee.b.x,two.legOne.knee.b.y );
                glVertex2f(two.legOne.knee.c.x,two.legOne.knee.c.y );
                glVertex2f(two.legOne.knee.d.x,two.legOne.knee.d.y );
                
                          
    glEnd();
	glPopMatrix();

}

void S2footTwo()
{
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(two.footTwo.translate.x,two.footTwo.translate.y,0);
    glRotatef(two.footTwo.angle, 0, 0, 1);
    circle(two.footTwo.radius.x,two.footTwo.radius.y);
	glPopMatrix();
}

void S2legTwo()
{
    
    //line
	glPushMatrix(); // 
		glTranslatef(0,0,0);
        glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( two.legTwo.top.x, two.legTwo.top.y,0);
			glVertex3f( two.legTwo.middle.x,two.legTwo.middle.y,0);
			glVertex3f( two.legTwo.middle.x,two.legTwo.middle.y,0);
			glVertex3f( two.legTwo.bottom.x,two.legTwo.bottom.y,0);	
		}glEnd();
            		
    glPopMatrix();
    
    //area

    glPushMatrix();
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
                glVertex2f(two.legTwo.top.x-5, two.legTwo.top.y);   
                glVertex2f(two.legTwo.top.x+5, two.legTwo.top.y); 
                glVertex2f(two.legTwo.middle.x+3, two.legTwo.middle.y); 
                glVertex2f(two.legTwo.middle.x-3, two.legTwo.middle.y);
                
                glVertex2f(two.legTwo.bottom.x+2, two.legTwo.bottom.y);
                glVertex2f(two.legTwo.bottom.x-2, two.legTwo.bottom.y);
                glVertex2f(two.legTwo.middle.x-3, two.legTwo.middle.y);
                glVertex2f(two.legTwo.middle.x+3, two.legTwo.middle.y); 
                          
    glEnd();
	glPopMatrix();
}

void drawStickmanTwo()
{
    glPushMatrix();
    glTranslatef(0,0,0); // moving stickman one to the left side
    glPushMatrix();
    glTranslatef(two.toAndFro.x,two.toAndFro.y,0); // moving body front and back
    S2Head();
    glPushMatrix(); // moving body up and down
    glTranslatef(two.bodyTranslate.x,two.bodyTranslate.y,0);
    S2handOne();
    S2armOne();
    S2legOne();
    S2body(); 
    S2handTwo();
    S2armTwo();
    S2legTwo();
    S2footOne();
    S2footTwo();
    glPopMatrix(); // END of moving body up and down
    glPopMatrix(); // END of moving body front and back
    glPopMatrix();
    
    drawAxes();
    drawGrid();
}

void S2Punching()
{
    //line
		two.armOne.middle.x= two.armOne.top.x + two.lengths.bicep;
		two.armOne.middle.y = two.armOne.top.y;

		two.armOne.bottom.x = two.armOne.middle.x + two.lengths.elbow;
		two.armOne.bottom.y = two.armOne.top.y;

		//bicep
		two.armOne.bicep.a.x = two.armOne.top.x-2;
		two.armOne.bicep.a.y = two.armOne.top.y + 5;
		two.armOne.bicep.b.x = two.armOne.middle.x;
		two.armOne.bicep.b.y = two.armOne.top.y + 2;
		two.armOne.bicep.c.x = two.armOne.middle.x;
		two.armOne.bicep.c.y = two.armOne.top.y - 2;
		two.armOne.bicep.d.x = two.armOne.top.x;
		two.armOne.bicep.d.y = two.armOne.top.y - 5;

        //elbow
        two.armOne.elbow.a.x = two.armOne.bicep.b.x;
		two.armOne.elbow.a.y = two.armOne.bicep.b.y;
		two.armOne.elbow.b.x = two.armOne.bottom.x;
		two.armOne.elbow.b.y = two.armOne.bottom.y + 1.5;
		two.armOne.elbow.c.x = two.armOne.bottom.x;
		two.armOne.elbow.c.y = two.armOne.bottom.y - 1.5;
		two.armOne.elbow.d.x = two.armOne.bicep.c.x;
		two.armOne.elbow.d.y = two.armOne.bicep.c.y;
        //hand
        two.handOne.translate.x = two.armOne.bottom.x ;
		two.handOne.translate.y = two.armOne.bottom.y ; 
        two.handOne.angle = 180;
}

void S2Kicking()
{
    //line
		two.legOne.middle.x= two.legOne.top.x + two.lengths.thigh;
		two.legOne.middle.y = two.legOne.top.y;

		two.legOne.bottom.x = two.legOne.middle.x + two.lengths.knee;
		two.legOne.bottom.y = two.legOne.top.y;
    //thigh
		two.legOne.thigh.a.x = two.legOne.top.x;
		two.legOne.thigh.a.y = two.legOne.top.y + 5;
		two.legOne.thigh.b.x = two.legOne.middle.x;
		two.legOne.thigh.b.y = two.legOne.top.y + 3;
		two.legOne.thigh.c.x = two.legOne.middle.x;
		two.legOne.thigh.c.y = two.legOne.top.y - 3;
		two.legOne.thigh.d.x = two.legOne.top.x;
		two.legOne.thigh.d.y = two.legOne.top.y - 5;
    //knee
        two.legOne.knee.a.x = two.legOne.thigh.b.x;
		two.legOne.knee.a.y = two.legOne.thigh.b.y;
		two.legOne.knee.b.x = two.legOne.bottom.x;
		two.legOne.knee.b.y = two.legOne.bottom.y + 1.5;
		two.legOne.knee.c.x = two.legOne.bottom.x;
		two.legOne.knee.c.y = two.legOne.bottom.y - 1.5;
		two.legOne.knee.d.x = two.legOne.thigh.c.x;
		two.legOne.knee.d.y = two.legOne.thigh.c.y;
    //hand
        two.footOne.translate.x = two.legOne.bottom.x ;
		two.footOne.translate.y = two.legOne.bottom.y ; 
        two.footOne.angle = 180;
}

void S2Hadouken()
{
    S2Punching();
    //line
    two.armTwo.bottom.x = two.armTwo.middle.x+ two.lengths.elbow2;
    two.armTwo.bottom.y = two.armTwo.middle.y;
    //elbow
    two.armTwo.elbow.a.x = two.armTwo.middle.x;
    two.armTwo.elbow.a.y = two.armTwo.middle.y+3;
    two.armTwo.elbow.b.x = two.armTwo.middle.x+two.lengths.elbow2;
    two.armTwo.elbow.b.y = two.armTwo.middle.y+1.5;
    two.armTwo.elbow.c.x = two.armTwo.middle.x+two.lengths.elbow2;
    two.armTwo.elbow.c.y = two.armTwo.middle.y-1.5;
    two.armTwo.elbow.d.x = two.armTwo.middle.x-3.5;
    two.armTwo.elbow.d.y = two.armTwo.middle.y-.5;

    //hand
    two.handTwo.translate.x = two.armTwo.bottom.x ;
	two.handTwo.translate.y = two.armTwo.bottom.y ; 
    two.handTwo.angle = 180;

    two.lengths.hadoukenCenter = (two.armOne.bottom.y + two.armTwo.bottom.y)/2;
    two.lengths.hadoukenX = two.armTwo.bottom.x;

    

}