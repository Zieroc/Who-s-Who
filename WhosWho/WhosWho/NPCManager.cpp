#include "NPCManager.h"

NPCManager::NPCManager(ContentManager* conManRef, TileMap* tileMapRef)
{
	conMan = conManRef;
	map = tileMapRef;

	for(int i = 0; i < 10; i++)
	{
		Add();
	}

	NPCs.at(0)->SetType(1);
	NPCs.at(1)->SetType(2);
}

NPCManager::~NPCManager()
{
}

void NPCManager::Update(Uint32 timeElapsed, InputHandler* input)
{
	for(std::size_t i = 0; i < NPCs.size(); i++)
	{
		NPCs.at(i)->Update(timeElapsed, input);
	}
}

void NPCManager::Draw(SDL_Renderer* renderer)
{
	for(std::size_t i = 0; i < NPCs.size(); i++)
	{
		NPCs.at(i)->Draw(renderer);
	}
}

// create a new NPC
void NPCManager::Add()
{
	NPCs.push_back(new NPC(conMan->GetTexture("circle.png"), map));
}