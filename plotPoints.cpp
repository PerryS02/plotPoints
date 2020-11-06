#include "plotPoints.h"

void plotPoints ()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, XMAX, 0.0, YMAX);

    ifstream inFile("points.in");
    if (!inFile)
    {
        cout <<"ERROR: INPUT FILE points.in NOT FOUND.\n";
        exit(1);
    }

    Points currentPoints;
    int currentLineNum = 0;
    //grab values from the input file and plot them until the eof is reached
    do
    {
        inFile >> currentPoints.redValue;
        inFile >> currentPoints.greenValue;
        inFile >> currentPoints.blueValue;
        inFile >> currentPoints.x;
        inFile >> currentPoints.y;
        inFile >> currentPoints.deltaX;
        inFile >> currentPoints.deltaY;
        inFile >> currentPoints.reps;
        currentLineNum++;
        //check the current set of points for invalid values
        checkForErrors(currentPoints, currentLineNum);
        //plot the points if no invalid values
        plotLine(currentPoints);
    } while (!inFile.eof());
    
    inFile.close();
}


void checkForErrors(Points points, int lineNum)
{
    //check if any color values are out of range
    if (points.redValue<COLORMIN || points.redValue>COLORMAX || points.greenValue<COLORMIN || points.greenValue>COLORMAX || points.blueValue<COLORMIN || points.blueValue>COLORMAX)
    {
        cout <<"ERROR: Color value not between " <<COLORMIN <<" and " <<COLORMAX <<" on line " <<lineNum <<" of points.in\n";
        exit(1);
    }

    //check the starting point is out of range of the window
    if (points.x > XMAX || points.y > YMAX)
    {
        cout <<"ERROR: Starting position out of window range " <<XMAX <<" by " <<YMAX <<" on line " <<lineNum <<" of points.in\n";
        exit(1);
    }

    //check if the set of points will extend out of range of the window
    int endX = points.x + (points.deltaX * points.reps);
    if (endX > XMAX || endX < 0)
    {
        cout <<"ERROR: Line extends out of X range of 0 to " <<XMAX <<" on line " <<lineNum <<" of points.in\n";
        exit(1);
    }
    int endY = points.y + (points.deltaY * points.reps);
    if (endY > YMAX || endY < 0)
    {
        cout <<"ERROR: Line extends out of Y range of 0 to " <<YMAX <<" on line " <<lineNum <<" of points.in\n";
        exit(1);
    }
}


void plotLine(Points currentPoints)
{
    //set the color for this set of points and store the starting X and Y values as current
    glColor3f(currentPoints.redValue, currentPoints.greenValue, currentPoints.blueValue);
    int currentX = currentPoints.x;
    int currentY = currentPoints.y;
    //draw every point in this set of points
    for (int i=0; i<currentPoints.reps; i++)
    {
        glBegin(GL_POINTS);
        glVertex2i(currentX, currentY);
        glEnd();
        glFlush();
        currentX = currentX + currentPoints.deltaX;
        currentY = currentY + currentPoints.deltaY;
    }
}
