//
//  main.cpp
//  Prog3
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
#include <vector>
#include <GLUT/glut.h>
#include <iostream>


// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 700;
const double COLLISION_FRICTION = 1.0;
const double Gravity = .5;
int i;

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

class Circle
{
private:
    double cx;// circle x
    double cy;// circle y
    double cvx;// circle velocity x
    double cvy;// circle velocity y
    double cs;// circle size
    double cr;// red
    double cg;// green
    double cb;// blue
    bool collide;
public:
    Circle();
    Circle(double x,double y,double r,double g,double b,double vx,double vy,double cs);
    void updatepostion();
    double getCX(){return cx;}
    double getCY(){return cy;}
    double getCVX(){return cvx;}
    double getCVY(){return cvy;}
    double getCS(){return cs;}
    double getR(){return cr;}
    double getB(){return cb;}
    double getG(){return cg;}
    double getnextx() {return cx + cvx;}
    double getnexty() {return cy + cvy;}
    bool getCollide(){return collide;)
    void setCX(double x){cx = x;}
    void setCY(double y){cy = y;}
    void setCVX(double vx){cvx = vx;}
    void setCVY(double vy){cvy = vy;}
    void setCS(double s){cs = s;}
    void setR(double nr){cr = nr;}
    void setB(double nb){cb = nb;}
    void setG(double ng){cg = ng;}
    void setCollide(bool answer){collide = answer;}
    
};
Circle::Circle(){
    cx = 0;
    cy = 0;
    cvx = 0;
    cvy = 0;
    cs = 10;
}
void Circle::updatepostion(){
    cvy -= Gravity;
    if (cx + cvx + cs > screen_x)
        cvx = -cvx;
    if (cx + cvx < cs)
        cvx = -cvx;
    if (cy + cvy + cs > screen_y)
        cvy = -cvy;
    if (cy + cvy < cs)
        cvy = -cvy;
    bool collideCheck = false;
    for(int j=i+1;j<map.length();j++){
        if(sqrt(pow(map[i].getnextx() - map[j].getnextx,2) + pow(map[i].getnexty()-map[j].getnexty(),2)) < map[i].getCS() + map[j].getCS()){
           collideCheck = true;
           if(!map[i].getCollide){
               Collide(i,j);
               map[i].setCollide(true);
        }
    }
    if (!collideCheck){
       map[i].setCollide(false);
    }
    cx += cvx;
    cy += cvy;
    glColor3d(cr,cg,cb);
    DrawCircle(cx,cy,cs);
}
Circle::Circle(double x,double y,double r,double g,double b,double vx,double vy,double s){
    cx = x;
    cy = y;
    cvx = vx;
    cvy = vy;
    cs = s;
    cr = r;
    cb = b;
    cg = b;
    glColor3d(cr,cg,cb);
    DrawCircle(x,y,s);
 }
std::vector<Circle> map;
//collide code

struct vectortype
{
    double x;
    double y;
};

void Collide(int p1, int p2)
{
    vectortype en; // Center of Mass coordinate system, normal component
    vectortype et; // Center of Mass coordinate system, tangential component
    vectortype u[2]; // initial velocities of two map
    vectortype um[2]; // initial velocities in Center of Mass coordinates
    double umt[2]; // initial velocities in Center of Mass coordinates, tangent component
    double umn[2]; // initial velocities in Center of Mass coordinates, normal component
    vectortype v[2]; // final velocities of two map
    double m[2];    // mass of two map
    double M; // mass of two map together
    vectortype V; // velocity of two map together
    double size;
    int i;

    double xdif=map[p1].getnextx() - map[p2].getnextx();
    double ydif=map[p1].getnexty() - map[p2].getnexty();

    // set Center of Mass coordinate system
    size=sqrt(xdif*xdif + ydif*ydif);
    xdif/=size; ydif/=size; // normalize
    en.x=xdif;
    en.y=ydif;
    et.x=ydif;
    et.y=-xdif;

    // set u values
    u[0].x=map[p1].getCVX();
    u[0].y=map[p1].getCVY();
    m[0]=map[p1].getCS()*map[p1].getCS();
    u[1].x=map[p2].getCVX();
    u[1].y=map[p2].getCVY();
    m[1]=map[p2].getCS()*map[p2].getCS();

    // set M and V
    M=m[0]+m[1];
    V.x=(u[0].x*m[0] + u[1].x*m[1])/M;
    V.y=(u[0].y*m[0] + u[1].y*m[1])/M;

    // set um values
    um[0].x=m[1]/M * (u[0].x-u[1].x);
    um[0].y=m[1]/M * (u[0].y-u[1].y);
    um[1].x=m[0]/M * (u[1].x-u[0].x);
    um[1].y=m[0]/M * (u[1].y-u[0].y);

    // set umt and umn values
    for(i=0;i<2;i++)
    {
        umt[i] = um[i].x * et.x + um[i].y * et.y;
        umn[i] = um[i].x * en.x + um[i].y * en.y;
    }

    // set v values
    for(i=0;i<2;i++)
    {
        v[i].x = umt[i] * et.x - umn[i] * en.x + V.x;
        v[i].y = umt[i] * et.y - umn[i] * en.y + V.y;
    }

    // reset particle values
    map[p1].setCVX(v[0].x*COLLISION_FRICTION);
    map[p1].setCVY(v[0].y*COLLISION_FRICTION);
    map[p2].setCVX(v[1].x*COLLISION_FRICTION);
    map[p2].setCVY(v[1].y*COLLISION_FRICTION);

} /* Collide */

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
    
    for(i=0; i<map.length()+1;i++){
    map[i].updateposition();   
    }
    
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
    //x , y, r, g, b , vx, vy, s
    Circle c1 = Circle(50,50,0,0,1,50,50,20);
    Circle c2 = Circle(500,505,.2,.7,.3,5,1,10);
    Circle c3 = Circle(650,650,1,0,0,1,5,40);
    Circle c4 = Circle(300,350,.5,.1,1,.89,1,24);
    Circle c5 = Circle(225,40,.8,.2,1,1,.89,36);
    Circle c6 = Circle(195,525,0.8,0.8,.8,10,5,42);
    Circle c7 = Circle(590,75,.9,.77,.2,7,5,15);
    Circle c8 = Circle(175,30,0,1,0,4,9,9);
    Circle c9 = Circle(30,425,1,1,0,4,4,30);
    Circle c10 = Circle(180,180,0,1,1,1,1,28);
    map.push_back(c1);
    map.push_back(c2);
    map.push_back(c3);
    map.push_back(c4);
    map.push_back(c5);
    map.push_back(c6);
    map.push_back(c7);
    map.push_back(c8);
    map.push_back(c9);
    map.push_back(c10);
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
