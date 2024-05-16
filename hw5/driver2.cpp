#include "tetris.h"
#include "tetromino.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace tetris_namespace;
int main()
{
    int row, col;
    char type, typeofTetris;
    askRowCol(row, col);
    askTetrisType(typeofTetris);
    TetrisVector obj1(row, col);
    TetrisArray1D obj2(row, col);
    TetrisAdapter<vector<vector<char>>, vector<char>> obj3(row, col);
    while (true)
    {
        askType(type);
        Tetromino obj4(static_cast<shapes>(type));
        if (typeofTetris == 'V')
            obj1.animate(obj4);
        else if (typeofTetris == '1')
            obj2.animate(obj4);
        else
            obj3.animate(obj4);
    }
}