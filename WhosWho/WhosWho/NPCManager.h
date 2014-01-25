#ifndef NPCMANAGER_H
#define NPCMANAGER_H

#include "NPC.h"
#include "ContentManager.h"
#include <vector>

using std::vector;

class NPCManager
{
public:
	NPCManager(ContentManager* conManRef);
	~NPCManager();
	void Update(Uint32 timeElapsed);
	void Draw(SDL_Renderer*);
	void Initialise();
	void Add();
	vector<NPC*> NPCs;
	SDL_Renderer* renderer;
	ContentManager* conMan;
};
#endif