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
double cvx1 = 50;
double cvy1 = 50;

double cx2 = 500;
double cy2 = 505;
double cs2 = 10;
double cvx2 = 5;
double cvy2 = 1;

double cx3 = 650;
double cy3 = 650;
double cs3 = 40;
double cvx3 = 1;
double cvy3 = 5;

double cx4 = 300;
double cy4 = 350;
double cs4 = 24;
double cvx4 = 0.89;
double cvy4 = 1;

double cx5 = 225;
double cy5 = 40;
double cs5 = 36;
double cvx5 = 1;
double cvy5 = 0.89;

double cx6 = 195;
double cy6 = 525;
double cs6 = 42;
double cvx6 = 10;
double cvy6 = 5;

double cx7 = 590;
double cy7 = 75;
double cs7 = 15;
double cvx7 = 7;
double cvy7 = 5;

double cx8 = 175;
double cy8 = 30;
double cs8 = 9;
double cvx8 = 4;
double cvy8 = 9;

double cx9 = 30;
double cy9 = 425;
double cs9 = 30;
double cvx9 = 4;
double cvy9 = 4;

double cx10 = 180;
double cy10 = 180;
double cs10 = 28;
double cvx10 = 1;
double cvy10 = 1;


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
    //glColor3d(0,0,1);
    //DrawRectangle(gX, gY, gX+ size, gY+ size);
//should be able to make this just a loop with random values seems i can also make a class that holds all of this
    
    
    glColor3d(0,0,1);
    if (cx1 + cvx1 + cs1 > screen_x)
        cvx1 = -cvx1;
    if (cx1 + cvx1 < 0+cs1)
        cvx1 = -cvx1;
    cx1 += cvx1;
    if (cy1 + cvy1 + cs1 > screen_y)
        cvy1 = -cvy1;
    if (cy1 + cvy1 < 0 + cs1)
        cvy1 = -cvy1;
    cy1 += cvy1;
    DrawCircle(cx1,cy1,cs1);
    
    glColor3d(0.2,0.7,0.3);
   if (cx2 + cvx2 + cs2 > screen_x)
       cvx2 = -cvx2;
   if (cx2 + cvx2 < 0 + cs2)
       cvx2 = -cvx2;
   cx2 += cvx2;
   if (cy2 + cvy2 + cs2 > screen_y)
       cvy2 = -cvy2;
   if (cy2 + cvy2 < 0 + cs2)
       cvy2 = -cvy2;
   cy2 += cvy2;
    DrawCircle(cx2,cy2,cs2);
    
    glColor3d(0,0,0);
    if (cx3 + cvx3 + cs3 > screen_x)
        cvx3 = -cvx3;
    if (cx3 + cvx3 < 0 + cs3)
        cvx3 = -cvx3;
    cx3 += cvx3;
    if (cy3 + cvy3 + cs3 > screen_y)
        cvy3 = -cvy3;
    if (cy3 + cvy3 < 0 + cs3)
        cvy3 = -cvy3;
    cy3 += cvy3;
    DrawCircle(cx3,cy3,cs3);
    
    glColor3d(0.5,0.1,1);
    if (cx4 + cvx4 + cs4 > screen_x)
        cvx4 = -cvx4;
    if (cx4 + cvx4 < 0 + cs4)
        cvx4 = -cvx4;
    cx4 += cvx4;
    if (cy4 + cvy4 + cs4 > screen_y)
        cvy4 = -cvy4;
    if (cy4 + cvy4 < 0 + cs4)
        cvy4 = -cvy4;
    cy4 += cvy4;
    DrawCircle(cx4,cy4,cs4);
    
    glColor3d(0.8,0.2,1);
    if (cx5 + cvx5 + cs5 > screen_x)
        cvx5 = -cvx5;
    if (cx5 + cvx5 < 0 + cs5)
        cvx5 = -cvx5;
    cx5 += cvx5;
    if (cy5 + cvy5 + cs5 > screen_y)
        cvy5 = -cvy5;
    if (cy5 + cvy5 < 0 + cs5)
        cvy5 = -cvy5;
    cy5 += cvy5;
    DrawCircle(cx5,cy5,cs5);
    
    glColor3d(0,0,5);
    if (cx6 + cvx6 + cs6 > screen_x)
        cvx6 = -cvx6;
    if (cx6 + cvx6 < 0 + cs6)
        cvx6 = -cvx6;
    cx6 += cvx6;
    if (cy6 + cvy6 + cs6 > screen_y)
        cvy6 = -cvy6;
    if (cy6 + cvy6 < 0 + cs6)
        cvy6 = -cvy6;
    cy6 += cvy6;
    DrawCircle(cx6,cy6,cs6);
    
    glColor3d(0.9,0.77,0.2);
    if (cx7 + cvx7 + cs7 > screen_x)
        cvx7 = -cvx7;
    if (cx7 + cvx7 < 0 + cs7)
        cvx7 = -cvx7;
    cx7 += cvx7;
    if (cy7 + cvy7 + cs7 > screen_y)
        cvy7 = -cvy7;
    if (cy7 + cvy7 < 0 + cs7)
        cvy7 = -cvy7;
    cy7 += cvy7;
    DrawCircle(cx7,cy7,cs7);
    
    glColor3d(0,0,0);
    if (cx8 + cvx8 + cs8 > screen_x)
        cvx8 = -cvx8;
    if (cx8 + cvx8 < 0 + cs8)
        cvx8 = -cvx8;
    cx8 += cvx8;
    if (cy8 + cvy8 + cs8 > screen_y)
        cvy8 = -cvy8;
    if (cy8 + cvy8 < 0 + cs8)
        cvy8 = -cvy8;
    cy8 += cvy8;
    DrawCircle(cx8,cy8,cs8);
    
    glColor3d(1,0,1);
    if (cx9 + cvx9 + cs9 > screen_x)
        cvx9 = -cvx9;
    if (cx9 + cvx9 < 0 + cs9)
        cvx9 = -cvx9;
    cx9 += cvx9;
    if (cy9 + cvy9 + cs9 > screen_y)
        cvy9 = -cvy9;
    if (cy9 + cvy9 < 0 + cs9)
        cvy9 = -cvy9;
    cy9 += cvy9;
    DrawCircle(cx9,cy9,cs9);
    
    glColor3d(0,1,1);
    if (cx10 + cvx10 + cs10 > screen_x)
        cvx10 = -cvx10;
    if (cx10 + cvx10 < 0 + cs10)
        cvx10 = -cvx10;
    cx10 += cvx10;
    if (cy10 + cvy10 + cs10 > screen_y)
        cvy10 = -cvy10;
    if (cy10 + cvy10 < 0 + cs10)
        cvy10 = -cvy10;
    cy10 += cvy10;
    DrawCircle(cx10,cy10,cs10);
    

    glutPostRedisplay();
    glutSwapBuffers();
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

