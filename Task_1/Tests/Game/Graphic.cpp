#include "Game.hpp"
#include "GameOfLife.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
using namespace sf;

#define WHITE Color::White
#define BLACK Color::Black
#define GRAY Color(153, 153, 153)

int main()
{   
    std::ifstream input("Tests/input/input2.txt");
    GameOfLife game;
    game.Fill(input);
    
    const int GRID_WIDTH = game.col;
    const int GRID_HEIGHT = game.row;
    const int CELL_SIZE = std::max(
        500/std::max(GRID_WIDTH,GRID_HEIGHT),
        1);
    const Vector2f CELL_VECTOR(CELL_SIZE, CELL_SIZE);

    const int DELAY_INC = 10;
    int delay = 100;

    bool isPlaying = true;
    Font font;
    font.loadFromFile("Tests/Game/fonts/arial.ttf");

    Text textPause("Press 'p' to pause", font);
    textPause.setCharacterSize(15);
    textPause.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
    textPause.setFillColor(BLACK);

    Text textPlay("Press 'p' to play", font);
    textPlay.setCharacterSize(15);
    textPlay.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
    textPlay.setFillColor(BLACK);

    RenderWindow window(VideoMode(CELL_SIZE * GRID_WIDTH, CELL_SIZE * GRID_HEIGHT + 50), "Game of Life");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::P)
                    isPlaying = !isPlaying;
                else if (event.key.code == Keyboard::Right)
                    delay = std::max(delay - DELAY_INC, 0); // prevent negative value
                else if (event.key.code == Keyboard::Left)
                    delay += DELAY_INC;
                break;
            // case Event::MouseButtonPressed:
            //     if (!isPlaying && event.mouseButton.button == Mouse::Left)
            //     {
            //         int x = double(event.mouseButton.x)/CELL_SIZE;
            //         int y = double(event.mouseButton.y)/CELL_SIZE;
            //         if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
            //             grid[x + y * GRID_WIDTH] = !grid[x + y * GRID_WIDTH];
            //     }
            //     break;
            }
        }

        // display grid and prepare gridNext
        window.clear(WHITE);
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            for (int y = 0; y < GRID_HEIGHT; y++)
            {
                // draw cell
                RectangleShape cell;
                cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                cell.setSize(CELL_VECTOR);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(GRAY);
                if (game.CurrentConfig[y][x])
                    cell.setFillColor(BLACK);
                else
                    cell.setFillColor(WHITE);
                window.draw(cell);
            }
        }

        // prepare gridNext
        if (isPlaying)
        {
            game.next_generation();
        }

        // Additional info
        if (isPlaying)
            window.draw(textPause);
        else
        {
            window.draw(textPlay);
        }
        Text textGeneration("Generation = " + std::to_string(game.Generation-1), font);
        textGeneration.setCharacterSize(15);
        textGeneration.setPosition(10, CELL_SIZE * GRID_HEIGHT + 20);
        textGeneration.setFillColor(BLACK);
        window.draw(textGeneration);

        window.display();
        sleep(milliseconds(delay));
        std::cout << "Generation = " << game.Generation << std::endl;
    }
}