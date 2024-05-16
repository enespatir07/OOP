#include "tetris.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;

Tetris::Tetris(int row, int column) { // constructor to assign column and row
    this->column = column;
    this->row = row;
}

void Tetris::reset() { // creates empty table
    for (int i = 0; i < row + 2; i++) {
        vector<char> temp;
        for (int j = 0; j < column + 2; j++) {
            if (i == 0 || i == row + 1)
                temp.push_back('#');
            else if (j == 0 || j == column + 1)
                temp.push_back('#');
            else
                temp.push_back(' ');
        }
        table.push_back(temp);
    }
}

void Tetris::draw() const { // prints the table on the terminal
    for (int i = 0; i < row + 2; i++) {
        for (int j = 0; j < column + 2; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
}

void Tetris::add(int current, int numOfBottom, vector<vector<char>> tetrominoShape) { // adds tetrominos on the board
    for (int i = 0; i < tetrominoShape.size(); i++) {
        for (int j = 0; j < tetrominoShape[i].size(); j++) {
            table[current + i][1 + j + numOfBottom] = tetrominoShape[i][j];
            if (current != 1) { // placing tetromino from left to right
                table[current - 1][1 + j + numOfBottom] = ' ';
            }
        }
    }
}
int Tetris::scan() { // scans the columns filled at the bottom
    auto i = row, result = 0;
    for (int j = 1; j <= column; j++) {
        if (table[i][j] != ' ')
            result++;
        if (table[i][j] == ' ' && table[i][j + 1] == 'T' && table[i][j + 2])
            result += 2;
        if (table[i][j] == 'S' && table[i][j + 1] == 'S' && table[i][j + 2] == ' ')
            result += 1;
        if (table[i][j] == ' ' && table[i][j + 1] == 'Z' && table[i][j + 1] == 'Z')
            result += 1;
    }
    return result;
}

void Tetris::animate(char type, vector<vector<char>> tetrominoShape) { // animates the processed of falling
    int length;
    auto i = 0, numOfBottom = 0, countOfStep = 1;
    do {
        numOfBottom = scan();
        add(countOfStep, numOfBottom, tetrominoShape);
        usleep(500000);
        length = tetrominoShape.size();
        cout << u8"\033[2J\033[1;1H"; // Cleaning terminal
        draw();
        countOfStep++; //
        i++;
    } while (i < row + 1 - length); // checks if tetromino collide at the bottom
    countOfStep = 1;
}

char Tetris::random() { // Returns a random tetromino name
    srand(time(NULL));
    vector<char> randomVector = {'I', 'O', 'J', 'L', 'S', 'Z', 'T'};
    return randomVector[rand() % 7];
}

bool Tetris::is_game_on(char type, int numOfbuttom, vector<vector<char>> tetrominoShape) const {
    if (numOfbuttom + tetrominoShape[0].size() > column) { // If there are no places left to put tetrominos it'll return false
        cout << "Cannot place " << type << endl;
        return false;
    }
    return true;
}

bool Tetris::isTrue(int numOfRows, int numOfColumns) { // Won't let user assign row or column less than 8
    if (numOfRows < 8 || numOfColumns < 8)
        return false;
    return true;
}
