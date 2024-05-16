#include "tetris.h"
#include "tetromino.h"
#include <iostream>
using tetromino_namespace::directions;
using tetromino_namespace::shapes;
using tetromino_namespace::Tetromino;
using namespace tetris_namespace;
using namespace std;
int main() {
    char type;
    int x, y;
    cout << "Creating objects of class tetris and tetromino" << endl;
    Tetris *tetrisPtr = new Tetris(10, 10);
    Tetromino *tetrominoPtr = new Tetromino(shapes::O);
    cout << "Objects created" << endl;
    cout << "Start of tetris class functions\n"
         << endl;
    tetrisPtr->createTable();
    cout << "createTable Done" << endl;
    tetrisPtr->draw();
    cout << "draw Done" << endl;
    Tetris::random();
    cout << "random Done" << endl;
    tetrisPtr->lengthOfStack();
    cout << "lengthOfStack Done" << endl;
    tetrisPtr->isMovable(*tetrominoPtr);
    cout << "isMovable Done" << endl;
    *tetrisPtr += *tetrominoPtr;
    tetrisPtr->draw();
    tetrisPtr->createTable();
    cout << "+= operator Done" << endl;
    tetrisPtr->animate(*tetrominoPtr);
    cout << "Functions of tetris class Done" << endl;
    cout << "Start of tetromino class functions\n"
         << endl;
    tetrominoPtr->getColumn();
    cout << "getColumn Done" << endl;
    tetrominoPtr->getTetromino();
    cout << "getTetromino Done" << endl;
    tetrominoPtr->getRow();
    cout << "getRow Done" << endl;
    tetrominoPtr->printTetromino();
    cout << "printTetromino Done" << endl;
    tetrominoPtr->rotate(directions::a);
    cout << "rotate Done" << endl;
    cout << "Functions of tetromino class Done" << endl;
}