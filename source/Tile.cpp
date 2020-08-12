#include "Tile.hpp"


Tile::Tile(){
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = TILE_WIDTH;
    rectangle.h = TILE_HEIGHT;
    open = false;
    bomb = false;
    flag = false;
    numberOfbombsAround = 0;
}


Tile::~Tile(){
}

SDL_Rect* Tile::getRect(){
    SDL_Rect* pointer;
    pointer = &rectangle;

    return pointer;
}

void Tile::setPosition(int x, int y){
    rectangle.x = x;
    rectangle.y = y;
    position.x = x;
    position.y = y;
}

coordinates Tile::getPosition(){
    return position;
}

bool Tile::getOpen(){
    return open;
}

void Tile::setOpen(bool state){
    open = state;
}

bool Tile::isBomb(){
    return bomb;
}

void Tile::setBomb(bool isBomb){
    bomb = isBomb;
}

int Tile::getBombsAround(){
    return numberOfbombsAround;
}
void Tile::setBombsAround(int nBombs){
    numberOfbombsAround = nBombs;
}
void Tile::setFlag(bool f){
    flag = f;
}
bool Tile::haveFlag(){
    return flag;
}
