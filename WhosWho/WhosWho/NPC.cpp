#include "NPC.h"

NPC::NPC(CC_Texture* texture, TileMap* map)
{

	x = rand() % 740 + 20;
	y = rand() % 600 + 20;
	
	image = new Sprite(texture, 16, 16);
	speed = 70;
	type = Normal;
	bounds.x = x;
	bounds.y = y;
	bounds.w = texture->GetWidth();
	bounds.h = texture->GetHeight();
	m_p_Map = map;
}

NPC::~NPC()
{
	delete(m_p_Map);
	delete(image);
}


void NPC::Update(Uint32 timeElapsed, InputHandler* input)
{
	image->Update(timeElapsed);

	velX = 0;
	velY = 0;
	
	if(type == Normal)
	{

	}
	else if(type == Player1)
	{
		if(input->KeyPressed(SDLK_w))
		{
			velY = -speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_s))
		{
			velY = speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_a))
		{
			velX = -speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_d))
		{
			velX = speed * (timeElapsed / 1000.0f);
		}
	}

	else if(type == Player2)
	{
		if(input->KeyPressed(SDLK_UP))
		{
			velY = -speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_DOWN))
		{
			velY = speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_LEFT))
		{
			velX = -speed * (timeElapsed / 1000.0f);
		}
		if(input->KeyPressed(SDLK_RIGHT))
		{
			velX = speed * (timeElapsed / 1000.0f);
		}
	}

	HorizontalTileCollisionTest();
	VerticalTileCollisionTest();

	x += velX;
	y += velY;
	CalcBounds();
}

void NPC::Draw(SDL_Renderer* renderer)
{
	image->Draw(renderer, x, y, flipped);
}

void NPC::HorizontalTileCollisionTest()
{
	if(!velX == 0) //If we aren't moving horizontally we can't collide with the map horizontally so only check if we have a horizontally velcoity
	{

		//Calculate the new position of the object if it moved at this amount
		SDL_Rect movedBounds(bounds);
		movedBounds.x += velX;

		float corner1X, corner1Y, corner2X, corner2Y; //The top and bottom corner or the left or right side depending on how we are moving 

		if(velX < 0)
		{
			corner1X = movedBounds.x;
			corner1Y = movedBounds.y + 1;

			corner2X = movedBounds.x;
			corner2Y = movedBounds.y + movedBounds.h - 1;
		}
		else
		{
			corner1X = movedBounds.x + movedBounds.w;
			corner1Y = movedBounds.y + 1;

			corner2X = movedBounds.x + movedBounds.w;
			corner2Y = movedBounds.y + movedBounds.h - 1;
		}

		float mapCell1X = m_p_Map->GetCellByPointX(floorf(corner1X));
		float mapCell1Y = m_p_Map->GetCellByPointY(floorf(corner1Y)); //Get the Map cell that corner 1 is in
		float mapCell2X = m_p_Map->GetCellByPointX(floorf(corner2X));
		float mapCell2Y = m_p_Map->GetCellByPointY(floorf(corner2Y)); //Get the Map cell that corner 2 is in

		//If it will be an impassable cell then don't let the object move
		if (!m_p_Map->IsCellPassable(mapCell1X, mapCell1Y) || !m_p_Map->IsCellPassable(mapCell2X, mapCell2Y))
		{
			velX = 0;
		}
	}
}

void NPC::VerticalTileCollisionTest()
{
	if(!velY == 0) //If we aren't moving vertically we can't collide with the map vertically so only check if we have a y velocity
	{
		//Calculate the new position of the object if it moved at this amount
		SDL_Rect movedBounds(bounds);
		movedBounds.y += velY;

		float corner1X, corner1Y, corner2X, corner2Y; //The left and right corner or the top or bottom side depending on how we are moving 

		if(velY < 0)
		{
			corner1X = movedBounds.x + 1;
			corner1Y = movedBounds.y;

			corner2X = movedBounds.x + movedBounds.w - 1;
			corner2Y = movedBounds.y;
		}
		else
		{
			corner1X = movedBounds.x + 1;
			corner1Y = movedBounds.y + movedBounds.h;

			corner2X = movedBounds.x + movedBounds.w - 1;
			corner2Y = movedBounds.y + movedBounds.h;
		}

		float mapCell1X = m_p_Map->GetCellByPointX(floorf(corner1X));
		float mapCell1Y = m_p_Map->GetCellByPointY(floorf(corner1Y)); //Get the Map cell that corner 1 is in
		float mapCell2X = m_p_Map->GetCellByPointX(floorf(corner2X));
		float mapCell2Y = m_p_Map->GetCellByPointY(floorf(corner2Y)); //Get the Map cell that corner 2 is in

		//If it will be an impassable cell then don't let the object move
		if (!m_p_Map->IsCellPassable(mapCell1X, mapCell1Y) || !m_p_Map->IsCellPassable(mapCell2X, mapCell2Y))
		{
			velY = 0;
		}
	}
}

void NPC::CalcBounds()
{
	bounds.x = x;
	bounds.y = y;
}

void NPC::SetType(int i)
{
	switch(i)
	{
	case 1:
		type = Player1;
		break;
	case 2:
		type = Player2;
		break;
	default:
		type = Normal;
		break;
	}
}