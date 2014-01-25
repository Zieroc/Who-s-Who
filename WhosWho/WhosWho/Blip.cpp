#include "Blip.h"

Blip::Blip(CC_Texture* texture, int playerX, int playerY)
{
	image = new Sprite(texture, 96, 96);
	x = playerX;
	y = playerY;
	alive == true;
}

Blip::~Blip()
{
}

void Blip::Update(Uint32 timeElapsed, InputHandler*)
{
	image->Update(timeElapsed);
}

void Blip::Draw(SDL_Renderer* renderer)
{
	if(alive)
	{
		image->SwitchAnimation(0);
		image->Draw(renderer, x, y, flipped);

		if(image->m_CurrentAnimation->GetFrame() == 3)
		{
			alive = false;
		}
	}
}