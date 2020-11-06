//main.cpp
#include "plotPoints.h"

//initialize GL window and call plotPoints
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("It's Full of Points!");
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(plotPoints);
    glutMainLoop();
    return 0;
}
