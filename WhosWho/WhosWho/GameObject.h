#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "Debug.h"
//#include "InputHandler.h"
#include "CC_Texture.h"
#include "Sprite.h"

class GameObject
{
public:
	virtual void Update(Uint32) = 0;
	void Draw(SDL_Renderer*);
	int x, y;
	float speed;
	bool alive;
	Sprite* image;
	bool flipped;
	enum Type { Player1, Player2, Normal };
	Type type;
};
#endif