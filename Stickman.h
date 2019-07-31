#include<math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>

#include "Shapes.h"

struct points
{
    double x;
    double y;
};

struct hand
{
    points radius;
    points translate;
    int angle;
};

struct foot
{
    points radius;
    points translate;
    int angle;
};

struct arm
{
    points top,middle,bottom;

};

struct leg
{
    points top,middle,bottom;

};


struct stickman
{
	//--------------------Head
    double headRadius;
    int headSegments;
    points headTranslate;

    //---------------------Body
    points bodyDown;
    points bodyTranslate;

    //---------------------arms
    arm armOne,armTwo;
    hand handOne,handTwo;
    
    //---------------------legs
    leg legOne,legTwo;
    foot footOne,footTwo;

};







	