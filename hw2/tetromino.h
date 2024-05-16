#ifndef _TETROMINO_H_
#define _TETROMINO_H_
#include <vector>
using namespace std;
enum class shapes { I = 'I',
                    O = 'O',
                    T = 'T',
                    J = 'J',
                    L = 'L',
                    S = 'S',
                    Z = 'Z' };

class Tetromino {
public:
    Tetromino(); // default constructor
    Tetromino(shapes); // Constructor to assign Tetrominos
    void printOnScreen();// Printing Tetrominos on the screen   
    void rotate(char);//turns object towards either right or left
    vector<vector<char>> get();//getter
private:
    vector<vector<char>> shapeOfClass;//2d char array to hold the tetrominos
};
#endif