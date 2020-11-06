#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

//citations
//https://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work for .eof() in plotPoints.cpp line 38

#define COLORMAX 1.0
#define COLORMIN 0.0
#define XMAX 640
#define YMAX 480

//structure of a set of points
struct Points
{
    float redValue;
    float greenValue;
    float blueValue;
    int x;
    int y;
    int deltaX;
    int deltaY;
    int reps;
};

//PURPOSE: read sets of points from a file and plot them in a window
//PRECONDITIONS: Open GL window is already initialized
//PARAMETERS: none
//RETURNS: void
void plotPoints ();

//PURPOSE: check for invalid values in points.in, if error detected print out error and terminate program
//PARAMETERS: Points points as points just read in, int lineNum as number of line of points.in just read in
//RETURNS: void
void checkForErrors(Points points, int lineNum);

//PURPOSE: draw a set of points in the Open GL window
//PRECONDITION: all values within Points currentPoints are valid
//PARAMETERS: Points currentPoints as set of points to be plotted
//RETURNS: void
void plotLine(Points currentPoints);
