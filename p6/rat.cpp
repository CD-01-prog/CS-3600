//
//  Rat.cpp
//  Prog5
//
//  Created by Caleb J. Delaney on 2/20/20.
//  Copyright © 2020 Caleb J. Delaney. All rights reserved.
//

#include "Rat.hpp"
#include "maze.h"
#include <cmath>
#include <GLUT/glut.h>

Rat::Rat(){
    x = 2.5;
    y = .5;
    degrees = 90.;
    dx = std::cos(degrees * 3.1415926 / 180.);
    dy = std::sin(degrees * 3.1415926 / 180.);
    Speed = .001;
    size = .2;
}

void Rat::SpinLeft(){
    degrees += .05 * 30;
    dx = std::cos(degrees * 3.1415926 / 180.);
    dy = std::sin(degrees * 3.1415926 / 180.);
    
}
void Rat::SpinRight(){
    degrees -= .05 * 30;
    dx = std::cos(degrees * 3.1415926 / 180.);
    dy = std::sin(degrees * 3.1415926 / 180.);
}
void Rat::ScurryForward(){
        x += dx * Speed * 30;
        y += dy * Speed * 30;
}
void Rat::ScurryBackward(){
    x -= dx * Speed * 30;
    y -= dy * Speed * 30;
}
void Rat::Draw(){
    glPushMatrix();
    glTranslated(x, y, 0);
    glRotated(degrees, 0, 0, 1);
    glScaled(.5, .5, 1.0);
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(.3,0);
        glVertex2d(-.3,.2);
        glVertex2d(-.3,-.2);
        glEnd();
    }
    glPopMatrix();
}
void Rat::RatView(){
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    double z_level = .25;
    double at_x = x + dx;
    double at_y = y + dy;
    double at_z = z_level;
    gluLookAt(x,y,z_level,  at_x, at_y, at_z,  0,0,1);
}
