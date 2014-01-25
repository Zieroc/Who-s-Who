#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "Debug.h"
#include "InputHandler.h"
#include "CC_Texture.h"
#include "Sprite.h"
#include "Tilemap.h"

class GameObject
{
public:
	virtual void Update(Uint32, InputHandler*) = 0;
	void Draw(SDL_Renderer*);
	void Initialize(CC_Texture*);
	float x, y;
	float speed;
	float velX;
	float velY;
	bool alive;
	Sprite* image;
	bool flipped;
	enum Type { Player1, Player2, Normal };
	Type type;
	SDL_Rect bounds;
	TileMap* m_p_Map; //Reference to the current tile map
};
#endif