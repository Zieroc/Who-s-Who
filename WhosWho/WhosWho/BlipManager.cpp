#include "BlipManager.h"

BlipManager::BlipManager(ContentManager* conManRef)
{
	con = conManRef;
}

BlipManager::~BlipManager()
{
}


void BlipManager::Update(Uint32 timeElapsed, InputHandler* g)
{
	for(std::size_t i = 0; i < Blips.size(); i++)
	{
		Blips.at(i)->Update(timeElapsed, g);
	}
}

void BlipManager::Draw(SDL_Renderer* renderer)
{
	for(std::size_t i = 0; i < Blips.size(); i++)
	{
		Blips.at(i)->Draw(renderer);
	}
}

// create a new Blip
void BlipManager::Add(int playerX, int playerY, int hit2)
{
	hit = hit2;

	if(hit == true)
	{
		Blips.push_back(new Blip(con->GetTexture("blip2.png"), playerX, playerY));
	}

	if(hit == false)
	{
		Blips.push_back(new Blip(con->GetTexture("blip.png"), playerX, playerY));
	}
}