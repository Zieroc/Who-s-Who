#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "InputHandler.h"

class NPC : public GameObject
{
public:
	NPC(CC_Texture*, TileMap*);
	~NPC();
	void Update(Uint32, InputHandler*);
	void Draw(SDL_Renderer*);
	void HorizontalTileCollisionTest();
	void VerticalTileCollisionTest();
	void CalcBounds();
	void SetType(int);
	int direction;
	float timer;
};
#endif