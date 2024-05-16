#include "tetris.h"
#include "tetromino.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Constructing tetromino class" << endl << endl;
    Tetromino *objectOfTetromino = new Tetromino(shapes::I);
    cout << "Running Member Function printOnScreen Of Class Tetromino" << endl << endl;
    objectOfTetromino->printOnScreen();
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function rotate Of Class Tetromino" << endl << endl;
    objectOfTetromino->rotate('r');
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function get Of Class Tetromino" << endl << endl;
    objectOfTetromino->get();
    cout << "Succesful" << endl << endl;
    cout << "Constructing tetris class" << endl << endl;
    Tetris *objectOfTetris = new Tetris(10, 10);
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function reset Of Class Tetris" << endl << endl;
    objectOfTetris->reset();
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function random Of Class Tetris" << endl << endl;
    objectOfTetris->random();
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function isTrue Of Class Tetris" << endl << endl;
    objectOfTetris->isTrue(10, 10);
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function add Of Class Tetris" << endl << endl;
    objectOfTetris->add(1, 0, objectOfTetromino->get());
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function draw Of Class Tetris" << endl << endl;
    objectOfTetris->draw();
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function animate Of Class Tetris" << endl << endl;
    objectOfTetris->animate('I', objectOfTetromino->get());
    cout << "Succesful" << endl << endl;
    cout << "Running Member Function is_game_on Of Class Tetris" << endl << endl;
    objectOfTetris->is_game_on('I', 0, objectOfTetromino->get());
    cout << "Succesful" << endl << endl;
    delete objectOfTetromino;
    delete objectOfTetris;
    cout << "deleting objects of Class Tetris and Tetromino" << endl << endl;
    cout << "Test driver completed" << endl << endl;
}