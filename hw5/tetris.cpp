#include "tetris.h"
#include "tetromino.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;
namespace tetris_namespace
{

// START OF TetrisVector FUNCTIONS

//creates board in type of 2D vector with given parameter
TetrisVector::TetrisVector(const int _row, const int _col)
{
    row = _row;
    col = _col;
    moveDirection = 'r';
    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;

    for (int i = 0; i < row + 2; i++)
    {
        vector<char> temp;
        for (int j = 0; j < col + 2; j++)
        {
            if (i == 0 || i == row + 1)
                temp.push_back('#');
            else if (j == 0 || j == col + 1)
                temp.push_back('#');
            else
                temp.push_back(' ');
        }
        board.push_back(temp);
    }
}
//creates board in type of 2D vector without given parameter

TetrisVector::TetrisVector() : row(10), col(10)
{
    moveDirection = 'r';
    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;
    for (int i = 0; i < row + 2; i++)
    {
        vector<char> temp;
        for (int j = 0; j < col + 2; j++)
        {
            if (i == 0 || i == row + 1)
                temp.push_back('#');
            else if (j == 0 || j == col + 1)
                temp.push_back('#');
            else
                temp.push_back(' ');
        }
        board.push_back(temp);
    }
}

//prints the board on the screen
void TetrisVector::draw() const
{
    for (int i = 0; i < row + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

// returns total move that user has made
int TetrisVector::numberOfMoves() const { return sumofMoveCount; }
// returns the last move count user has made
int TetrisVector::lastMove() const { return moveCount; }

// takes input for rotation process
void askRotation(char &rotationDirection, int &rotationCount)
{
    cout << "Rotation Direction (a for anticlockwise, c clockwise) and rotation count: ";
    cin >> rotationDirection >> rotationCount;
    while (!(rotationDirection == 'a' || rotationDirection == 'c') || cin.fail())
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> rotationDirection >> rotationCount;
    }
}

//Animates function to animate the added tetromino dropping to the bottom of the board
void TetrisVector::animate(Tetromino &other)
{
    int i = 0;
    askRotation(rotationDirection, rotationCount);
    //rotates tetromino with gives rotation count
    for (int k = 0; k < rotationCount; k++)
        other.rotate(static_cast<directions>(rotationDirection));
    // check if table is full
    if (lengthOfStack() + other.getRow() > row)
    {
        cerr << "table is full" << endl;
        exit(0);
    }
    //Get move direnction and count
    cout << "Move Direction (r for right, l left) and move count: ";
    cin >> moveDirection >> moveCount;
    while (!(moveDirection == 'r' || moveDirection == 'l') || cin.fail() || !isMovable(other))
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> moveDirection >> moveCount;
    }
    // variable for numofMoves function
    sumofMoveCount++;
    //if direction is l then multiply movecount by -1
    if (moveDirection == 'l')
        moveCount *= -1;
    do
    {
        //add tetromino at to tetris
        *this += other;
        usleep(500000);
        cout << u8"\033[2J\033[1;1H";
        draw();
        numofFalls++;
        i++;
    } while (i < row - other.getRow() + 1 && check == 0);
    numofFalls = 1;
    check = 0;
}

// adds tetromino to tetris

TetrisVector &TetrisVector::operator+=(const Tetromino &other)
{
    if (numofFalls == 2)
    {
        for (int i = 1; i <= other.getRow(); i++)
        {
            for (int j = 0; j < other.getColumn(); j++)
            {
                board[i][1 + (col / 2) + j] = ' ';
            }
        }
    }
    for (int i = 0; i < other.getRow(); i++)
    {
        for (int k = 0; k < other.getColumn(); k++)
        {
            // checking for tetrominos overlap
            if (board[numofFalls + other.getRow() - 1][1 + (col / 2) + moveCount + k] != ' ')
                check = 1;
        }
        if (check == 1)
        {
            break;
        }

        for (int j = 0; j < other.getColumn(); j++)
        {

            if (numofFalls == 1)
                board[numofFalls + i][1 + (col / 2) + j] = other.getTetromino()[i][j];
            if (numofFalls > 1)
                board[numofFalls + i][1 + (col / 2) + j + moveCount] = other.getTetromino()[i][j];
            if (numofFalls != 1)
            {
                board[numofFalls - 1][1 + (col / 2) + j + moveCount] = ' ';
            }
        }
    }
    return *this;
}

// writing board to the file
void TetrisVector::writeToFile() const
{
    ofstream outfile;
    outfile.open("TetrisVector.txt");
    if (!outfile.is_open())
        cerr << "Error: Unable to open file." << endl;
    for (int i = 0; i < row + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            outfile << board[i][j];
        }
        outfile << endl;
    }
    outfile.close();
}

// prints what is in file
void TetrisVector::readFromFile() const
{
    string line;
    ifstream myfile("TetrisVector.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cerr << "Unable to open file";
}

// function when computing if table is full
int TetrisVector::lengthOfStack() const
{
    int flag, s = 0;
    for (int i = row; i >= 1; i--)
    {
        flag = 0;
        for (int j = 1; j <= col; j++)
        {
            if (board[i][j] != ' ')
            {
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

// checking if player can move towards right or left
bool TetrisVector::isMovable(const Tetromino &other) const
{
    if (moveDirection == 'r')
    {
        if ((col / 2) + other.getColumn() + moveCount > col + 1)
            return false;
    }
    else
    {
        if (moveCount > (col / 2) - 1)
            return false;
    }
    return true;
}

void TetrisVector::fit() {}

// START OF TetrisAdapter FUNCTIONS

//creates board in type of 2D template with given parameter

template <typename container, typename T>
TetrisAdapter<container, T>::TetrisAdapter(const int row_, const int col_)
{
    moveDirection = 'r';
    row = row_;
    col = col_;
    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;
    for (int i = 0; i < row + 2; i++)
    {
        T temp;
        for (int j = 0; j < col + 2; j++)
        {
            if (i == 0 || i == row + 1)
                temp.push_back('#');
            else if (j == 0 || j == col + 1)
                temp.push_back('#');
            else
                temp.push_back(' ');
        }
        board.push_back(temp);
    }
}

//creates board in type of 2D template without given parameter

template <typename container, typename T>
TetrisAdapter<container, T>::TetrisAdapter() : row(10), col(10)
{
    moveDirection = 'r';

    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;
    for (int i = 0; i < row + 2; i++)
    {
        T temp;
        for (int j = 0; j < col + 2; j++)
        {
            if (i == 0 || i == row + 1)
                temp.push_back('#');
            else if (j == 0 || j == col + 1)
                temp.push_back('#');
            else
                temp.push_back(' ');
        }
        board.push_back(temp);
    }
}
//prints the board on the screen

template <typename container, typename T>
void TetrisAdapter<container, T>::draw() const
{
    for (int i = 0; i < row + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

//Animates function to animate the added tetromino dropping to the bottom of the board

template <typename container, typename T>
void TetrisAdapter<container, T>::animate(Tetromino &other)
{
    int i = 0;
    askRotation(rotationDirection, rotationCount);
    for (int k = 0; k < rotationCount; k++)
        other.rotate(static_cast<directions>(rotationDirection));
    if (lengthOfStack() + other.getRow() > row)
    {
        cerr << "table is full" << endl;
        exit(0);
    }
    cout << "Move Direction (r for right, l left) and move count: ";
    cin >> moveDirection >> moveCount;
    while (!(moveDirection == 'r' || moveDirection == 'l') || cin.fail() || !isMovable(other))
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> moveDirection >> moveCount;
    }
    sumofMoveCount++;
    if (moveDirection == 'l')
        moveCount *= -1;
    do
    {
        *this += other;
        usleep(500000);
        cout << u8"\033[2J\033[1;1H";
        draw();
        numofFalls++;
        i++;
    } while (i < row - other.getRow() + 1 && check == 0);
    numofFalls = 1;
    check = 0;
}

// adds tetromino to tetris
template <typename container, typename T>
TetrisAdapter<container, T> &TetrisAdapter<container, T>::operator+=(const Tetromino &other)
{
    if (numofFalls == 2)
    {
        for (int i = 1; i <= other.getRow(); i++)
        {
            for (int j = 0; j < other.getColumn(); j++)
            {
                board[i][1 + (col / 2) + j] = ' ';
            }
        }
    }
    for (int i = 0; i < other.getRow(); i++)
    {
        for (int k = 0; k < other.getColumn(); k++)
        {
            // checking tetromino overlapping
            if (board[numofFalls + other.getRow() - 1][1 + (col / 2) + moveCount + k] != ' ')
                check = 1;
        }
        if (check == 1)
        {
            break;
        }

        for (int j = 0; j < other.getColumn(); j++)
        {

            if (numofFalls == 1)
                board[numofFalls + i][1 + (col / 2) + j] = other.getTetromino()[i][j];
            if (numofFalls > 1)
                board[numofFalls + i][1 + (col / 2) + j + moveCount] = other.getTetromino()[i][j];
            if (numofFalls != 1)
            {
                board[numofFalls - 1][1 + (col / 2) + j + moveCount] = ' ';
            }
        }
    }
    return *this;
}

// function when computing if table is full
template <typename container, typename T>
int TetrisAdapter<container, T>::lengthOfStack() const
{
    int flag, s = 0;
    for (int i = row; i >= 1; i--)
    {
        flag = 0;
        for (int j = 1; j <= col; j++)
        {
            if (board[i][j] != ' ')
            {
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

// checking if player can move towards right or left

template <typename container, typename T>
bool TetrisAdapter<container, T>::isMovable(const Tetromino &other) const
{
    if (moveDirection == 'r')
    {
        if ((col / 2) + other.getColumn() + moveCount > col + 1)
            return false;
    }
    else
    {
        if (moveCount > (col / 2) - 1)
            return false;
    }
    return true;
}

// writing board to the file

template <typename container, typename T>
void TetrisAdapter<container, T>::writeToFile() const
{
    ofstream outfile;
    outfile.open("TetrisAdapter.txt");
    if (!outfile.is_open())
        cerr << "Error: Unable to open file." << endl;
    for (int i = 0; i < row + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            outfile << board[i][j];
        }
        outfile << endl;
    }
    outfile.close();
}

// prints what is on file
template <typename container, typename T>
void TetrisAdapter<container, T>::readFromFile() const
{
    string line;
    ifstream myfile("TetrisAdapter.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cerr << "Unable to open file";
}

// returns total move that user has made
template <typename container, typename T>
int TetrisAdapter<container, T>::numberOfMoves() const { return sumofMoveCount; }
// returns the last move count user has made
template <typename container, typename T>
int TetrisAdapter<container, T>::lastMove() const { return moveCount; }
template <typename container, typename T>
void TetrisAdapter<container, T>::fit() {}

// START OF TetrisArray1D FUNCTIONS
//creates board in type of 1D array with given parameter

TetrisArray1D::TetrisArray1D(const int _row, const int _col)
{
    moveDirection = 'r';

    row = _row;
    col = _col;
    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;
    board = new char[(row + 2) * (col + 2)];
    for (int i = 0; i < (row + 2) * (col + 2); i++)
    {
        if ((i / (col + 2)) == 0 || (i / (col + 2)) == (row + 1) || (i % (col + 2)) == 0 || (i % (col + 2)) == (col + 1))
            board[i] = '#';

        else
            board[i] = ' ';
    }
}

//creates board in type of 1D vector without given parameter

TetrisArray1D::TetrisArray1D() : row(8), col(8)
{
    moveDirection = 'r';

    check = 0;
    numofFalls = 1;
    sumofMoveCount = 0;
    board = new char[(row + 2) * (col + 2)];
    for (int i = 0; i < (row + 2) * (col + 2); i++)
    {
        if ((i / (col + 2)) == 0 || (i / (col + 2)) == (row + 1) || (i % (col + 2)) == 0 || (i % (col + 2)) == (col + 1))
            board[i] = '#';

        else
            board[i] = ' ';
    }
}
//deletes 1d array
TetrisArray1D::~TetrisArray1D() { delete[] board; }

//prints the board on the screen
void TetrisArray1D::draw() const
{
    for (int i = 0; i < (row + 2) * (col + 2); i++)
    {
        cout << board[i];
        if ((i + 1) % (col + 2) == 0)
            cout << endl;
    }
}
// function when computing if table is full

int TetrisArray1D::lengthOfStack() const
{
    int flag, s = 0;
    for (int i = row; i >= 1; i--)
    {
        flag = 0;
        for (int j = 1; j <= col; j++)
        {
            if (board[((col + 2) * i) + j] != ' ')
            {
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
//Animates function to animate the added tetromino dropping to the bottom of the board

void TetrisArray1D::animate(Tetromino &other)
{
    int i = 0;
    askRotation(rotationDirection, rotationCount);
    for (int k = 0; k < rotationCount; k++)
        other.rotate(static_cast<directions>(rotationDirection));
    if (lengthOfStack() + other.getRow() > row)
    {
        cerr << "table is full" << endl;
        exit(0);
    }
    cout << "Move Direction (r for right, l left) and move count: ";
    cin >> moveDirection >> moveCount;
    while (!(moveDirection == 'r' || moveDirection == 'l') || cin.fail() || !isMovable(other))
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> moveDirection >> moveCount;
    }
    sumofMoveCount++;
    if (moveDirection == 'l')
        moveCount *= -1;
    do
    {
        *this += other;
        usleep(500000);
        cout << u8"\033[2J\033[1;1H";
        draw();
        numofFalls++;
        i++;
    } while (i < row - other.getRow() + 1 && check == 0);
    numofFalls = 1;
    check = 0;
}
// adds tetromino to tetris

TetrisArray1D &TetrisArray1D::operator+=(const Tetromino &other)
{
    if (numofFalls == 2)
    {
        for (int i = 1; i <= other.getRow(); i++)
        {
            for (int j = 0; j < other.getColumn(); j++)
            {
                board[(col + 2) * i + 1 + (col / 2) + j] = ' ';
            }
        }
    }
    for (int i = 0; i < other.getRow(); i++)
    {
        for (int k = 0; k < other.getColumn(); k++)
        {
            if (board[(numofFalls + other.getRow() - 1) * (col + 2) + 1 + (col / 2) + moveCount + k] != ' ')
                check = 1;
        }
        if (check == 1)
        {
            break;
        }

        for (int j = 0; j < other.getColumn(); j++)
        {

            if (numofFalls == 1)
                board[(numofFalls + i) * (col + 2) + 1 + (col / 2) + j] = other.getTetromino()[i][j];
            if (numofFalls > 1)
                board[(numofFalls + i) * (col + 2) + 1 + (col / 2) + j + moveCount] = other.getTetromino()[i][j];
            if (numofFalls != 1)
            {
                board[(numofFalls - 1) * (col + 2) + 1 + (col / 2) + j + moveCount] = ' ';
            }
        }
    }
    return *this;
}
// writes board on file
void TetrisArray1D::writeToFile() const
{
    ofstream outfile;
    outfile.open("TetrisArray1D.txt");
    if (!outfile.is_open())
        cerr << "Error: Unable to open file." << endl;
    for (int i = 0; i < (row + 2) * (col + 2); i++)
    {
        outfile << board[i];
        if ((i + 1) % (col + 2) == 0)
            outfile << endl;
    }
    outfile.close();
}

// prints what is on file
void TetrisArray1D::readFromFile() const
{
    string line;
    ifstream myfile("TetrisArray1D.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cerr << "Unable to open file";
}

// checking if player can move towards right or left

bool TetrisArray1D::isMovable(const Tetromino &other) const
{
    if (moveDirection == 'r')
    {
        if ((col / 2) + other.getColumn() + moveCount > col + 1)
            return false;
    }
    else
    {
        if (moveCount > (col / 2) - 1)
            return false;
    }
    return true;
}
void TetrisArray1D::fit() {}
// returns total move that user has made

int TetrisArray1D::numberOfMoves() const { return sumofMoveCount; }
// returns the last move count user has made

int TetrisArray1D::lastMove() const { return moveCount; }

// START OF GLOBAL FUNCTIONS

// returns random char from vector of  {'I', 'O', 'J', 'L', 'S', 'Z', 'T'}
char randomChar()
{
    srand(time(0));
    vector<char> randomChars = {'I', 'O', 'J', 'L', 'S', 'Z', 'T'};
    return randomChars[rand() % 7];
}

// takes user input for row and column
void askRowCol(int &row, int &col)
{
    cout << "Tetris board size: ";
    cin >> row >> col;
    while (row < 8 || col < 8 || cin.fail())
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> row >> col;
    }
}

// takes user input for Tetris type
void askTetrisType(char &typeofTetris)
{
    cout << "Type of the Tetris Class (V for vector, 1 for array1D, A for adaptor):  ";
    cin >> typeofTetris;
    while ((typeofTetris != 'V' && typeofTetris != '1' && typeofTetris != 'A') || cin.fail())
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> typeofTetris;
    }
}

// takes user input for tetromino type
void askType(char &type)
{
    cout << "Tetromino type (Q: for quit, R: for random): ";
    cin >> type;
    while (!(type == 'O' || type == 'T' || type == 'L' || type == 'S' || type == 'J' || type == 'Z' || type == 'I' || type == 'R' || type == 'Q') || cin.fail())
    { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cerr << "Error, Try again: ";
        cin >> type;
    }
    if (type == 'R')
        type = randomChar();

    if (type == 'Q')
    { // program quit
        cout << endl
             << "Program Terminated" << endl;
        exit(0);
    }
}

} // namespace tetris_namespace
