#include "tetris.h"
#include "tetromino.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;
using namespace tetromino_namespace;
using namespace tetris_namespace;

Tetris::Tetris(const int row, const int column) { // constructor to assign size of table
    this->row = row;
    this->column = column;
    check = 0;
    numOfFalls = 1;
}

Tetris::Tetris() : row(8), column(8) { // no-parameter constructror assigns row and column to 8 if no parameter given
}

Tetris::~Tetris() { // Destructor to delete 2D char dynamic char array
    for (int i = 0; i < row; ++i) {
        delete[] table[i];
    }
    delete[] table;
}

Tetris &Tetris::operator+=(const Tetromino &other) { // Operator Overloading to add tetrominos on tetris board
    if (numOfFalls == 2) {
        for (int i = 1; i <= other.getRow(); i++) {
            for (int j = 0; j < other.getColumn(); j++) {
                table[i][1 + (column / 2) + j] = ' ';
            }
        }
    }
    for (int i = 0; i < other.getRow(); i++) {
        for (int k = 0; k < other.getColumn(); k++) {
            if (table[numOfFalls + other.getRow() - 1][1 + (column / 2) + moveCount + k] != ' ')
                check = 1;
        }
        if (check == 1) {
            break;
        }

        for (int j = 0; j < other.getColumn(); j++) {

            if (numOfFalls == 1)
                table[numOfFalls + i][1 + (column / 2) + j] = other.getTetromino()[i][j];
            if (numOfFalls > 1)
                table[numOfFalls + i][1 + (column / 2) + j + numOfMovesHorizontally] = other.getTetromino()[i][j];
            if (numOfFalls != 1) {
                table[numOfFalls - 1][1 + (column / 2) + j + numOfMovesHorizontally] = ' ';
            }
        }
    }
    return *this;
}

void Tetris::createTable() { // creates empty table with size of row and column
    table = new char *[row + 2];
    for (int i = 0; i < row + 2; i++)
        table[i] = new char[column + 2];
    for (int i = 0; i < row + 2; i++) {
        for (int j = 0; j < column + 2; j++) {
            if (i == 0 || i == row + 1)
                table[i][j] = '#';
            else if (j == 0 || j == column + 1)
                table[i][j] = '#';
            else
                table[i][j] = ' ';
        }
    }
}

void Tetris::draw() const { // prints table on screen
    for (int i = 0; i < row + 2; i++) {
        for (int j = 0; j < column + 2; j++) {
            cout << table[i][j]
                 << " ";
        }
        cout << endl;
    }
}

void Tetris::animate(Tetromino &other) { // Animate Function to let tetrominos fall from top to bottom
    int i = 0;
    cout << "Rotation Direction (a for anticlockwise, c clockwise) and rotation count: ";
    cin >> rotationDirection >> rotationCount;
    directions tempDirection = static_cast<directions>(rotationDirection);
    while (!(tempDirection == directions::a || tempDirection == directions::c) || cin.fail()) { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> rotationDirection >> rotationCount;
        tempDirection = static_cast<directions>(rotationDirection);
    }
    for (int k = 0; k < rotationCount; k++)
        other.rotate(tempDirection);
    if (lengthOfStack() + other.getRow() > row) {
        cout << "table is full" << endl;
        exit(0);
    }
    cout << "Move Direction (r for right, l left) and move count: ";
    cin >> moveDirection >> moveCount;
    directions tempMoveDirection = static_cast<directions>(moveDirection);
    while (!(tempMoveDirection == directions::r || tempMoveDirection == directions::l) || cin.fail() || !isMovable(other)) { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> moveDirection >> moveCount;
        tempMoveDirection = static_cast<directions>(moveDirection);
    }
    numOfMovesHorizontally = moveCount;
    if (tempMoveDirection == directions::l)
        numOfMovesHorizontally *= -moveCount;
    int len = lengthOfStack();
    do {
        *this += other;
        usleep(500000);
        cout << u8"\033[2J\033[1;1H";
        draw();
        numOfFalls++;
        i++;
    } while (i < row - other.getRow() - len + 1);
    numOfFalls = 1;
    check = 0;
}

bool Tetris::isMovable(const Tetromino &other) const { // checks if user can move tetromino in direction with legit moveCount
    if (static_cast<directions>(moveDirection) == directions::r) {
        if ((column / 2) + other.getColumn() + moveCount > column + 1)
            return false;
    } else {
        if (moveCount > (column / 2) - 1)
            return false;
    }
    return true;
}

int Tetris::lengthOfStack() const { // returns the length of tetromino stack on tetris board
    int flag, s = 0;
    for (int i = row; i >= 1; i--) {
        flag = 0;
        for (int j = 1; j <= column; j++) {
            if (table[i][j] != ' ') {
                s++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return s;
    }
    return s;
}

char Tetris::random() { // returns random a random char in array {'I', 'O', 'J', 'L', 'S', 'Z', 'T'}
    srand(time(0));
    shapes *randomShape{new shapes[7]{shapes::I, shapes::O, shapes::J, shapes::L, shapes::S, shapes::Z, shapes::T}};
    return static_cast<char>(randomShape[rand() % +7]);
}
