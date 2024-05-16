#ifndef _TETRIS_H_
#define _TETRIS_H_
#include <vector>
using namespace std;
class Tetris {
public:
    Tetris();// default constructor
    Tetris(int, int);// constructor to assign column and row
    void draw() const; // prints the table on the terminal
    void reset();// creates empty table
    void add(int, int, vector<vector<char>> tetrominoShape);// adds tetrominos on the board
    void animate(char, vector<vector<char>>);// animates the processed of falling
    int scan();// scans the columns filled at the bottom
    bool is_game_on(char, int, vector<vector<char>>) const;
    static char random(); // Returns a random tetromino name
    static bool isTrue(int, int); // Won't let user assign row or column less than 8

private:
    int row;
    int column;
    vector<vector<char>> table;// tetris table
};
#endif