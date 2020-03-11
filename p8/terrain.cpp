#include <vector>
#include <cstdlib>
#include <GLUT/glut.h>
#include "graphics.hpp"
#include "terrain.hpp"

TCell::TCell()
{
    r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    z = 0;
}
void TCell::Draw(int x, int y)
{
    // draw walls as GL_LINES
    {
           glColor3d(r,g,b);
           glBegin(GL_QUADS);
           glVertex3d(x, y, z);
           glVertex3d(x+1, y, z);
           glVertex3d(x+1, y+1, z);
           glVertex3d(x, y+1, z);
           glEnd();
        
        }
    }

TMaze::TMaze(){

}
void TMaze::Draw()
{
    for (int i = 0; i < TWIDTH; i++)
        for (int j = 0; j < THEIGHT; j++)
            cells[i][j].Draw(i, j);
}
