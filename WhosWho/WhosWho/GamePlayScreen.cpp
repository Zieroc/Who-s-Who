#include "GameplayScreen.h"
#include <iostream>
#include "ScreenManager.h"

//CURRENTLY USED FOR TESTING

GameplayScreen::GameplayScreen()
{
}

GameplayScreen::~GameplayScreen()
{
	/*delete(m_p_Bob);
	delete(m_p_Square);
	delete(m_p_Map);*/
}

void GameplayScreen::Initialize(ScreenManager* manager)
{
	m_p_Manager = manager;
}

void GameplayScreen::LoadContent(SDL_Renderer* renderer, ContentManager* conMan)
{
	/*m_p_SoundManager = new SoundManager(conMan);
	conMan->LoadSoundEffect("laser.wav");
	conMan->LoadTexture("Tiles.png");
	conMan->LoadTexture("bob.png");
	conMan->LoadTexture("square.png");*/
	//*m_p_SoundManager->PlaySoundEffect("laser.wav");*/

	conMan->LoadTexture("circle.png");
	testNPC->Initialize(conMan->GetTexture("circle.png"));
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed)
{
	testNPC->Update(timeElapsed);
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	testNPC->Draw(renderer);
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
