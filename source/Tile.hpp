#pragma once

#include <SDL2/SDL.h>

struct coordinates {
    int x;
    int y;
};

const int TILE_WIDTH = 20;
const int TILE_HEIGHT = 20;

class Tile{
public:
    Tile();
    ~Tile();
    SDL_Rect* getRect();
    void setPosition(int x, int y);
    coordinates getPosition();
    bool getOpen();
    void setOpen(bool state);

    bool isBomb();
    void setBomb(bool isBomb);

    int getBombsAround();
    void setBombsAround(int nBombs);

    void setFlag(bool f);
    bool haveFlag();

private:
    bool open;
    bool bomb;
    SDL_Rect rectangle;
    int numberOfbombsAround;
    bool flag;
    coordinates position;
};
