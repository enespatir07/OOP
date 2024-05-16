#ifndef _TETRIS_H_
#define _TETRIS_H_
#include "tetromino.h"
#include <deque>
#include <iostream>
#include <vector>
using namespace tetromino_namespace;
using namespace std;
namespace tetris_namespace
{
class AbstractTetris
{
public:
    virtual void draw() const = 0;                             // prints the board on the screen
    virtual AbstractTetris &operator+=(const Tetromino &) = 0; // adds tetromino to tetris
    virtual void animate(Tetromino &) = 0;                     // Animates function to animate the added tetromino dropping to the bottom of the board
    virtual void fit() = 0;
    virtual void readFromFile() const = 0; // prints what is in file
    virtual void writeToFile() const = 0;  // writing board to the file
    virtual int lastMove() const = 0;      // returns the last move count user has made
    virtual int numberOfMoves() const = 0; // returns total move that user has made
};

class TetrisVector : public AbstractTetris
{
public:
    TetrisVector &operator+=(const Tetromino &) override;
    void animate(Tetromino &) override;
    void fit() override;
    void draw() const override;
    int numberOfMoves() const override;
    void writeToFile() const override;
    void readFromFile() const override;
    int lastMove() const override;

    TetrisVector(const int, const int);      // constructor
    TetrisVector();                          // no parameter constructor
    int lengthOfStack() const;               // function when computing if table is full
    bool isMovable(const Tetromino &) const; // checking if player can move towards right or left

private:
    vector<vector<char>> board;
    int row, col, check, numofFalls, moveCount, rotationCount, sumofMoveCount;
    char rotationDirection, moveDirection;
};

class TetrisArray1D : public AbstractTetris
{
public:
    TetrisArray1D &operator+=(const Tetromino &) override;
    void fit() override;
    void draw() const override;
    void animate(Tetromino &) override;
    int numberOfMoves() const override;
    void writeToFile() const override;
    void readFromFile() const override;
    int lastMove() const override;

    TetrisArray1D(const int, const int);     // constructor
    TetrisArray1D();                         // no parameter constructor
    ~TetrisArray1D();                        // destructor
    int lengthOfStack() const;               // function when computing if table is full
    bool isMovable(const Tetromino &) const; // checking if player can move towards right or left

private:
    char *board;
    char moveDirection, rotationDirection;
    int row, col, numofFalls, check, moveCount, rotationCount, sumofMoveCount;
};

template <typename container, typename T>
class TetrisAdapter : public AbstractTetris
{
public:
    void fit() override;
    void animate(Tetromino &) override;
    TetrisAdapter &operator+=(const Tetromino &) override;
    void draw() const override;
    int numberOfMoves() const override;
    void writeToFile() const override;
    void readFromFile() const override;
    int lastMove() const override;

    TetrisAdapter(const int, const int);     // constructor
    TetrisAdapter();                         // no parameter constructor
    int lengthOfStack() const;               // function when computing if table is full
    bool isMovable(const Tetromino &) const; // checking if player can move towards right or left

private:
    container board;
    int row, col, numofFalls, check, moveCount, rotationCount, sumofMoveCount;
    char moveDirection, rotationDirection;
};

//GLOBAL FUNCTIONS
char randomChar();
void askRowCol(int &, int &);
void askTetrisType(char &);
void askType(char &);
void askRotation(char &, int &);
//FORWARD DECLARATION
template class TetrisAdapter<vector<vector<char>>, vector<char>>;
template class TetrisAdapter<deque<deque<char>>, deque<char>>;
} // namespace tetris_namespace
#endif