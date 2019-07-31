#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "../Stickman.h"

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

    //------> elbow
    one.armTwo.elbow.a.x = one.armTwo.bottom.x+2;
    one.armTwo.elbow.a.y = one.armTwo.bottom.y;
    one.armTwo.elbow.b.x = one.armTwo.bottom.x-2;
    one.armTwo.elbow.b.y = one.armTwo.bottom.y;
    one.armTwo.elbow.c.x = one.armTwo.middle.x-3;
    one.armTwo.elbow.c.y = one.armTwo.middle.y;
    one.armTwo.elbow.d.x = one.armTwo.middle.x+3;
    one.armTwo.elbow.d.y = one.armTwo.middle.y;
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
    //thigh
    one.legOne.thigh.a.x=one.legOne.top.x-5 ;
    one.legOne.thigh.a.y= one.legOne.top.y;
    one.legOne.thigh.b.x= one.legOne.top.x+5 ;
    one.legOne.thigh.b.y= one.legOne.top.y;
    one.legOne.thigh.c.x= one.legOne.middle.x+3;
    one.legOne.thigh.c.y= one.legOne.middle.y;
    one.legOne.thigh.d.x= one.legOne.middle.x-3;
    one.legOne.thigh.d.y= one.legOne.middle.y;
    //knee
    one.legOne.knee.a.x = one.legOne.bottom.x+2;
    one.legOne.knee.a.y = one.legOne.bottom.y;
    one.legOne.knee.b.x = one.legOne.bottom.x-2;
    one.legOne.knee.b.y = one.legOne.bottom.y;
    one.legOne.knee.c.x = one.legOne.middle.x-3;
    one.legOne.knee.c.y = one.legOne.middle.y;
    one.legOne.knee.d.x = one.legOne.middle.x+3;
    one.legOne.knee.d.y = one.legOne.middle.y;



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
    one.lengths.thigh = sqrt(pow((one.legOne.top.x - one.legOne.middle.x),2) + pow((one.legOne.top.y - one.legOne.middle.y),2));
    one.lengths.knee = sqrt(pow((one.legOne.middle.x - one.legOne.bottom.x),2) + pow((one.legOne.middle.y - one.legOne.bottom.y),2));
    one.lengths.elbow2 = sqrt(pow(( one.armTwo.middle.x - one.armTwo.bottom.x ),2) + pow(( one.armTwo.middle.y - one.armTwo.bottom.y ),2));
}

void initializeStates()
{
	
	one.states.punch = 0 ; 
    one.states.kick = 0;
    one.states.hadouken = 0 ;
    one.states.showHadouken = 0;
}