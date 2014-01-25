#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H
#include "GameScreen.h"
//#include "Character.h"
#include "TileMap.h"
#include "SoundManager.h"
#include <SDL_mixer.h>
#include "NPCManager.h"

class GameplayScreen : public GameScreen
{
public:
	GameplayScreen();
	~GameplayScreen();
	void Initialize(ScreenManager* manager);
	void LoadContent(SDL_Renderer* renderer, ContentManager* conMan);
	void UnloadContent();
	void Update(Uint32 timeElapsed, InputHandler* input);
	void Draw(SDL_Renderer* renderer);
	void HandleInput(InputHandler* input);
	void HandleEvents(SDL_Event sdlEvent);
private:
	TileMap* m_p_Map;
	NPCManager* npcManager;
	SoundManager* m_p_SoundManager;
};

#endif

