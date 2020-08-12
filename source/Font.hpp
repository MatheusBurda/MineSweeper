#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

#define FONT_PATH "arcadeclassic.regular.ttf"
const int FONT_SIZE = 80;
const int FONT_WIDTH = 10;
const int FONT_HEIGHT = 20;

class Font{
public:
    Font();
    ~Font();
    void setRenderer(SDL_Renderer* r);
    SDL_Rect* getTextRect();
    void setSize(int nLetter, int nLines);
    bool setFont();
    void setColor(SDL_Color c);
    void setText(char* c);
    void setPosition(int x, int y);
    SDL_Texture* getTexture();

private:
    TTF_Font* mainFont;
    SDL_Surface* messageSurface;
    SDL_Texture* messageTexture;
    SDL_Rect messageRect;
    SDL_Color color;
    char text[10];
    SDL_Renderer* mainRenderer;
};
