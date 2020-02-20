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
    void SpinLeft();
    void SpinRight();
    void ScurryForward();
    void ScurryBackward();
    void Draw();
    void RatView();
private:
    double x;
    double y;
    double degrees;
};

#endif /* Rat_hpp */
