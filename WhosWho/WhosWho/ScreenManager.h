#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include "GameScreen.h"
#include "Debug.h"
//#include "Camera.h"
#include "ContentManager.h"
#include <SDL.h>

class ScreenManager
{
public:
	enum GameState { Gameplay, Quit};
	ScreenManager(SDL_Renderer* renderer, ContentManager* conManRef/*Camera* camera*/);
	~ScreenManager();
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(Uint32 timeElapsed);
	void HandleEvents(SDL_Event sdlEvent);
	void Draw();
	void SwitchState(GameState newState); //Change the current state of the game
	//Camera* GetCamera();
private:
	GameScreen* m_p_Screen;
	GameState m_CurrentState;
	GameState m_LastState;
	InputHandler* m_p_InputHandler;
	SDL_Renderer* m_p_Renderer; //Reference to the render that will be passed to screens to allow them to draw
	void SwitchScreens(); //Switch from the current screen to the new screen, handling loads and unloads etc.
	ContentManager* m_p_ContentManager;
	//Camera* m_p_Camera;
};

#endif

