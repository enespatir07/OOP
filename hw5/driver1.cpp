#include "tetris.h"
#include "tetromino.h"
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using namespace tetris_namespace;

int main()
{
    int row, col,rotationCount;
    char type, typeofTetris,rotationDirection;
    TetrisVector vObject(10, 10);
    Tetromino tetrObject(static_cast<shapes>('T'));
    cout << "Start of TetrisVector functions;\n"
         << endl;
    cout << "calling Draw function" << endl;
    cout << "----------------" << endl;
    vObject.draw();
    cout << "----------------" << endl;
    cout << "draw Done" << endl
         << endl
         << endl;
    cout << "calling animate function" << endl;
    cout << "----------------" << endl;
    vObject.animate(tetrObject);
    cout << "----------------" << endl;
    cout << "animate Done" << endl
         << endl
         << endl;
    cout << "calling numberofMoves function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << vObject.numberOfMoves() << endl;
    cout << "----------------" << endl;
    cout << "numberofMoves Done" << endl
         << endl
         << endl;
    cout << "calling lastMove function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << vObject.lastMove() << endl;
    cout << "----------------" << endl;
    cout << "lastMove Done" << endl
         << endl
         << endl;

    cout << "calling lengthOfStack function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << vObject.lengthOfStack() << endl;
    cout << "----------------" << endl;
    cout << "lengthOfStack Done" << endl
         << endl
         << endl;
    cout << "Calling isMovable function" << endl;
    cout << "----------------" << endl;
    cout << vObject.isMovable(tetrObject) << endl;
    cout << "----------------" << endl;
    cout << "isMovable Done" << endl
         << endl
         << endl;

    cout << "Calling writingToFile function" << endl;
    cout << "----------------" << endl;
    vObject.writeToFile();
    cout << "----------------" << endl;
    cout << "writingToFile Done" << endl
         << endl
         << endl;

    cout << "Calling readingFromFile function" << endl;
    cout << "----------------" << endl;
    vObject.readFromFile();
    cout << "----------------" << endl;
    cout << "readingFromFile Done" << endl
         << endl
         << endl;

    TetrisArray1D arrayObject(10, 10);
    cout << endl
         << endl
         << "Start of TetrisArray1D functions;\n"
         << endl;
    cout << "calling Draw function" << endl;
    cout << "----------------" << endl;
    arrayObject.draw();
    cout << "----------------" << endl;
    cout << "draw Done" << endl
         << endl
         << endl;

    cout << "calling animate function" << endl;
    cout << "----------------" << endl;
    arrayObject.animate(tetrObject);
    cout << "----------------" << endl;
    cout << "animate Done" << endl
         << endl
         << endl;

    cout << "calling numberofMoves function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << arrayObject.numberOfMoves() << endl;
    cout << "----------------" << endl;
    cout << "numberofMoves Done" << endl
         << endl
         << endl;
    cout << "calling lastMove function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << arrayObject.lastMove() << endl;
    cout << "----------------" << endl;
    cout << "lastMove Done" << endl
         << endl
         << endl;

    cout << "calling lengthOfStack function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << arrayObject.lengthOfStack() << endl;
    cout << "----------------" << endl;
    cout << "lengthOfStack Done" << endl
         << endl
         << endl;
    cout << "Calling isMovable function" << endl;
    cout << "----------------" << endl;
    cout << arrayObject.isMovable(tetrObject) << endl;
    cout << "----------------" << endl;
    cout << "isMovable Done" << endl
         << endl
         << endl;

    cout << "Calling writingToFile function" << endl;
    cout << "----------------" << endl;
    arrayObject.writeToFile();
    cout << "----------------" << endl;
    cout << "writingToFile Done" << endl
         << endl
         << endl;

    cout << "Calling readingFromFile function" << endl;
    cout << "----------------" << endl;
    arrayObject.readFromFile();
    cout << "----------------" << endl;
    cout << "readingFromFile Done" << endl
         << endl
         << endl;

    TetrisAdapter<deque<deque<char>>, deque<char>> adapterObjectDq(10, 10);
    TetrisAdapter<vector<vector<char>>, vector<char>> adapterObjectVc(10, 10);
    cout << endl
         << endl
         << "Start of TetrisVector functions;\n"
         << endl;
    cout << "calling Draw function" << endl;
    cout << "----------------" << endl;
    adapterObjectDq.draw();
    adapterObjectVc.draw();
    cout << "----------------" << endl;
    cout << "draw Done" << endl
         << endl
         << endl;

    cout << "calling animate function" << endl;
    cout << "----------------" << endl;
    adapterObjectDq.animate(tetrObject);
    adapterObjectVc.animate(tetrObject);
    cout << "----------------" << endl;
    cout << "animate Done" << endl
         << endl
         << endl;

    cout << "calling numberofMoves function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << adapterObjectDq.numberOfMoves() << endl;
    cout << "Output: " << adapterObjectVc.numberOfMoves() << endl;
    cout << "----------------" << endl;
    cout << "numberofMoves Done" << endl
         << endl
         << endl;
    cout << "calling lastMove function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << adapterObjectDq.lastMove() << endl;
    cout << "Output: " << adapterObjectVc.lastMove() << endl;
    cout << "----------------" << endl;
    cout << "lastMove Done" << endl
         << endl
         << endl;

    cout << "calling lengthOfStack function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << adapterObjectDq.lengthOfStack() << endl;
    cout << "Output: " << adapterObjectVc.lengthOfStack() << endl;

    cout << "----------------" << endl;
    cout << "lengthOfStack Done" << endl
         << endl
         << endl;
    cout << "Calling isMovable function" << endl;
    cout << "----------------" << endl;
    cout << adapterObjectDq.isMovable(tetrObject) << endl;
    cout << adapterObjectVc.isMovable(tetrObject) << endl;
    cout << "----------------" << endl;
    cout << "isMovable Done" << endl
         << endl
         << endl;

    cout << "Calling writingToFile function" << endl;
    cout << "----------------" << endl;
    adapterObjectDq.writeToFile();
    cout << "----------------" << endl;
    cout << "writingToFile Done" << endl
         << endl
         << endl;

    cout << "Calling readingFromFile function" << endl;
    cout << "----------------" << endl;
    adapterObjectDq.readFromFile();
    cout << "----------------" << endl;
    cout << "readingFromFile Done" << endl
         << endl
         << endl;

    cout << endl
         << endl
         << "Testing Global Functions;" << endl
         << endl;

    cout << "Calling randomChar function" << endl;
    cout << "----------------" << endl;
    cout << "Output: " << randomChar() << endl;
    cout << "Output: " << randomChar() << endl;
    cout << "Output: " << randomChar() << endl;
    cout << "Output: " << randomChar() << endl;
    cout << "Output: " << randomChar() << endl;
    cout << "----------------" << endl; 
    cout << "randomChar done" << endl
         << endl;

    cout << "Calling askRowCol function" << endl;
    cout << "----------------" << endl;
    askRowCol(row, col);
    cout << "----------------" << endl;
    cout << "askRowCol done" << endl
         << endl;

    cout << "Calling askTetrisType function" << endl;
    cout << "----------------" << endl;
    askTetrisType(typeofTetris);
    cout << "----------------" << endl;
    cout << "askTetrisType done" << endl
         << endl;

    cout << "Calling askType function" << endl;
    cout << "----------------" << endl;
    askType(type);
    cout << "----------------" << endl;
    cout << "askType done" << endl
         << endl;

    cout << "Calling askRotation function" << endl;
    cout << "----------------" << endl;
    askRotation(rotationDirection,rotationCount);;
    cout << "----------------" << endl;
    cout << "askRotation done" << endl
         << endl;
}
