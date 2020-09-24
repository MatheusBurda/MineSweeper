#include "Game.hpp"


Game::Game(int lines, int columns, int nBombs){
    numberOfbombs = nBombs;
    isRunning = false;
    window = NULL;
    renderer = NULL;
    nLines = lines;
    nColumns = columns;
    numberOfTiles = lines * columns;
    textTiles = NULL;
    matrixOfTiles = NULL;
    initSDL();
    startNewGame();
}

Game::~Game(){

}

void Game::initSDL(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (TILE_WIDTH+1)*(nColumns+2) ,(TILE_HEIGHT + 1)*(nLines+2), SDL_WINDOW_SHOWN);
        if(window == NULL){
            printf("Window could not be created\n");
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer == NULL){
            printf("Renderer could not be created\n");
        }
        if(TTF_Init() < 0)
            printf("ERROR: %s\n",TTF_GetError());
    }
}

void Game::setTiles(){
    matrixOfTiles = new Tile* [nLines];
    for(int j = 0; j < nLines; j++)
        matrixOfTiles[j] = new Tile [nColumns];

    for(int i = 0; i < nLines; i++)
        for(int j = 0; j < nColumns; j++)
            matrixOfTiles[i][j].setPosition((TILE_WIDTH+1)*(j+1),(TILE_HEIGHT + 1)*(i+1));
}

void Game::setTextTiles(){
    textTiles = new Font [12];
    for(int i = 0; i<12; i++){
        textTiles[i].setRenderer(renderer);
    }
    textTiles[0].setColor({0,0,0});
    textTiles[0].setText("x");
    textTiles[1].setText("1");
    textTiles[2].setText("2");
    textTiles[3].setText("3");
    textTiles[4].setText("4");
    textTiles[5].setText("5");
    textTiles[6].setText("6");
    textTiles[7].setText("7");
    textTiles[8].setText("8");

    textTiles[9].setColor({105, 105, 105});
    textTiles[9].setPosition(22,0);
    textTiles[9].setSize(5,1);
    textTiles[9].setText("Bombs");

    char bombNumberText[3];
    textTiles[10].setColor({105, 105, 105});
    textTiles[10].setSize(sprintf(bombNumberText, "%d", numberOfbombs),1);
    textTiles[10].setPosition(82,0);
    textTiles[10].setText(bombNumberText);

    textTiles[11].setColor({205, 0, 0});
    textTiles[11].setSize(9,1);
    textTiles[11].setPosition(((TILE_WIDTH+1)*(nColumns+2)/2) - 40,0);
    textTiles[11].setText("GAME OVER");

}

void Game::setAllBombs(){
    srand((unsigned) time(0));
    int x ,y, cont;
    for(int k = 0; k < numberOfbombs; k++){
        while(1){
            x = (rand() % nLines);
            y = (rand() % nColumns);
            if(!matrixOfTiles[x][y].isBomb()){
                matrixOfTiles[x][y].setBomb(true);
                break;
            }
        }
    }

    for(int i = 0; i < nLines; i++)
        for(int j = 0; j < nColumns; j++){
            cont = 0;
            if(i>0 && i<(nLines-1)){
                if(j>0 && j < (nColumns-1)){
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j+1].isBomb())
                        cont++;
                }
                else if(j == (nColumns-1) ){
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j-1].isBomb())
                        cont++;

                }
                else{
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j+1].isBomb())
                        cont++;
                }
            }
/**********************************************************************/
            else if(i == (nLines-1)){
                if(j>0 && j<(nColumns-1)){
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                }
                else if(j == (nColumns-1)){
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                }
                else{
                    if(matrixOfTiles[i-1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i-1][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                }
            }
/**********************************************************************/
            else{
                if(j>0 && j<(nColumns-1)){
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j+1].isBomb())
                        cont++;
                }
                else if(j == (nColumns-1)){
                    if(matrixOfTiles[i][j-1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j-1].isBomb())
                        cont++;
                }
                else{
                    if(matrixOfTiles[i][j+1].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j].isBomb())
                        cont++;
                    if(matrixOfTiles[i+1][j+1].isBomb())
                        cont++;
                }
            }
            matrixOfTiles[i][j].setBombsAround(cont);
        }


    /*for(int i = 0; i < nLines; i++)
        for(int j = 0; j < nColumns; j++)
            if(matrixOfTiles[i][j].isBomb())
                matrixOfTiles[i][j].setOpen(true);*/

}

void Game::zeroWave(int i, int j){
    if(matrixOfTiles[i][j].getOpen())
        return;
    matrixOfTiles[i][j].setOpen(true);
    if(matrixOfTiles[i][j].getBombsAround() == 0){
        if(i>0 && i<(nLines-1)){
            if(j>0 && j < (nColumns-1)){
                zeroWave(i-1,j);
                zeroWave(i,j-1);
                zeroWave(i,j+1);
                zeroWave(i+1,j);
                zeroWave(i-1,j-1);
                zeroWave(i+1,j-1);
                zeroWave(i+1,j+1);
                zeroWave(i-1,j+1);

            }
            else if(j == (nColumns-1) ){
                zeroWave(i-1,j);
                zeroWave(i,j-1);
                zeroWave(i+1,j);
                zeroWave(i-1,j-1);
                zeroWave(i+1,j-1);
            }
            else{
                zeroWave(i-1,j);
                zeroWave(i,j+1);
                zeroWave(i+1,j);
                zeroWave(i+1,j+1);
                zeroWave(i-1,j+1);
            }
        }
        /**********************************************************************/
        else if(i == (nLines-1)){
            if(j>0 && j<(nColumns-1)){
                zeroWave(i-1,j);
                zeroWave(i,j-1);
                zeroWave(i,j+1);
                zeroWave(i-1,j-1);
                zeroWave(i-1,j+1);
            }
            else if(j == (nColumns-1)){
                zeroWave(i-1,j);
                zeroWave(i,j-1);
                zeroWave(i-1,j-1);
            }
            else{
                zeroWave(i-1,j);
                zeroWave(i,j+1);
                zeroWave(i-1,j+1);
            }
        }
        /**********************************************************************/
        else{
            if(j>0 && j<(nColumns-1)){
                zeroWave(i,j-1);
                zeroWave(i,j+1);
                zeroWave(i+1,j);
                zeroWave(i+1,j+1);
                zeroWave(i+1,j-1);
            }
            else if(j == (nColumns-1)){
                zeroWave(i,j-1);
                zeroWave(i+1,j);
                zeroWave(i+1,j-1);
            }
            else{
                zeroWave(i,j+1);
                zeroWave(i+1,j);
                zeroWave(i+1,j+1);
            }
        }
    }
}

bool Game::running(){
    return isRunning;
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            close();

            break;
        case SDL_MOUSEBUTTONDOWN:
            if(running()){
                SDL_GetMouseState(&xMousePosition, &yMousePosition);
                updateTiles(event.button);
            }
            else
                startNewGame();
            break;
        default:
            break;
    }
}

void Game::updateTiles(SDL_MouseButtonEvent& button){
    for(int i = 0; i < nLines; i++){
        for(int j = 0; j < nColumns; j++){
            if((matrixOfTiles[i][j].getPosition().x < xMousePosition) && (xMousePosition <= (matrixOfTiles[i][j].getPosition().x + TILE_WIDTH + 1))
             && (matrixOfTiles[i][j].getPosition().y < yMousePosition) && (yMousePosition <= (matrixOfTiles[i][j].getPosition().y + TILE_HEIGHT + 1))){
                if(button.button == SDL_BUTTON_LEFT){
                    if(matrixOfTiles[i][j].isBomb()){
                        matrixOfTiles[i][j].setOpen(true);
                        gameOver(true);
                    }
                    else if(!matrixOfTiles[i][j].getBombsAround())
                        zeroWave(i,j);
                    else
                        matrixOfTiles[i][j].setOpen(true);
                }
                else if(button.button == SDL_BUTTON_RIGHT){
                    if(!matrixOfTiles[i][j].haveFlag())
                        matrixOfTiles[i][j].setFlag(true);
                    else
                        matrixOfTiles[i][j].setFlag(false);
                }
            }
        }
    }
}

void Game::draw(){
    int x;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);
    if(isRunning){
        SDL_RenderCopy(renderer, textTiles[9].getTexture(), NULL, textTiles[9].getTextRect());
        SDL_RenderCopy(renderer, textTiles[10].getTexture(), NULL, textTiles[10].getTextRect());
    }
    else
        SDL_RenderCopy(renderer, textTiles[11].getTexture(), NULL, textTiles[11].getTextRect());

    for(int i = 0; i < nLines; i++)
        for(int j = 0; j < nColumns; j++){
            if(matrixOfTiles[i][j].getOpen()){
                if(matrixOfTiles[i][j].isBomb())
                    SDL_SetRenderDrawColor(renderer, 185, 0, 0, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
            }
            else if(matrixOfTiles[i][j].haveFlag())
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, matrixOfTiles[i][j].getRect());
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, matrixOfTiles[i][j].getRect());

            if(matrixOfTiles[i][j].getOpen()){
                if(matrixOfTiles[i][j].isBomb()){
                    textTiles[0].setPosition((matrixOfTiles[i][j].getPosition().x + 6), matrixOfTiles[i][j].getPosition().y);
                    SDL_RenderCopy(renderer, textTiles[0].getTexture(), NULL, textTiles[0].getTextRect());
                }
                else{
                    x = matrixOfTiles[i][j].getBombsAround();
                    if(x != 0){
                        textTiles[x].setPosition((matrixOfTiles[i][j].getPosition().x + 6), matrixOfTiles[i][j].getPosition().y);
                        SDL_RenderCopy(renderer, textTiles[x].getTexture(), NULL, textTiles[x].getTextRect());
                    }
                }
            }
        }
    SDL_RenderPresent(renderer);
}

void Game::mainGameLoop(){
    while(running()){
        checkEndedGame();
		handleEvents();
		draw();
	}
    close();
}

void Game::checkEndedGame(){
    int countArmedBombs = 0;
    for(int i = 0; i < nLines; i++)
        for(int j = 0; j < nColumns; j++)
            if(matrixOfTiles[i][j].isBomb() && !matrixOfTiles[i][j].haveFlag())
                countArmedBombs++;
    if(countArmedBombs == 0)
        gameOver(false);
}

void Game::gameOver(bool exploded){
    isRunning = false;
    if(!exploded){
        textTiles[11].setColor({255 , 255, 255});
        textTiles[11].setText(" SUCCESS ");
        for(int i = 0; i < nLines; i++)
            for(int j = 0; j < nColumns; j++)
                if(!matrixOfTiles[i][j].isBomb())
                    matrixOfTiles[i][j].setOpen(true);
    }
    else{
        for(int i = 0; i < nLines; i++)
            for(int j = 0; j < nColumns; j++)
                matrixOfTiles[i][j].setOpen(true);
    }
    draw();
    while(true)
        handleEvents();
}

void Game::startNewGame(){
    deleteTiles();
    setTiles();
    if(textTiles == NULL)
        setTextTiles();
    setAllBombs();
    isRunning = true;
    mainGameLoop();
}

void Game::close(){
    deleteText();
    deleteTiles();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
}

void Game::deleteTiles(){
    if(matrixOfTiles == NULL)
        return;
    for(int j = 0; j < nLines; j++)
        delete [] matrixOfTiles[j];
    delete [] matrixOfTiles;
}

void Game::deleteText(){
    delete[]textTiles;
}