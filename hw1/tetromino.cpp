#include "tetromino.h"
#include <iostream>
#include <vector>
using namespace std;
void Tetromino::printOnScreen() { // Printing Tetrominos on the screen
    for (int i = 0; i < classShape.size(); i++) {
        for (int j = 0; j < classShape[i].size(); j++) {
            cout << classShape[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Tetromino::Tetromino(shapes shape) { // Constructing Tetrominos
    if (shape == shapes::I) {
        classShape = {{'I', 'I', 'I', 'I'}};

    } else if (shape == shapes::O) {
        classShape = {{'O', 'O'},
                      {'O', 'O'}};

    } else if (shape == shapes::T) {
        classShape = {{'T', 'T', 'T'},
                      {' ', 'T', ' '}};

    } else if (shape == shapes::J) {
        classShape = {{' ', 'J'},
                      {' ', 'J'},
                      {'J', 'J'}};

    } else if (shape == shapes::L) {
        classShape = {{'L', ' '},
                      {'L', ' '},
                      {'L', 'L'}};

    } else if (shape == shapes::S) {
        classShape = {{' ', 'S', 'S'},
                      {'S', 'S', ' '}};

    } else if (shape == shapes::Z) {
        classShape = {{'Z', 'Z', ' '},
                      {' ', 'Z', 'Z'}};
    }
}

void Tetromino::rotate(char direction) {
    vector<vector<char>> newOne;

    if (direction == 'l') { // Turning towards left
        for (int i = classShape[0].size() - 1; i >= 0; i--) {
            vector<char> tempvec; // temporary 1d vector to store data
            for (int j = 0; j < classShape.size(); j++) {
                tempvec.push_back(classShape[j][i]);
            }
            newOne.push_back(tempvec);// pushing 1d vector to the unfilled vector
        }
    } else if (direction == 'r') { // Turning towards right
        for (int i = 0; i < classShape[0].size(); i++) {
            vector<char> tempvec; //temporary 1d vector to store data
            for (int j = classShape.size() - 1; j >= 0; j--) {
                tempvec.push_back(classShape[j][i]);
            }
            newOne.push_back(tempvec);//pushing 1d vector to the unfilled vector
        }
    }
    classShape = newOne; //assigning newOne to private member of class
}
