#ifndef _TETROMINO_H_
#define _TETROMINO_H_
#include<vector>
using namespace std;
enum class shapes { I = 'I', O = 'O', T = 'T', J = 'J', L = 'L', S = 'S',Z = 'Z' };

class Tetromino{
public:
    Tetromino();//default constructor
    Tetromino(shapes);
    void printOnScreen(); 
    void rotate(char);
    bool canFit(vector<Tetromino>);
    void set(vector<vector<char>>);
private:
    vector<vector<char>> classShape; 
};
#endif 