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
	delete(npcManager);
}

void GameplayScreen::Initialize(ScreenManager* manager)
{
	m_p_Manager = manager;
}

void GameplayScreen::LoadContent(SDL_Renderer* renderer, ContentManager* conMan)
{
	m_p_SoundManager = new SoundManager(conMan);
	conMan->LoadSoundEffect("miss.wav");
	conMan->LoadSoundEffect("hit.wav");
	
	conMan->LoadTexture("Tiles.png");
	m_p_Map = new TileMap(conMan->GetTexture("Tiles.png"));
	m_p_Map->LoadMap("data/Files/arena.lvl");

	conMan->LoadTexture("circle.png");
	conMan->LoadTexture("blip.png");
	npcManager = new NPCManager(conMan, m_p_Map, m_p_SoundManager);
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed, InputHandler* input)
{
	npcManager->Update(timeElapsed, input);
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	m_p_Map->Draw(renderer/*, m_p_Manager->GetCamera()*/);
	npcManager->Draw(renderer);
}

void GameplayScreen::HandleInput(InputHandler* input)
{
	if(input->KeyPressed(SDLK_SPACE))
	{
		npcManager->Swap(1);
	}
}

void GameplayScreen::HandleEvents(SDL_Event sdlEvent)
{
}
