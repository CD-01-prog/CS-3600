//
//  main.cpp
//  House_test
//
//  Created by Caleb J. Delaney on 2/21/20.
//  Copyright © 2020 Caleb J. Delaney. All rights reserved.
//

#include <cmath>
#include <cstring>
#include <iostream>

#include <GLUT/GLUT.h>

// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 700;

void DrawCircle(double x1, double y1, double radius)
{
    glBegin(GL_TRIANGLE_STRIP);
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

void DrawLine(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
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
void display(void)
{
    //set up
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    
    //looking
    gluLookAt(-100, -500, 500, 0, 0, 0, 0, 0, 1);
    //set up the grass
    glColor3d(0.0,0.99,0.0);
    DrawCircle(0,0,250);
    
    //floor
    glColor3d(0.0, 0.0, .99);
    //DrawRectangle(0,0,200,100);
    
    //set up the walls
    //left
    DrawLine(0, 0, 0, 100);
    glColor3d(0.0, 0.0, .99);
    glBegin(GL_QUADS);
    glVertex3i(0, 0, 0);
    glVertex3i(0, 100, 0);
    glVertex3i(0, 100, 20);
    glVertex3i(0, 0, 20);
    glEnd();
    //right
    DrawLine(200,0, 200, 100);
    glColor3d(0.0, 0.0, .99);
    glBegin(GL_QUADS);
    glVertex3i(200, 0, 0);
    glVertex3i(200, 100, 0);
    glVertex3i(200, 100, 20);
    glVertex3i(200, 0, 20);
    glEnd();
    
    //back
    DrawLine(0,100,200,100);
    glColor3d(0.0, 0.0, .99);
    glBegin(GL_QUADS);
    glVertex3i(0, 100, 0);
    glVertex3i(200, 100, 0);
    glVertex3i(200, 100, 20);
    glVertex3i(0, 100, 20);
    glEnd();
    
    //front
    DrawLine(0,0,200,0);
    glColor3d(0.0, 0.0, .99);
    glBegin(GL_QUADS);
    glVertex3i(0, 0, 0);
    glVertex3i(200, 0, 0);
    glVertex3i(200, 0, 20);
    glVertex3i(0, 0, 20);
    glEnd();

    //set up the roof
    
    //left side
    glColor3d(.99,0,0);
    
    glColor3d(.99,0,0);
    glBegin(GL_QUADS);
    glVertex3i(0,0,20);
    glVertex3i(0,100,20);
    glVertex3i(100,100,50);
    glVertex3i(0,100,50);
    glEnd();
    //right side
    glColor3d(.99,0,0);
    glBegin(GL_QUADS);
    glVertex3i(100,100,50);
    glVertex3i(200,100,50);
    glVertex3i(200,0,20);
    glVertex3i(100,0,20);
    glEnd();

    glutSwapBuffers();
    glutPostRedisplay();}


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
void SetPerspectiveView(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double aspectRatio = (GLdouble) w/(GLdouble) h;
    gluPerspective(
    /* field of view in degree */ 38.0,
    /* aspect ratio */ aspectRatio,
    /* Z near */ .1, /* Z far */ 3000.0);
    glMatrixMode(GL_MODELVIEW);
}
// This callback function gets called by the Glut
// system whenever the window is resized by the user.
// reshape:
void reshape(int w, int h)
{
    screen_x = w;
    screen_y = h;
    glViewport(0, 0, w, h);
    
    SetPerspectiveView(w,h);
    
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
        glutCreateWindow("a house");
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
