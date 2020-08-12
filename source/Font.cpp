#include "Font.hpp"


Font::Font(){
    messageRect.x = 0;
    messageRect.y = 0;
    messageRect.w = FONT_WIDTH;
    messageRect.h = FONT_HEIGHT;
    mainFont = NULL;
    messageSurface = NULL;
    messageTexture = NULL;
    color = {255,255,255};
    setFont();
}
Font::~Font(){

}

void Font::setSize(int nLetter, int nLines){
    messageRect.w = FONT_WIDTH * nLetter;
    messageRect.h = FONT_HEIGHT * nLines;
}

void Font::setRenderer(SDL_Renderer* r){
    mainRenderer = r;
}

SDL_Rect* Font::getTextRect(){
    SDL_Rect* pointer;
    pointer = &messageRect;

    return pointer;
}

bool Font::setFont(){
    mainFont  = TTF_OpenFont(FONT_PATH,FONT_SIZE);
    if(mainFont == NULL)
        printf("TTF ERROR: %s\n", TTF_GetError());
}

void Font::setColor(SDL_Color c){
    color = c;
}

void Font::setText(char* c){
    strcpy(text,c);
    messageSurface = TTF_RenderText_Blended(mainFont, text, color);
    if(messageSurface == NULL)
        printf("TTF ERROR: %s\n", TTF_GetError());
    messageTexture = SDL_CreateTextureFromSurface(mainRenderer, messageSurface);
    if(messageSurface == NULL)
        printf("TTF ERROR: %s\n", TTF_GetError());
}

void Font::setPosition(int x, int y){
    messageRect.x = x;
    messageRect.y = y;
}

SDL_Texture* Font::getTexture(){

    return messageTexture;
}
