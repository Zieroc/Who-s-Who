#include "NPC.h"

NPC::NPC()
{
	x = 100;
	y = 100;
}

NPC::~NPC()
{
}

void NPC::Initialize(CC_Texture* texture)
{
	image = new Sprite(texture, 16, 16);
	speed = 2;
	type = Normal;
}

void NPC::Update(Uint32 timeElapsed)
{
	image->Update(timeElapsed);
}

void NPC::Draw(SDL_Renderer* renderer)
{
	image->Draw(renderer, x, y, flipped);
}