#include <vector>
#include <cstdlib>
#include <GLUT/glut.h>
#include "graphics.hpp"
#include "maze.hpp"

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
        if (left){
        glColor3d(0.2,0.7,0.3);//green
        glBegin(GL_QUADS);
        glVertex3d(x, y, 0);
        glVertex3d(x, y + 1, 0);
        glVertex3d(x, y + 1, 1);
        glVertex3d(x, y, 1);
        glEnd();
    }
        if (top){
        glColor3d(0,0,1);//blue
        glBegin(GL_QUADS);
        glVertex3d(x, y+1, 0);
        glVertex3d(x+1, y+1, 0);
        glVertex3d(x+1, y+1, 1);
        glVertex3d(x, y+1, 1);
        glEnd();
    }
        if (right && x == WIDTH-1){
        glColor3d(0.2,0.7,0.3);
        glBegin(GL_QUADS);
        glVertex3d(x+1, y+1, 0);
        glVertex3d(x+1, y, 0);
        glVertex3d(x+1, y, 1);
        glVertex3d(x+1, y+1, 1);
    glEnd();
    }
        if (bottom && y == 0){
           glColor3d(0,0,1);
           glBegin(GL_QUADS);
           glVertex3d(x+1, y, 0);
           glVertex3d(x, y, 0);
           glVertex3d(x, y, 1);
           glVertex3d(x+1, y, 1);
           glEnd();
        
        }}else
    {
        if (left)
          DrawLine(x, y, x, y + 1);
        if (top)
          DrawLine(x, y + 1, x + 1, y + 1);
        if (right)
          DrawLine(x + 1, y + 1, x + 1, y);
        if (bottom)
          DrawLine(x + 1, y, x, y);
    }

}



Maze::Maze()
{
    RemoveWalls();
}
void Maze::RemoveWalls()
{
    srand(time(0));
    cells[0][0].bottom= false;
    RemoveWallsR(0, 0);
    cells[WIDTH-1][HEIGHT-1].top=false;

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
        }
        if (i+1 < WIDTH && !cells[i+1][j].visited)
        {
            moves.push_back(RIGHT);
        }
        if (j+1 < HEIGHT && !cells[i][j+1].visited)
        {
            moves.push_back(UP);
        }
        if(j-1 >= 0 && !cells[i][j-1].visited)
        {
            moves.push_back(DOWN);
        }
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
        }
        if (moves[r] == RIGHT)
        {
            cells[i][j].right = false;
            cells[i+1][j].left = false;
            RemoveWallsR(i + 1, j);
        }
        if (moves[r] == UP)
        {
            cells[i][j].top = false;
            cells[i][j+1].bottom = false;
            RemoveWallsR(i, j+1);
        }
        if (moves[r] == DOWN)
        {
            cells[i][j].bottom = false;
            cells[i][j-1].top = false;
            RemoveWallsR(i, j-1);
        }

    }

}

void Maze::Draw()
{
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            cells[i][j].Draw(i, j);
}
// gets stuck in wall since angle affects dx and dy
bool Maze::IsSafe(double x,double y, double r){
    int i = (int)x;
    int j = (int)y;
    double size = .2; // comes from rat size if change need to update for rat
    x=x-i;
    y=y-j;
    if (cells[i][j].right && x+size > 1.0) {
            return false;
    }else if (cells[i][j].left && x-size < 0.0) {
            return false;
    }else if (cells[i][j].top && y+size > 1.0) {
            return false;
    }else if (cells[i][j].bottom && y-size < 0.0) {
            return false;
    }

    if (x+size > 1.0 && y-size < 0.0) {
            return false;
    }else if (x+size > 1.0 && y+size >1.0) {
            return false;
    } else if (x-size < 0.0 && y-size < 0.00) {
            return false;
    } else if (x-size < 0.0 && y+size > 1.0) {
            return false;
    }

    return true;
}
