#include "tetris.h"
#include "tetromino.h"
#include <iostream>
using namespace tetromino_namespace;
using namespace tetris_namespace;
using namespace std;
int main() {
    int row, column;
    char type;
    cout << "Tetris board size: ";
    cin >> row >> column;
    while (row < 8 || column < 8 || cin.fail()) { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> row >> column;
    }
    Tetris *tetrisPtr = new Tetris(row, column);
    tetrisPtr->createTable();
    while (true) {
        cout << "Tetromino type (Q: for quit, R: for random): ";
        cin >> type;
        shapes tempShape = static_cast<shapes>(type);
        options tempOption = static_cast<options>(type);
        while (!(tempShape == shapes::I || tempShape == shapes::J || tempShape == shapes::L || tempShape == shapes::O || tempShape == shapes::S ||tempShape == shapes::T || tempShape == shapes::Z || tempOption == options::R || tempOption == options::Q) || cin.fail()) { // exception handling
            cin.clear();
            cin.ignore(256, '\n');
            cerr << "Error, Try again: ";
            cin >> type;
            tempShape = static_cast<shapes>(type);
            tempOption = static_cast<options>(type);
        }
        if (tempOption == options::R) // random tetromino
            type = Tetris::random();

        if (tempOption == options::Q) { // program quit
            cout << endl
                 << "Program Terminated" << endl;
            delete tetrisPtr;
            exit(0);
        }
        Tetromino *tetrominoPtr = new Tetromino(static_cast<shapes>(type));
        tetrisPtr->animate(*tetrominoPtr);
        delete tetrominoPtr;
    }
    delete tetrisPtr;
}