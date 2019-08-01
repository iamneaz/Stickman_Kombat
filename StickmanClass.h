#include <math.h>
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

struct head
{
    points radius;
    points translate;
    int angle;
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

struct quad
{
    points a,b,c,d;
};

struct arm
{
    points top,middle,bottom;
    quad bicep,elbow;

};

struct leg
{
    points top,middle,bottom;
    quad thigh,knee;

};

struct condition
{
    int punch;
    int kick;
    int hadouken;
    int showHadouken;
};

struct length
{
    int bicep;
    int elbow;
    int thigh;
    int knee;
    int elbow2;
    int hadoukenCenter;
    int hadoukenX;
    
};


struct stickman
{
	//--------------------Head
    head headOne;
    points headTranslate;

    //---------------------Body
    points bodyDown;
    points bodyTranslate;
    points toAndFro;

    //---------------------arms
    arm armOne,armTwo;
    hand handOne,handTwo;
    
    //---------------------legs
    leg legOne,legTwo;
    foot footOne,footTwo;

    //---------------------state
    condition states;

    //---------------------lengths
    length lengths;
};







	