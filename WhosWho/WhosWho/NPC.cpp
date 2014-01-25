#include "NPC.h"
#include <stdlib.h>

NPC::NPC(CC_Texture* texture)
{
	// generate random position for enemy
	x = rand() % 740 + 20;
	y = rand() % 600 + 20;
	
	//x = 100;
	//y = 100;

	image = new Sprite(texture, 16, 16);
	speed = 2;
	type = Normal;
}

NPC::~NPC()
{
}

void NPC::Update(Uint32 timeElapsed)
{
	image->Update(timeElapsed);
}

void NPC::Draw(SDL_Renderer* renderer)
{
	image->Draw(renderer, x, y, flipped);
}