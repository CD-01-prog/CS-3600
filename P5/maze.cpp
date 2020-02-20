#include <vector>
#include <cstdlib>
#include <GLUT/glut.h>
#include "graphics.h"
#include "maze.h"

Cell::Cell()
{
    left = top = right = bottom = true;
    visited = false;
}
void Cell::Draw(int x, int y)
{
    // draw walls as GL_LINES
    if (current_view != top_view)
    {
    glColor3d(0, 0, 0);
    if (left)
        DrawLine(x, y, x, y + 1);
    {
        
        glColor3d(0.2,0.7,0.3);//green
        glBegin(GL_QUADS);
        glVertex3i(x, y, 0);
        glVertex3i(x, y + 1, 0);
        glVertex3i(x, y + 1, 1);
        glVertex3i(x, y, 1);
        glEnd();
    }
    if (top)
        DrawLine(x, y + 1, x + 1, y + 1);
    {
        glColor3d(0,0,1);//blue
        glBegin(GL_QUADS);
        glVertex3i(x, y, 0);
        glVertex3i(x+1, y, 0);
        glVertex3i(x+1, y, 1);
        glVertex3i(x, y, 1);
        glEnd();
    }
    if (right)
        DrawLine(x + 1, y + 1, x + 1, y);
    {
        glColor3d(0,1,1);// aqua
        glBegin(GL_QUADS);
        glVertex3i(x, y+1, 0);
        glVertex3i(x, y, 0);
        glVertex3i(x, y, 1);
        glVertex3i(x, y+1, 1);
    glEnd();
    }
    if (bottom)
        DrawLine(x + 1, y, x, y);
    {
           glColor3d(0,0,0);// black
           glBegin(GL_QUADS);
           glVertex3i(x+1, y, 0);
           glVertex3i(x, y, 0);
           glVertex3i(x, y, 1);
           glVertex3i(x+1, y, 1);
           glEnd();
       }
    }
    else
    {
        if (left)
            glColor3d(0.2,0.7,0.3);//green
            DrawLine(x, y, x, y + 1);
        if (top)
            glColor3d(0,0,1);//blue
            DrawLine(x, y + 1, x + 1, y + 1);
        if (right)
            glColor3d(0,1,1);// aqua
            DrawLine(x + 1, y + 1, x + 1, y);
        if (bottom)
            glColor3d(0,0,0);
            DrawLine(x + 1, y, x, y);
        
        // draw walls as GL_QUADS
        // figure out a way to draw each wall in a different color. (you don't have to save the color of the wall)
        // figure out a way to prevent two co-planar wall from 'bleeding' on top of each other when drawing.
    }

}



Maze::Maze()
{

}
void Maze::RemoveWalls()
{
    RemoveWallsR(0, 0);

    // Remove top and bottom wall
}

void Maze::RemoveWallsR(int i, int j)
{
    cells[i][j].visited = true;

    while (true)
    {
        // record legal possibilitites between LEFT, UP, RIGHT, DOWN
        enum MOVES { LEFT, UP, RIGHT, DOWN };
        std::vector<MOVES> moves;

        // check for a legal LEFT move
        if (i - 1 >= 0 && !cells[i - 1][j].visited)
        {
            moves.push_back(LEFT);
        }/*
        if (i + 1 <= 1 && !cells[i+1][j].visited)
        {
            moves.push_back(RIGHT);
        }
        if (j + 1  <= 1 && !cells[i][j+1].visited)
        {
            moves.push_back(UP);
        }
        if(j-1 >= 0 && !cells[i][j-1].visited)
        {
            moves.push_back(DOWN);
        }
*/
        if (moves.size() == 0)
        {
            return;
        }

        // pick which direction randomly
        int r = rand() % moves.size();

        if (moves[r] == LEFT)
        {
            cells[i][j].left = false;
            cells[i - 1][j].right = false;
            RemoveWallsR(i - 1, j);
        }/*
        if (moves[r] == RIGHT)
        {
            cells[i-1][j].right = false;
            cells[i][j].left = false;
            RemoveWallsR(i - 1, j);
        }
        if (moves[r] == UP)
        {
            cells[i][j-1].top = false;
            cells[i][j].bottom = false;
            RemoveWallsR(i, j-1);
        }
        if (moves[r] == DOWN)
        {
            cells[i][j].bottom = false;
            cells[i][j-1].top = false;
            RemoveWallsR(i, j-1);
        }*/

    }

}

void Maze::Draw()
{
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            cells[i][j].Draw(i, j);
    RemoveWalls();
}
