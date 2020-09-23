#include "Game.hpp"

int main( int argc, char* args[] )
{
	Game* game = NULL;
	game = new Game(20,15,10);
	delete [] game;
	return 0;
}
