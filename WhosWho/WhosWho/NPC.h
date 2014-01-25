#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPC : public GameObject
{
public:
	NPC(CC_Texture*);
	~NPC();
	void Update(Uint32);
	void Draw(SDL_Renderer*);
};
#endif