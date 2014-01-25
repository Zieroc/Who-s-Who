#include "NPCManager.h"

NPCManager::NPCManager(ContentManager* conManRef)
{
	conMan = conManRef;

	for(int i = 0; i < 10; i++)
	{
		Add();
	}
}

NPCManager::~NPCManager()
{
}

void NPCManager::Update(Uint32 timeElapsed)
{
	for(std::size_t i = 0; i < NPCs.size(); i++)
	{
		NPCs.at(i)->Update(timeElapsed);
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
	NPCs.push_back(new NPC(conMan->GetTexture("circle.png")));
}