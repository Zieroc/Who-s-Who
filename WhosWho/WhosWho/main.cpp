//TESTING
#include "Game.h"
#include <iostream>
#include <time.h>

int main(int args, char* p_args[])
{
	// For my random numbers (for npc positions)
	srand (time(NULL));

	Game* game = new Game();
	DEBUG_MSG("Game Object Created");

	game->Initialize("Who's Who?", 50, 50, 800, 640, SDL_WINDOW_SHOWN);
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