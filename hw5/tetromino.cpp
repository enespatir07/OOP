#include "tetromino.h"
#include "tetris.h"
#include <iostream>
using namespace std;

namespace tetromino_namespace
{
Tetromino::Tetromino() : row(2), column(2)
{
    tetrominoShape = new char *[row];
    for (int i = 0; i < row; i++)
        tetrominoShape[i] = new char[column];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            tetrominoShape[i][j] = 'O';
}

Tetromino::Tetromino(const shapes shape)
{ // Constructor to assign Tetrominos with dynamic 2D char arrays
    if (shape == shapes::I)
    {
        row = 1, column = 4;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                tetrominoShape[i][j] = 'I';
    }
    else if (shape == shapes::O)
    {
        row = 2, column = 2;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                tetrominoShape[i][j] = 'O';
    }
    else if (shape == shapes::T)
    {
        row = 2, column = 3;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 0)
                    tetrominoShape[i][j] = 'T';
                else
                {
                    if (j != 1)
                    {
                        tetrominoShape[i][j] = ' ';
                    }
                    else
                        tetrominoShape[i][j] = 'T';
                }
            }
        }
    }
    else if (shape == shapes::J)
    {
        row = 3, column = 2;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 2)
                    tetrominoShape[i][j] = 'J';
                else
                {
                    if (j == 0)
                        tetrominoShape[i][j] = ' ';
                    else
                        tetrominoShape[i][j] = 'J';
                }
            }
        }
    }
    else if (shape == shapes::L)
    {
        row = 3, column = 2;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 2)
                    tetrominoShape[i][j] = 'L';
                else
                {
                    if (j == 1)
                        tetrominoShape[i][j] = ' ';
                    else
                        tetrominoShape[i][j] = 'L';
                }
            }
        }
    }
    else if (shape == shapes::S)
    {
        row = 2, column = 3;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 0)
                {
                    if (j != 0)
                        tetrominoShape[i][j] = 'S';
                    else
                        tetrominoShape[i][j] = ' ';
                }
                else if (j != 2)
                    tetrominoShape[i][j] = 'S';
                else
                    tetrominoShape[i][j] = ' ';
            }
        }
    }
    else if (shape == shapes::Z)
    {
        row = 2, column = 3;
        tetrominoShape = new char *[row];
        for (int i = 0; i < row; i++)
            tetrominoShape[i] = new char[column];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 0)
                {
                    if (j != 2)
                        tetrominoShape[i][j] = 'Z';
                    else
                        tetrominoShape[i][j] = ' ';
                }
                else if (j != 0)
                    tetrominoShape[i][j] = 'Z';
                else
                    tetrominoShape[i][j] = ' ';
            }
        }
    }
}

Tetromino::~Tetromino()
{ // Destructor to delete 2D char dynamic char array
    for (int i = 0; i < row; ++i)
    {
        delete[] tetrominoShape[i];
    }
    delete[] tetrominoShape;
}

void Tetromino::printTetromino() const
{ // Printing Tetrominos on the screen

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << tetrominoShape[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Tetromino::rotate(const directions direction)
{ // Rotates tetrominos either in clockwise or anticlockwise direction
    char **temp = new char *[column];
    for (int i = 0; i < column; i++) // Temporary 2D char array to copy the original char array
        temp[i] = new char[row];

    if (direction == directions::a)
    { // towards anticlockwise
        for (int i = column - 1, k = 0; i >= 0; i--, k++)
        {
            for (int j = 0; j < row; j++)
            {
                temp[k][j] = tetrominoShape[j][i];
            }
        }
    }
    if (direction == directions::c)
    { // towards clockwise
        for (int i = 0; i < column; i++)
        {
            for (int j = row - 1, k = 0; j >= 0; j--, k++)
            {
                temp[i][k] = tetrominoShape[j][i];
            }
        }
    }

    for (int i = 0; i < row; ++i)
    { // Deleting contents of original array to assign the temporary array to itself
        delete[] tetrominoShape[i];
    }
    delete[] tetrominoShape;
    tetrominoShape = temp;
    int tempInt = row; // swapping size values
    row = column;
    column = tempInt;
}

// Getters
int Tetromino::getRow() const { return row; }
int Tetromino::getColumn() const { return column; }
char **Tetromino::getTetromino() const { return tetrominoShape; }
} // namespace tetromino_namespace