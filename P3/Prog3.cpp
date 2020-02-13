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
class circle{
    public:
    circle();
    circle(double x,double y,double radius,double r,double g,double b, double dx, double dy);
    
    double getx() {return x;}
    void setx(double nx) {x = nx;}
    double gety() {return y;}
    void sety(double ny) {y = ny;}
    double getradius() {return radius;}
    void setradius(double nradius) {radius = nradius;}
    
    double getr() {return r;};
    void setr(double nr) {r = nr;}
    double getg() {return g;};
    void setg(double ng) {g = ng;}
    double getb() {return b;};
    void setb(double nb) {b = nb;}
    
    double getdx() {return xDir;}
    double getdy() {return yDir;}
    double getnextx() { return x + xDir; }
    double getnexty() { return y + yDir; }

    void setdx(double dx) { xDir = dx; }
    void setdy(double dy) { yDir = dy; }

    void step(int myself, circle all[], int count);
    private:
    double x,y,radius;
    double xDir, yDir;
    double r,g,b;
    };
circle::circle(double x, double y, double radius, double r, double g, double b, double dx, double dy){
    x = x;
    y = y;
    radius = radius;
    r = r;
    g = g;
    b = b;
    xDir = dx;
    yDir = dy;
}
    
/*
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
*/

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
    circle(50,50,20,0,0,1,1,1);
    /*
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
*/
    // Test lines that draw all three shapes and some text.
    // Delete these when you get your code working.
    //glColor3d(0,0,1);
    //DrawRectangle(gX, gY, gX+ size, gY+ size);

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
