#include "tetromino.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;
void Tetromino::printOnScreen() { // Printing Tetrominos on the screen
    for (int i = 0; i < shapeOfClass.size(); i++) {
        for (int j = 0; j < shapeOfClass[i].size(); j++) {
            cout << shapeOfClass[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Tetromino::Tetromino(shapes shape) { // Constructor to assign Tetrominos
    if (shape == shapes::I) {
        shapeOfClass = {{'I', 'I', 'I', 'I'}};

    } else if (shape == shapes::O) {
        shapeOfClass = {{'O', 'O'},
                        {'O', 'O'}};

    } else if (shape == shapes::T) {
        shapeOfClass = {{' ', 'T', ' '},
                        {'T', 'T', 'T'}};

    } else if (shape == shapes::J) {
        shapeOfClass = {{' ', 'J'},
                        {' ', 'J'},
                        {'J', 'J'}};

    } else if (shape == shapes::L) {
        shapeOfClass = {{'L', ' '},
                        {'L', ' '},
                        {'L', 'L'}};

    } else if (shape == shapes::S) {
        shapeOfClass = {{' ', 'S', 'S'},
                        {'S', 'S', ' '}};

    } else if (shape == shapes::Z) {
        shapeOfClass = {{'Z', 'Z', ' '},
                        {' ', 'Z', 'Z'}};
    }
}

void Tetromino::rotate(char direction) {//turns object towards either right or left
    vector<vector<char>> newOne;

    if (direction == 'l') { // Turning towards left
        for (int i = shapeOfClass[0].size() - 1; i >= 0; i--) {
            vector<char> tempvec; // temporary 1d vector to store data
            for (int j = 0; j < shapeOfClass.size(); j++) {
                tempvec.push_back(shapeOfClass[j][i]);
            }
            newOne.push_back(tempvec); // pushing 1d vector to the unfilled vector
        }
    } else if (direction == 'r') { // Turning towards right
        for (int i = 0; i < shapeOfClass[0].size(); i++) {
            vector<char> tempvec; // temporary 1d vector to store data
            for (int j = shapeOfClass.size() - 1; j >= 0; j--) {
                tempvec.push_back(shapeOfClass[j][i]);
            }
            newOne.push_back(tempvec); // pushing 1d vector to the unfilled vector
        }
    }
    shapeOfClass = newOne; // assigning newOne to private member of class
}

vector<vector<char>> Tetromino::get() {//getter
    return shapeOfClass;
}
