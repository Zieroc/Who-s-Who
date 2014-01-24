//TESTING
#include "Game.h"
#include <iostream>

int main(int args, char* p_args[])
{

	Game* game = new Game();
	DEBUG_MSG("Game Object Created");

	game->Initialize("TEST", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	DEBUG_MSG("Game Initialised");

	DEBUG_MSG("Starting Game Loop");
	while(game->IsRunning())
	{
		game->Update();
		game->HandleEvents();
		game->Draw();
	}
	DEBUG_MSG("Game Loop Exited");

	DEBUG_MSG("Cleaning up");
	game->CleanUp();
	return 0;
}