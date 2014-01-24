#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H
#include "GameScreen.h"
//#include "Character.h"
#include "TileMap.h"
//#include "SoundManager.h"
#include <SDL_mixer.h>
#include "NPC.h"

//CURRENTLY USED FOR TESTING

class GameplayScreen : public GameScreen
{
public:
	GameplayScreen();
	~GameplayScreen();
	void Initialize(ScreenManager* manager);
	void LoadContent(SDL_Renderer* renderer, ContentManager* conMan);
	void UnloadContent();
	void Update(Uint32 timeElapsed);
	void Draw(SDL_Renderer* renderer);
	void HandleInput(InputHandler* input);
	void HandleEvents(SDL_Event sdlEvent);
private:
	TileMap* m_p_Map;
	NPC* npcTest;
};

#endif

