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

	conMan->LoadTexture("circle.png");
	npcTest = new NPC();
	npcTest->Initialize(conMan->GetTexture("circle.png"), m_p_Map);
	npcTest->SetType(1);

	npc2 = new NPC();
	npc2->Initialize(conMan->GetTexture("circle.png"), m_p_Map);
	npc2->SetType(2);
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed, InputHandler* input)
{
	npcTest->Update(timeElapsed, input);
	npc2->Update(timeElapsed, input);
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	m_p_Map->Draw(renderer/*, m_p_Manager->GetCamera()*/);
	npcTest->Draw(renderer);
	npc2->Draw(renderer);
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
