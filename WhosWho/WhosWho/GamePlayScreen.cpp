#include "GameplayScreen.h"
#include <iostream>
#include "ScreenManager.h"

//CURRENTLY USED FOR TESTING

GameplayScreen::GameplayScreen()
{
}

GameplayScreen::~GameplayScreen()
{
	delete(m_p_Map);
}

void GameplayScreen::Initialize(ScreenManager* manager)
{
	m_p_Manager = manager;
}

void GameplayScreen::LoadContent(SDL_Renderer* renderer, ContentManager* conMan)
{
	/*m_p_SoundManager = new SoundManager(conMan);
	conMan->LoadSoundEffect("laser.wav");
	conMan->LoadTexture("bob.png");
	conMan->LoadTexture("square.png");*/
	//*m_p_SoundManager->PlaySoundEffect("laser.wav");*/
	conMan->LoadTexture("Tiles.png");
	m_p_Map = new TileMap(conMan->GetTexture("Tiles.png"));
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed)
{
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	m_p_Map->Draw(renderer/*, m_p_Manager->GetCamera()*/);
}

void GameplayScreen::HandleInput(InputHandler* input)
{
	/*if(input->KeyPressed(SDLK_SPACE))
	{
		m_p_Manager->SwitchState(ScreenManager::GameState::Quit);
	}*/
}

void GameplayScreen::HandleEvents(SDL_Event sdlEvent)
{
}
