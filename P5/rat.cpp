//
//  Rat.cpp
//  Prog5
//
//  Created by Caleb J. Delaney on 2/20/20.
//  Copyright © 2020 Caleb J. Delaney. All rights reserved.
//

#include "Rat.hpp"
#include <cmath>
#include <GLUT/glut.h>

Rat::Rat(){
    x = 2.5;
    y = .5;
    degrees = 90.;
}

void Rat::SpinLeft(){
    degrees += .05 * 30;
}
void Rat::SpinRight(){
    degrees -= .05 * 30;
}
void Rat::ScurryForward(){
    double radians = degrees * 3.1415926 / 180.;
    double dx = std::cos(radians);
    double dy = std::sin(radians);
    double SPEED = .001;
    //        if (pMaze->IsSafe(x + dx * SPEED, y + dy * SPEED, fat))
    {
        x += dx * SPEED * 30;
        y += dy * SPEED * 30;
    }
    //        else if

    //        else if
}
void Rat::ScurryBackward(){
    double radians = degrees * 3.1415926 / 180.;
    double dx = std::cos(radians);
    double dy = std::sin(radians);
    double SPEED = .001;
    {
        x -= dx * SPEED * 30;
        y -= dy * SPEED * 30;
    }
}
void Rat::Draw(){
    glPushMatrix();
    glTranslated(x, y, 0);
    glRotated(degrees, 0, 0, 1);
    glScaled(.5, .5, 1.0);
    {
        glBegin(GL_TRIANGLES);
        glVertex2d(.5,0);
        glVertex2d(-.3,.2);
        glVertex2d(-.3,-.2);
        glEnd();
    }
    glPopMatrix();
}
void Rat::RatView(){
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    // camera is not good is locked by position need to find out how to get it to rotate with degrees
    gluLookAt(x, y, .5, x+1, y+1, 0, 0, 0, 1);
}
