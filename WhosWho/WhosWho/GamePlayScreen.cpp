#include "GameplayScreen.h"
#include <iostream>
#include "ScreenManager.h"
#include <string>
#include <sstream>

//CURRENTLY USED FOR TESTING

GameplayScreen::GameplayScreen()
{
	p1Kills = 0;
	p2Kills = 0;
}

GameplayScreen::~GameplayScreen()
{
	delete(m_p_Map);
	delete(npcManager);
	delete(m_p_SoundManager);
	delete(font);
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
	//*m_p_SoundManager->PlaySoundEffect("laser.wav");*/
	
	conMan->LoadTexture("Tiles.png");
	m_p_Map = new TileMap(conMan->GetTexture("Tiles.png"));
	m_p_Map->LoadMap("data/Files/arena.lvl");

	conMan->LoadTexture("circle.png");
	npcManager = new NPCManager(conMan, m_p_Map, m_p_SoundManager, &p1Kills, &p2Kills);

	font = TTF_OpenFont("data/Files/SourceSansPro-Semibold.ttf", 60);

	rendererRef = renderer;

	kills1 = RenderText("P1 KILLS: 0        P2 KILLS: 0");
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(Uint32 timeElapsed, InputHandler* input)
{
	npcManager->Update(timeElapsed, input);

	std::stringstream Stream;
	Stream.str("");
	Stream << "P1 KILLS: ";
	Stream << p1Kills;
	Stream << "        P2 KILLS: ";
	Stream << p2Kills;

	SDL_DestroyTexture(kills1);
	kills1 = RenderText(Stream.str().c_str());
}

void GameplayScreen::Draw(SDL_Renderer* renderer)
{
	m_p_Map->Draw(renderer/*, m_p_Manager->GetCamera()*/);
	npcManager->Draw(renderer);
	SDL_Rect dest1;
	SDL_Rect dest2;
	dest1.x = 100;
	dest1.y = 20;
	dest1.w = 600;
	dest1.h = 40;

	SDL_RenderCopy(renderer, kills1, NULL, &dest1);
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

SDL_Texture* GameplayScreen::RenderText(const char* message)
{
	SDL_Color colour;
	colour.a = 255;
	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
	SDL_Surface *surf = TTF_RenderText_Blended(font, message, colour);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(rendererRef, surf);
    //Clean up unneeded stuff
    SDL_FreeSurface(surf);
 
    return texture;
}
