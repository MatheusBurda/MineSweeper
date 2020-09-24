#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include "Tile.hpp"
#include "Font.hpp"
#include <cstdlib>
#include <ctime>


#define SCREEN_TITLE "MINESWEEPER"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game{

public:
    Game(int lines, int columns, int nBombs);
    ~Game();
    void initSDL();
    void setTiles();
    void deleteTiles();
    void deleteText();
    bool running();

    void handleEvents();
    void updateTiles(SDL_MouseButtonEvent& button);
    void draw();
    void close();
    void setTextTiles();
    void setAllBombs();
    void zeroWave(int i, int j);

    void mainGameLoop();
    void checkEndedGame();
    void gameOver(bool exploded);
    void startNewGame();

private:
    bool isRunning;

    SDL_Window *window;
    SDL_Renderer *renderer;
    int numberOfTiles;
    Tile **matrixOfTiles;

    int nLines;
    int nColumns;
    int xMousePosition;
    int yMousePosition;
    int numberOfbombs;

    Font *textTiles;

};
