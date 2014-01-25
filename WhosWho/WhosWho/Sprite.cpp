#include "Sprite.h"
#include <iostream>

Sprite::Sprite(CC_Texture* texture, int width, int height)
{
	m_p_Texture = texture;

	m_DestinationRect.w = width;
	m_DestinationRect.h = height;

	m_SourceRect.w = width;
	m_SourceRect.h = height;

	m_Columns = texture->GetWidth() / width;
	m_Rows = texture->GetHeight() / height;

	m_Timer = 0;
	m_Interval = 100;
}

Sprite::~Sprite()
{
}

void Sprite::Update(Uint32 timeElapsed)
{
//	if (m_Animate)
//	{
//		m_Timer += timeElapsed;
//		//Check the timer is more than the chosen interval
//		if (m_Timer >= m_Interval)
//		{
//			//Show the next frame
//			m_CurrentAnimation->NextState();
//			//Reset the timer
//			m_Timer = 0;
//		}
//	}
}

void Sprite::Draw(SDL_Renderer* renderer, int x, int y, bool flipped /*Camera* camera*/)
{
	m_DestinationRect.x = x;
	m_DestinationRect.y = y;

	m_SourceRect.x = 0;//m_SourceRect.w;// * (m_CurrentAnimation->GetFrame() % m_Columns);
    m_SourceRect.y = 0;//m_SourceRect.h;// * (m_CurrentAnimation->GetFrame() / m_Columns);

	if(flipped)
	{
		SDL_RenderCopyEx(renderer, m_p_Texture->GetTexture(), &m_SourceRect, &m_DestinationRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else
	{
		SDL_RenderCopy(renderer, m_p_Texture->GetTexture(), &m_SourceRect, &m_DestinationRect);
	}
}

//void Sprite::AddAnimation(int startFrame, int  endFrame, bool looping)
//{
//	m_p_Animations.push_back(new Animation(startFrame, endFrame, looping));
//}
//
//void Sprite::SwitchAnimation(int animation)
//{
//	m_CurrentAnimation = m_p_Animations[animation];
//}

void Sprite::Tint(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(m_p_Texture->GetTexture(), r, g, b);
}