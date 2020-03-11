//
//  Rat.hpp
//  Prog5
//
//  Created by Caleb J. Delaney on 2/20/20.
//  Copyright © 2020 Caleb J. Delaney. All rights reserved.
//

#ifndef Rat_hpp
#define Rat_hpp

#include <stdio.h>
class Rat
{
public:
    Rat();
    double Getx(){return x;};
    double Gety(){return y;};
    double Getz(){return z;};
    double Getdegrees(){return degrees;};
    double Getdx(){return dx;};
    double Getdy(){return dy;};
    double GetSpeed(){return Speed;};
    double Getsize(){return size;};
    void SpinLeft();
    void SpinRight();
    void ScurryForward();
    void ScurryBackward();
    void Draw();
    void RatView();
    
private:
    double x;
    double y;
    double z;
    double degrees;
    double dx;
    double dy;
    double Speed;
    double size;
};

#endif /* Rat_hpp */

