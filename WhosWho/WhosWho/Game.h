#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <SDL.h>
#include <SDL_mixer.h>
//#include "ContentManager.h"
//#include "ScreenManager.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char* title, int x, int y, int width, int height, int flags);
	void Update();
	void Draw();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
	Uint32 GetTimeElapsed(); //Get the time elapsed since the last frame
private:
	bool m_Running;
	SDL_Window* m_p_Window;
	SDL_Renderer * m_p_Renderer;
	//ScreenManager* m_p_ScreenManager;
	Uint32 m_LastTime; //The time of the last frame
	//ContentManager* m_p_ContentManager;
	//Camera* m_p_Camera;
};

#endif