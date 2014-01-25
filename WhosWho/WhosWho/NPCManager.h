#ifndef NPCMANAGER_H
#define NPCMANAGER_H

#include "NPC.h"
#include "ContentManager.h"
#include "SoundManager.h"
#include "Tilemap.h"
#include "BlipManager.h"
#include <vector>

using std::vector;

class NPCManager
{
public:
	NPCManager(ContentManager* conManRef, TileMap* tileMapRef, SoundManager* soundManRef);
	~NPCManager();
	void Update(Uint32 timeElapsed, InputHandler*);
	void Draw(SDL_Renderer*);
	void Add();
	void Swap(int);
	vector<NPC*> NPCs;
	SDL_Renderer* renderer;
	ContentManager* conMan;
	BlipManager* blipManager;
	TileMap* map;
	int max;
	int p1, p2;
	SoundManager* soundMan;
};
#endif