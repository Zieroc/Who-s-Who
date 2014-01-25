#include "NPCManager.h"

NPCManager::NPCManager(ContentManager* conManRef, TileMap* tileMapRef, SoundManager* soundManRef)
{
	soundMan = soundManRef;
	conMan = conManRef;
	map = tileMapRef;
	max = 10;

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
	for(std::vector<NPC*>::size_type i = 0; i != NPCs.size(); i++)
	{
		delete(NPCs[i]);
	}
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
			soundMan->PlaySoundEffect("hit.wav");
		}
		else
		{
			//NPCs.at(p1)->Tint(0, 0, 255);
			soundMan->PlaySoundEffect("miss.wav");
		}

		NPCs.at(p1)->attacking = false;
	}
	if(NPCs.at(p2)->attacking)
	{
		if(SDL_HasIntersection(&NPCs.at(p1)->bounds, &NPCs.at(p2)->bounds))
		{
			Swap(1);
			soundMan->PlaySoundEffect("hit.wav");
		}
		else
		{
			soundMan->PlaySoundEffect("miss.wav");
		}

		NPCs.at(p2)->attacking = false;
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
	NPCs.push_back(new NPC(conMan->GetTexture("circle.png"), conMan->GetTexture("blip.png"), map));
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