#pragma once
#include <cmath>

const int TWIDTH = 100;
const int THEIGHT = 100;

struct TCell
{
    TCell();
    void Draw(int x, int y);
    float r;// red value
    float g;// green value
    float b;// blue value
    double z; // height value
};

class TMaze
{
public:
    TMaze();
    //void RemoveWalls();
    //void RemoveWallsR(int i, int j);
    void Draw();
    double GetZ(double x, double y){return (2 * sin(.4*y)+1.5 * cos(.3*x)+4 * sin(.2*x)*cos(.3*y)+6 * sin(.11*x)*cos(.03*y)*.9);};
    bool IsSafe(double x, double y, double r);// modify to tell hieht of next step so can be placed apporpeiatly

private:
    TCell cells[TWIDTH][THEIGHT];
};
