#include "tetris.h"
#include "tetromino.h"
#include <iostream>
using namespace std;

int main() {
    int row, column, numOfbuttom = 0;
    char type;
    vector<vector<char>> temp;
    cout << "Enter the board size: ";
    cin >> row >> column;
    while (!Tetris::isTrue(row, column) || cin.fail()) { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error, Try again: ";
        cin >> row >> column;
    }
    Tetris *objectOfTetris = new Tetris(row, column);
    objectOfTetris->reset();
    while (true) {
        cout << "Tetromino type (Q: for quit, R: for random): ";
        cin >> type;
        while (!(type == 'O' || type == 'T' || type == 'L' || type == 'S' || type == 'J' || type == 'Z' || type == 'I' || type == 'R' || type == 'Q')) { // exception handling
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error, Try again: ";
            cin >> type;
        }
        if (type == 'R') // Getting a random character
            type = objectOfTetris->random();
        if (type == 'Q') { // Terminates the program if user enters 'Q'
            cout << endl
                 << "Program Terminated" << endl;
            exit(0);
        }
        Tetromino *objectOfTetromino = new Tetromino(static_cast<shapes>(type)); // Creating Tetromino object with a parameter that it's type is strong enum that was converted from characeter
        temp = objectOfTetromino->get();
        if (!(objectOfTetris->is_game_on(type, numOfbuttom, temp))) // Checking if game is still playable
            break;
        objectOfTetris->animate(type, temp); // printing with animation
        numOfbuttom = objectOfTetris->scan();
        delete objectOfTetromino;
    }
    delete objectOfTetris;
}
