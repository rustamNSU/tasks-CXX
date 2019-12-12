#include "Game.hpp"
#include "GameOfLife.h"
#include <iostream>
#include <ctime>

int main(int argc, char** argv){

    std::ifstream input("Tests/input/input.txt");

    GameOfLife game;
    game.Fill(input);
    game.print();
    for(int i = 0 ; i < 100; i++){
        game.next_generation();
        game.print();
    }
    
    return 0;

}