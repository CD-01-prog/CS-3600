//
//  main.cpp
//  Prog2
//
//  Created by Caleb J. Delaney on 1/10/20.
//  Copyright © 2020 Caleb J. Delaney. All rights reserved.
//

// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//        and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <GLUT/glut.h>


// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 700;
double gX = 200;
double gY = 200;
double gDX = 0.1;
double gDY = 0.07;
// very bad next assignment just make a class it will be easier i mean like that is what all classes teach me to do
double cx1 = 50;
double cy1 = 50;
double cs1 = 20;
double cv1 = 1;
double cx2 = 500;
double cy2 = 505;
double cs2 = 20;
double cv2 = 1;
double cx3 = 650;
double cy3 = 650;
double cs3 = 20;
double cv3 = 1;
double cx4 = 300;
double cy4 = 350;
double cs4 = 20;
double cv4 = 1;
double cx5 = 225;
double cy5 = 40;
double cs5 = 20;
double cv5 = 1;
double cx6 = 195;
double cy6 = 525;
double cs6 = 20;
double cv6 = 1;
double cx7 = 590;
double cy7 = 75;
double cs7 = 20;
double cv7 = 1;
double cx8 = 175;
double cy8 = 30;
double cs8 = 20;
double cv8 = 1;
double cx9 = 30;
double cy9 = 425;
double cs9 = 20;
double cv9 = 1;
double cx10 = 180;
double cy10 = 180;
double cs10 = 20;
double cv10 = 1;

//
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<32; i++)
    {
        double theta = (double)i/32.0 * 2.0 * 3.1415926;
        double x = x1 + radius * cos(theta);
        double y = y1 + radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x2,y1);
    glVertex2d(x2,y2);
    glVertex2d(x1,y2);
    glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glVertex2d(x3,y3);
    glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, char *string)
{
    void *font = GLUT_BITMAP_9_BY_15;

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    int len, i;
    glRasterPos2d(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }

    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    double size = 50;
    if (gX + gDX + size > screen_x)
        gDX = -gDX;
    if (gX + gDX < 0)
        gDX = -gDX;
    if (gY + gDY + size > screen_y)
        gDY = -gDY;
    if (gY + gDY < 0)
        gDY = -gDY;
    gX += gDX;
    gY += gDY;

    // Test lines that draw all three shapes and some text.
    // Delete these when you get your code working.
    glColor3d(0,0,1);
    DrawRectangle(gX, gY, gX+ size, gY+ size);
//should be able to make this just a loop with random values seems i can also make a class that holds all of this
    
    
    glColor3d(0,0,1);
    DrawCircle(cx1,cy1,cs1);
    
    glColor3d(0.2,0.7,0.3);
    DrawCircle(cx2,cy2,cs2);
    
    glColor3d(0,0,0);
    DrawCircle(cx3,cy3,cs3);
    
    glColor3d(0.5,0.1,1);
    DrawCircle(cx4,cy4,cs4);
    
    glColor3d(0.8,0.2,1);
    DrawCircle(cx5,cy5,cs5);
    
    glColor3d(0,0,5);
    DrawCircle(cx6,cy6,cs6);
    
    glColor3d(0.9,0.77,0.2);
    DrawCircle(cx7,cy7,cs7);
    
    glColor3d(0,0,0);
    DrawCircle(cx8,cy8,cs8);
    
    glColor3d(1,0,1);
    DrawCircle(cx9,cy9,cs9);
    
    glColor3d(0,1,1);
    DrawCircle(cx10,cy10,cs10);
    

    glutPostRedisplay();
    glutSwapBuffers();
}
double out_of_bounds_x(double gX, double gDX){
    double size = 50;
    if (gX + gDX + size > screen_x)
        gDX = -gDX;
    if (gX + gDX < 0)
        gDX = -gDX;
    gX += gDX;
    return gX;
}
double out_of_bounds_y(double gY, double gDY){
    double size = 50;
    if (gY + gDY + size > screen_y)
        gDY = -gDY;
    if (gY + gDY < 0)
        gDY = -gDY;
    gY += gDY;
    return gY;
}

// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 27: // escape character means to quit the program
            exit(0);
            break;
        case 'b':
            // do something when 'b' character is hit.
            break;
        default:
            return; // if we don't care, return without glutPostRedisplay()
    }

    glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
    // Reset our global variables to the new width and height.
    screen_x = w;
    screen_y = h;

    // Set the pixel resolution of the final picture (Screen coordinates).
    glViewport(0, 0, w, h);

    // Set the projection mode to 2D orthographic, and set the world coordinates:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    }
    if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
    }
    if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
    {
    }
    glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screen_x, screen_y);
    glutInitWindowPosition(50, 50);

    int fullscreen = 0;
    if (fullscreen)
    {
        glutGameModeString("800x600:32");
        glutEnterGameMode();
    }
    else
    {
        glutCreateWindow("This appears in the title bar");
    }

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);

    glColor3d(0,0,0); // forground color
    glClearColor(1, 1, 1, 0); // background color
    InitializeMyStuff();

    glutMainLoop();

    return 0;
}
