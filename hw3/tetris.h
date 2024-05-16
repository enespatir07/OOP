#ifndef _TETRIS_H_
#define _TETRIS_H_
#include "tetromino.h"

using tetromino_namespace::Tetromino;

namespace tetris_namespace {
class Tetris {
public:
    Tetris(const int, const int);            // constructor to assign size of table
    Tetris();                                // no-parameter constructror assigns row and column to 8 if no parameter given
    ~Tetris();                               // Destructor to delete 2D char dynamic char array
    Tetris &operator+=(const Tetromino &);   // Operator Overloading to add tetrominos on tetris board
    void createTable();                      // creates empty table with size of row and column
    void draw() const;                       // prints table on screen
    void animate(Tetromino &);               // Animate Function to let tetrominos fall from top to bottom
    bool isMovable(const Tetromino &) const; // checks if user can move tetromino in direction with legit moveCount
    int lengthOfStack() const;               // returns the length of tetromino stack on tetris board
    static char random();                    // returns random a random char in array {'I', 'O', 'J', 'L', 'S', 'Z', 'T'}
private:
    int row, column, numOfMovesHorizontally, numOfFalls, moveCount, rotationCount, check;
    char **table;
    char rotationDirection, moveDirection;
};
} // namespace tetris_namespace
#endif