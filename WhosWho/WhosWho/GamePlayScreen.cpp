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
	delete(m_p_SoundManager);
	delete(font);
	delete(text);
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
	npcManager = new NPCManager(conMan, m_p_Map, m_p_SoundManager);

	font = TTF_OpenFont("data/Files/SourceSansPro-Semibold.ttf", 40);

	rendererRef = renderer;
	text = RenderText("WHO'S WHO?");
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
	SDL_Rect dest;
	dest.x = 250;
	dest.y = 20;
	dest.w = 300;
	dest.h = 80;

	SDL_RenderCopy(renderer, text, NULL, &dest);
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
    TTF_CloseFont(font);
 
    return texture;
}
