///////////////////////////////////////////////////////////
// C++ course, Abdullin Rustam, task 1
// email: afaritovich@mail.ru
///////////////////////////////////////////////////////////

#pragma once
#include <vector>
#include <fstream>
#include <ostream>
#include <iostream>

using std::vector;
using std::ifstream;
using std::ofstream;

class GameOfLife{

    public:

    int row;
    int col;
    vector<vector<bool>> CurrentConfig;  ///< Pairs of alive cells
    
    const int rLive = 3;
    const int minDead = 2;
    const int maxDead = 3;
    int Generation;

    

    /* Constructor */

    GameOfLife(){Generation=0;};

    /* Methods */

    /**
     * This function reads initial configuration 
     * from input file
     * 
     * * - alive
     * _ - empty
     * 
     * example:
     * **_
     * __*
     * ***
     */
    void Fill( ifstream& input );

    void next_generation();

    void print();

    ~GameOfLife() = default;

};