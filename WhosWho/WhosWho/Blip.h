#ifndef BLIP_H
#define BLIP_H

#include "GameObject.h"

class Blip : public GameObject
{
public:
	Blip(CC_Texture*, int playerX, int playerY);
	~Blip();
	void Update(Uint32, InputHandler*);
	void Draw(SDL_Renderer*);
	bool alive;
};
#endif