#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "Stickman.h"
//#include "StickmanTwo.h"

//#include "Shapes.h"

// CIRCLE MOVE CODE


/*
#define PI 3.1416

static float	tx	=  0.0;
static float	ty	=  0.0;

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);
    {
		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(0.0, 1.0, 0.0);

	glTranslatef(tx,ty,0);
	circle(6,6);

	glPopMatrix();
	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}


void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=5;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				ty -=5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				ty +=5;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}
int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Translating Circle");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left,right
	glutMainLoop();
	return 0;
}

*/



// PUSH POP MATRIX
/*

#define PI 3.1416

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
                glVertex2f(100, 0);
                glVertex2f(-100, 0);
                glVertex2f(0, 100);
                glVertex2f(0, -100);
    glEnd();

    glPushMatrix();
        glRotatef(45, 0, 0, 1);
        glPushMatrix(); // Furthest Triangle, Draw first


            //glRotatef(45, 0, 0, 1);
            glTranslatef(-20, 0, 0);
            //glScaled(2, 1, 0);
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Middle Triangle, Draw 2nd
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Nearest Triangle, Draw last
            glTranslatef(10, 0, 0);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();



    glPopMatrix();

	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Push Pop Matrix");
	init();
	glutDisplayFunc(display);
	//glutSpecialFunc(spe_key);//up,down,left,right
	glutMainLoop();
	return 0;
}

*/



// ANIMATION CODE


#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double incx, incy;
int state;
char* testString;

struct counter
{
	double punch=0;
	double kick=0;
	double hadouken=0;
};

struct switchCounter
{
	int punch = 0;
	int kick = 0;
	int hadouken = 0;
};

counter timerOne,timerTwo;
switchCounter oneSwitch,twoSwitch;
int startGame=0;
int switchHadouken = 0;
int stickmanOneWon = 1;
int stickmanTwoWon = 0;
int hx=0;

void drawSS()
{
    glColor3f(1,0,0);
    circle(10,10);
    glPushMatrix();
		glRotatef(-angle,0,0,1);
		glTranslatef(0,20,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(1,0,0);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,20,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,0,0);
			circle(5,5);
		glPopMatrix();
		
    glPopMatrix();

	glPushMatrix();
		glRotatef(angle,0,0,1);
		glTranslatef(0,30,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(0,1,0);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,30,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,1,0);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(20,30,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,1,0);
			circle(5,5);
		glPopMatrix();
    
    glPopMatrix();

	glPushMatrix();
		glRotatef(-angle,0,0,1);
		glTranslatef(0,40,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(0,0,1);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,40,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,0,1);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(30,40,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,0,1);
			circle(5,5);
		glPopMatrix();
    glPopMatrix();

	glPushMatrix();
		glRotatef(angle,0,0,1);
		glTranslatef(0,50,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(1,1,0);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,50,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,1,0);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(40,50,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,1,0);
			circle(5,5);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-angle,0,0,1);
		glTranslatef(0,60,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(1,50,90);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,60,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,50,90);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(50,60,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,50,90);
			circle(5,5);
		glPopMatrix();
    glPopMatrix();

	glPushMatrix();
		glRotatef(angle,0,0,1);
		glTranslatef(0,70,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(1,1,0);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,70,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(11,1,90);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(60,70,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(11,1,90);
			circle(5,5);
		glPopMatrix();
    
    glPopMatrix();

	    glPushMatrix();
		glRotatef(-angle,0,0,1);
		glTranslatef(0,80,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(1,0,1);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,80,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,50,0);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(70,80,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(1,50,0);
			circle(5,5);
		glPopMatrix();
    glPopMatrix();

	glPushMatrix();
		glRotatef(angle,0,0,1);
		glTranslatef(0,90,0);
		glRotatef(2*angle,0,0,1);
		glColor3f(0,1,1);
		drawSquare(5);
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(10,90,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,1,1);
			circle(5,5);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-angle,0,0,1);
			glTranslatef(80,90,0);
			glRotatef(2*angle,0,0,1);
			glColor3f(0,1,1);
			circle(5,5);
		glPopMatrix();
	glPopMatrix();
    
    glPopMatrix();


}

/**
 * Draw a character string.
 *
 * @param x        The x position
 * @param y        The y position
 * @param z        The z position
 * @param string   The character string
 */
void drawString(float x, float y, float z, char *string) {
  glRasterPos3f(x, y, z);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
  }
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case 'd':
			//one.toAndFro.x+=1; // stickmanOne going forward
			//printf("%f %f\n",one.toAndFro.x,two.toAndFro.x);
			
			if(one.toAndFro.x == two.toAndFro.x-30)
			{
				one.toAndFro.x-=10;
			}
			else
			{
				one.toAndFro.x+=1; // stickmanOne going forward
			}
			break;
		case 'a':
			one.toAndFro.x-=1; // stickmanOne going backward
			break;
		case 'b':
			one.states.punch = 1 ; // punch
			if(two.life.counter>4)
			{
				stickmanOneWon=1;
			}
			printf("%d \n",two.life.counter);
			break;
		case 'n':
			one.states.kick = 1 ; // kick
			if(two.life.counter>4)
			{
				stickmanOneWon=1;
			}
			printf("%d \n",two.life.counter);
			break;
		case 'm':
			one.states.hadouken = 1 ; // Hadouken
			if(two.life.counter>4)
			{
				stickmanOneWon=1;
			}
			printf("%d \n",two.life.counter);
			break;
		case '1':
			two.states.punch = 1 ; // punch
			break;
		case '2':
			two.states.kick = 1 ; // kick
			break;
		case '3':
			two.states.hadouken = 1 ; // Hadouken
			break;
		case 'y':
			startGame = 1 ; // Hadouken
			break;
		case 'u':
			hx=0 ; // Hadouken
			one.life.counter=1;
			two.life.counter=1;
			break;
		


		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			
			break;
		case GLUT_KEY_UP:		// up arrow key
			
			break;

		case GLUT_KEY_RIGHT:
			two.toAndFro.x+=1; // stickmanTwo going backward
			break;
		case GLUT_KEY_LEFT:
			if(two.toAndFro.x == one.toAndFro.x+30)
			{
				two.toAndFro.x+=10;
			}
			else
			{
				two.toAndFro.x-=1; // stickmanTwo going forward
			}
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}


int S1x=0 , S2x=0;


void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,110,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects

	//drawAxes();
	//drawGrid();
	if(startGame==1)
	{
		if(hx==0)
		{
			glTranslatef(0,-30,0);
			drawStickmanOne();
			drawStickmanTwo();
			glPushMatrix();
			glTranslatef(0,30,-50);
			//drawSS();
			glPopMatrix();
		}
		

			if(one.life.counter>4)
			{
				
				drawString(0,0,0,"STICKMAN TWO WON");
				drawString(22,-30,0,"Press U to START");
				hx=1;
				

			}

			if(two.life.counter>4)
			{
				
				drawString(0,0,0,"STICKMAN One WON");
				drawString(22,-30,0,"Press U to START");
				hx=1;
			}
		
	}
	else if(stickmanTwoWon==1)
	{
		
		drawString(0,0,0,"STICKMAN TWO WON");
		drawString(22,-30,0,"Press Y to START");
	}
	else if(stickmanOneWon==1)
	{
		
		drawString(0,0,0,"STICKMAN ONE WON");
		drawString(22,-30,0,"Press Y to START");
	}
	else
	{
		stickmanTwoWon=0;
		stickmanOneWon=0;
		drawString(0,0,0,"STICKMAN KOMBAT");
		drawString(22,-30,0,"Press Y to START");

	}
	
	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animation_movingBodyUpAndDown()
{
	if(state ==0 && one.bodyTranslate.y>2){ state =1;}
    if(state ==1 && one.bodyTranslate.y <=0){state =0;}

    if(state == 0)
	{
		one.bodyTranslate.y+=.10;
		two.bodyTranslate.y+=.10;
	}
	else 
	{
		one.bodyTranslate.y-=.10;
		two.bodyTranslate.y-=.10;
	}
}
void animation_rotatingHead()
{
	one.headOne.angle+=5;
	two.headOne.angle+=5;
}
/*
ANIMATIONS OF STICKMAN 1
*/
void animation_S1Kick()
{
	if(one.states.kick==1)
	{
		timerOne.kick++;
		S1Kicking();
		if(oneSwitch.kick==0)
		{
			if( one.lengths.kick >= two.toAndFro.x)
			{
				//printf("%d %f\n",one.lengths.kick,two.toAndFro.x);
				two.life.lifebar[two.life.counter]=0;
				two.life.counter++;
				stickmanOneWon++;
				//printf("%d \n",two.life.counter);
				oneSwitch.kick=1;
			}
		}
		
		if(timerOne.kick>10)
		{
			one.states.kick=0;
			timerOne.kick=0;
			oneSwitch.kick=0;
		}
	}
	else
	{
		initS1LegOne();
		initS1FootOne();
	}
}
void animation_S1Hadouken()
{
	
	if(one.states.hadouken == 1)
	{
		one.hadouken.initial.y=0;
		one.lengths.hadoukenCenter = (one.armOne.bottom.y + one.armTwo.bottom.y)/2;
    	one.lengths.hadoukenX = one.armTwo.bottom.x;
		one.states.showHadouken =1;
		timerOne.hadouken++;
		one.hadouken.moving.x++;
		S1Hadouken();
		one.lengths.hadoukenShot = one.hadouken.moving.x+one.toAndFro.x+50;
		//printf("%d %f\n",one.lengths.hadoukenShot,two.toAndFro.x);
		if(oneSwitch.hadouken==0)
		{
			if( one.lengths.hadoukenShot >= two.toAndFro.x)
			{
				//printf("%d \n",two.life.counter);
            	two.life.lifebar[two.life.counter]=0;
				two.life.counter++;
				stickmanOneWon++;
				oneSwitch.hadouken=1;
			}
		}
		
		if(timerOne.hadouken>20)
		{
			one.hadouken.moving.x=0;
			one.states.hadouken = 0;
			timerOne.hadouken = 0;
			one.hadouken.initial.y=0;
			one.lengths.hadoukenX=0;
			
			oneSwitch.hadouken=0;
		}	
	}
	else
	{
		initS1ArmOne();
		initS1ArmTwo();
		initS1HandOne();
		initS1HandTwo();
	}

}
void animation_S1Punch()
{
	if(one.states.punch == 1)
	{
		timerOne.punch++;
		S1Punching();
		if(oneSwitch.punch==0)
		{
			if( one.lengths.punch >= two.toAndFro.x)
			{
				//printf("%d %f\n",one.lengths.punch,two.toAndFro.x);
				two.life.lifebar[two.life.counter]=0;
				two.life.counter++;
				stickmanOneWon++;
				//printf("%d \n",two.life.counter);
				oneSwitch.punch=1;
			}
		}
		
		if(timerOne.punch>10)
		{
			one.states.punch=0;
			timerOne.punch=0;
			oneSwitch.punch=0;
			
		}
	}
	else
	{
		//  initS1ArmOne();
		//  initS1HandOne();
	}

}

/*
ANIMATIONS OF STICKMAN 2
*/
void animation_S2Kick()
{
	if(two.states.kick==1)
	{
		timerTwo.kick++;
		S2Kicking();
		if(twoSwitch.kick==0)
		{
			if( two.lengths.kick <= one.toAndFro.x)
			{
				//printf("%d %f\n",two.lengths.kick,one.toAndFro.x);
				one.life.lifebar[one.life.counter]=0;
				one.life.counter++;
				stickmanTwoWon++;
				//printf("%d \n",one.life.counter);
				twoSwitch.kick=1;
			}
		}
		
		if(timerTwo.kick>.3)
		{
			two.states.kick=0;
			timerTwo.kick=0;
			twoSwitch.kick=0;
		}
	}
	else
	{
		initS2LegOne();
		initS2FootOne();
	}
}
void animation_S2Punch()
{
	if(two.states.punch == 1)
	{
		timerTwo.punch++;
		S2Punching();
		//printf("%d %f\n",two.lengths.punch,one.toAndFro.x);
		if(twoSwitch.punch==0)
		{
			if( two.lengths.punch <= one.toAndFro.x)
			{
				
				one.life.lifebar[one.life.counter]=0;
				one.life.counter++;
				stickmanTwoWon++;
				//printf("%d \n",one.life.counter);
				twoSwitch.punch=1;
			}
		}
		
		if(timerTwo.punch>10)
		{
			two.states.punch=0;
			timerTwo.punch=0;
			twoSwitch.punch=0;
		}
	}
	else
	{
		//  initS1ArmOne();
		//  initS1HandOne();
	}

}
void animation_S2Hadouken()
{
	if(two.states.hadouken == 1)
	{
		two.hadouken.initial.y=0;
		two.lengths.hadoukenCenter = (two.armOne.bottom.y + two.armTwo.bottom.y)/2;
    	two.lengths.hadoukenX = two.armTwo.bottom.x;
		two.states.showHadouken =1;
		timerTwo.hadouken++;
		two.hadouken.moving.x--;
		S2Hadouken();
		two.lengths.hadoukenShot = two.hadouken.moving.x+two.toAndFro.x-50;
		//printf("%d %f\n",two.lengths.hadoukenShot,one.toAndFro.x);
		if(twoSwitch.hadouken==0)
		{
			if( two.lengths.hadoukenShot <= one.toAndFro.x)
			{
				//printf("%d \n",one.life.counter);
            	one.life.lifebar[one.life.counter]=0;
				one.life.counter++;
				stickmanTwoWon++;
				twoSwitch.hadouken=1;
			}
		}
		if(timerTwo.hadouken>20)
		{
			two.hadouken.moving.x=0;
			two.states.hadouken = 0;
			timerTwo.hadouken = 0;
			two.hadouken.initial.y=0;
			two.lengths.hadoukenX=0;
			twoSwitch.hadouken=0;
		}	
	}
	else
	{
		initS2ArmOne();
		initS2ArmTwo();
		initS2HandOne();
		initS2HandTwo();
	}
}
void animate(){
    animation_movingBodyUpAndDown();
	animation_rotatingHead();
	//--------------------------------> S1
	animation_S1Kick();
	animation_S1Hadouken();
	animation_S1Punch();
	
	//--------------------------------> S2
	animation_S2Kick();
	animation_S2Hadouken();
	animation_S2Punch();
	
	//--------------------------------> Background
	angle+=2;
	//printf("%d \n",two.life.counter);
	if(one.life.counter>4)
	{
		stickmanTwoWon=1;
	}
	// if(two.life.counter>4)
	// {
	// 	stickmanOneWon=1;
	// }
	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;
	initializeStickmanOne();
	initializeStickmanTwo();
	initializeS1States();
	initializeS2States();
	//S1x=one.armOne.bottom.x-15;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Stickman Kombat");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}






