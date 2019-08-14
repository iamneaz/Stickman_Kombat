#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "../StickmanClass.h"

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

void initializeS1States()
{
	
	one.states.punch = 0 ; 
    one.states.kick = 0;
    one.states.hadouken = 0 ;
    one.states.showHadouken = 0;
}

void initializeS1Hadouken()
{
    one.hadouken.initial.x = 0;
    one.hadouken.initial.y = 30;
    one.hadouken.moving.x = 0;
    
}

stickman two;

void initS2Head()
{
    two.headOne.radius.x=8;
    two.headOne.radius.y=8;
    two.headOne.translate.x = 0;
    two.headOne.translate.y = 60;
    two.headOne.angle = 0;

}

void initS2Body()
{
    two.bodyDown.x=0;
    two.bodyDown.y=25;
    two.bodyTranslate.x = 0;
    two.bodyTranslate.y = 0;
    two.toAndFro.x = 0 ;
    two.toAndFro.y = 0 ;
}

void initS2ArmOne()
{
     //------------------------>armOne
    two.armOne.top.x = 0;
    two.armOne.top.y = 45;
    two.armOne.middle.x = 15;
    two.armOne.middle.y = 30;
    two.armOne.bottom.x = 5;
    two.armOne.bottom.y = 20;
    //------> bicep
    two.armOne.bicep.a.x = two.armOne.top.x-5;
    two.armOne.bicep.a.y = two.armOne.top.y;
    two.armOne.bicep.b.x = two.armOne.top.x+5;
    two.armOne.bicep.b.y = two.armOne.top.y;
    two.armOne.bicep.c.x = two.armOne.middle.x+3;
    two.armOne.bicep.c.y = two.armOne.middle.y;
    two.armOne.bicep.d.x = two.armOne.middle.x-3;
    two.armOne.bicep.d.y = two.armOne.middle.y;
    //------> elbow
    two.armOne.elbow.a.x = two.armOne.bottom.x+2;
    two.armOne.elbow.a.y = two.armOne.bottom.y;
    two.armOne.elbow.b.x = two.armOne.bottom.x-2;
    two.armOne.elbow.b.y = two.armOne.bottom.y;
    two.armOne.elbow.c.x = two.armOne.middle.x-3;
    two.armOne.elbow.c.y = two.armOne.middle.y;
    two.armOne.elbow.d.x = two.armOne.middle.x+3;
    two.armOne.elbow.d.y = two.armOne.middle.y;
    
}

void initS2HandOne()
{
    two.handOne.radius.x=2;
    two.handOne.radius.y=two.handOne.radius.x+2;
    two.handOne.translate.x = two.armOne.bottom.x;
    two.handOne.translate.y = two.armOne.bottom.y;
    two.handOne.angle=45;
}

void initS2ArmTwo()
{
    two.armTwo.top.x = 0;
    two.armTwo.top.y = 45;
    two.armTwo.middle.x = -15;
    two.armTwo.middle.y = 30;
    two.armTwo.bottom.x = -20;
    two.armTwo.bottom.y = 40;

    //------> elbow
    two.armTwo.elbow.a.x = two.armTwo.bottom.x+2;
    two.armTwo.elbow.a.y = two.armTwo.bottom.y;
    two.armTwo.elbow.b.x = two.armTwo.bottom.x-2;
    two.armTwo.elbow.b.y = two.armTwo.bottom.y;
    two.armTwo.elbow.c.x = two.armTwo.middle.x-3;
    two.armTwo.elbow.c.y = two.armTwo.middle.y;
    two.armTwo.elbow.d.x = two.armTwo.middle.x+3;
    two.armTwo.elbow.d.y = two.armTwo.middle.y;
}

void initS2HandTwo()
{
    two.handTwo.radius.x=2;
    two.handTwo.radius.y=two.handTwo.radius.x+2;
    two.handTwo.translate.x = two.armTwo.bottom.x;
    two.handTwo.translate.y = two.armTwo.bottom.y;
    two.handTwo.angle=-90;
}

void initS2LegOne()
{
    two.legOne.top.x=two.bodyDown.x;
    two.legOne.top.y=two.bodyDown.y;
    two.legOne.middle.x=5;
    two.legOne.middle.y=10;
    two.legOne.bottom.x=15;
    two.legOne.bottom.y=0;
    //thigh
    two.legOne.thigh.a.x=two.legOne.top.x-5 ;
    two.legOne.thigh.a.y= two.legOne.top.y;
    two.legOne.thigh.b.x= two.legOne.top.x+5 ;
    two.legOne.thigh.b.y= two.legOne.top.y;
    two.legOne.thigh.c.x= two.legOne.middle.x+3;
    two.legOne.thigh.c.y= two.legOne.middle.y;
    two.legOne.thigh.d.x= two.legOne.middle.x-3;
    two.legOne.thigh.d.y= two.legOne.middle.y;
    //knee
    two.legOne.knee.a.x = two.legOne.bottom.x+2;
    two.legOne.knee.a.y = two.legOne.bottom.y;
    two.legOne.knee.b.x = two.legOne.bottom.x-2;
    two.legOne.knee.b.y = two.legOne.bottom.y;
    two.legOne.knee.c.x = two.legOne.middle.x-3;
    two.legOne.knee.c.y = two.legOne.middle.y;
    two.legOne.knee.d.x = two.legOne.middle.x+3;
    two.legOne.knee.d.y = two.legOne.middle.y;



}

void initS2FootOne()
{
    two.footOne.radius.x=2;
    two.footOne.radius.y=two.footOne.radius.x+3;
    two.footOne.translate.x = two.legOne.bottom.x-2;
    two.footOne.translate.y = two.legOne.bottom.y;
    two.footOne.angle=-90;
}

void initS2LegTwo()
{
    two.legTwo.top.x=two.bodyDown.x;
    two.legTwo.top.y=two.bodyDown.y;
    two.legTwo.middle.x=-10;
    two.legTwo.middle.y=14;
    two.legTwo.bottom.x=-8;
    two.legTwo.bottom.y=0;
}

void initS2FootTwo()
{
    two.footTwo.radius.x=2;
    two.footTwo.radius.y=two.footTwo.radius.x+3;
    two.footTwo.translate.x = two.legTwo.bottom.x-2;
    two.footTwo.translate.y = two.legTwo.bottom.y;
    two.footTwo.angle=-90;
}

void initS2Lengths()
{
    two.lengths.bicep = sqrt(pow((two.armOne.top.x - two.armOne.middle.x),2) + pow((two.armOne.top.y - two.armOne.middle.y),2));
    two.lengths.elbow = sqrt(pow(( two.armOne.middle.x - two.armOne.bottom.x ),2) + pow(( two.armOne.middle.y - two.armOne.bottom.y ),2)); 
    two.lengths.thigh = sqrt(pow((two.legOne.top.x - two.legOne.middle.x),2) + pow((two.legOne.top.y - two.legOne.middle.y),2));
    two.lengths.knee = sqrt(pow((two.legOne.middle.x - two.legOne.bottom.x),2) + pow((two.legOne.middle.y - two.legOne.bottom.y),2));
    two.lengths.elbow2 = sqrt(pow(( two.armTwo.middle.x - two.armTwo.bottom.x ),2) + pow(( two.armTwo.middle.y - two.armTwo.bottom.y ),2));
}

void initializeS2States()
{
	
	two.states.punch = 0 ; 
    two.states.kick = 0;
    two.states.hadouken = 0 ;
    two.states.showHadouken = 0;
}