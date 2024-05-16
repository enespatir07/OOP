#ifndef _TETROMINO_H_
#define _TETROMINO_H_

namespace tetromino_namespace
{
enum class shapes
{ // enum class for different types of tetrominos and options
    I = 'I',
    O = 'O',
    T = 'T',
    J = 'J',
    L = 'L',
    S = 'S',
    Z = 'Z'
};
enum class directions
{
    a = 'a', // anticlokcwise
    c = 'c', // clockwise
    r = 'r', // right
    l = 'l'  // left
};
enum class options
{
    R = 'R',
    Q = 'Q'
};
class Tetromino
{
public:
    Tetromino(const shapes);       // Constructor to assign Tetrominos with dynamic 2D char arrays
    Tetromino();                   // No-parameter creates Tetromino O with size 2X2  if no parameter given
    ~Tetromino();                  // Destructor to delete 2D char dynamic char array
    void rotate(const directions); // Rotates tetrominos either in clockwise or anticlockwise direction
    void printTetromino() const;   // Printing Tetrominos on the screen
    char **getTetromino() const;   // getter
    int getRow() const;            // getter
    int getColumn() const;         // getter
private:
    char **tetrominoShape;
    int row, column; // size of tetromino
};
} // namespace tetromino_namespace
#endif