#include "NPCManager.h"

NPCManager::NPCManager(ContentManager* conManRef, TileMap* tileMapRef)
{
	conMan = conManRef;
	map = tileMapRef;
	max = 175;

	conMan->LoadTexture("blip.png");

	blipManager = new BlipManager(conMan);

	for(int i = 0; i < max; i++)
	{
		Add();
	}

	NPCs.at(0)->SetType(1);
	NPCs.at(1)->SetType(2);

	p1 = 0;
	p2 = 1;
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

	if(NPCs.at(p1)->attacking)
	{
		if(SDL_HasIntersection(&NPCs.at(p1)->bounds, &NPCs.at(p2)->bounds))
		{
			Swap(2);
		}
		else
		{
			blipManager->Add(NPCs.at(p1)->x - 40, NPCs.at(p1)->y - 44);
		}

		NPCs.at(p1)->attacking = false;
	}
	if(NPCs.at(p2)->attacking)
	{
		if(SDL_HasIntersection(&NPCs.at(p1)->bounds, &NPCs.at(p2)->bounds))
		{
			Swap(1);
		}
		else
		{
			blipManager->Add(NPCs.at(p2)->x - 40, NPCs.at(p2)->y - 44);
		}

		NPCs.at(p2)->attacking = false;
	}

	blipManager->Update(timeElapsed, input);
}

void NPCManager::Draw(SDL_Renderer* renderer)
{
	for(std::size_t i = 0; i < NPCs.size(); i++)
	{
		NPCs.at(i)->Draw(renderer);
	}

	blipManager->Draw(renderer);
}

// create a new NPC
void NPCManager::Add()
{
	NPCs.push_back(new NPC(conMan->GetTexture("circle.png"), map));
}

void NPCManager::Swap(int i)
{
	int newGuy = p1;
	while(newGuy == p1 || newGuy == p2)
	{
		newGuy = rand() % max;
	}
	NPCs.at(newGuy)->SetType(i);
	if(i == 1)
	{
		NPCs.at(p1)->SetType(3);
		p1 = newGuy;
	}
	else
	{
		NPCs.at(p2)->SetType(3);
		p2 = newGuy;
	}
}