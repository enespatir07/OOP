#include "tetromino.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int numOfTetrominos;
    cout << "How many tetrominos: ";
    cin >> numOfTetrominos;
    while (cin.fail()) { // exception handling
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error, Try again: ";
        cin >> numOfTetrominos;
    }
    cout << "What are the types:" << endl;
    vector<Tetromino> vectorClass; // vector of objects 
    char x;
    for (int i = 0; i < numOfTetrominos; i++) {
        cin >> x;
        while (!(x == 'O' || x == 'T' || x == 'L' || x == 'S' || x == 'J' || x == 'Z' || x=='I')) { // exception handling
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error, Try again: ";
            cin >> x;
        }
        vectorClass.push_back(Tetromino(static_cast<shapes>(x)));// Turning char variable into enum class variable
    }
    cout << endl;
    for (int i = 0; i < numOfTetrominos; i++)// Printing tetrominos of each object
        vectorClass[i].printOnScreen();
}