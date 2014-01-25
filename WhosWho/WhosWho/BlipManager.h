#ifndef BLIPMANAGER_H
#define BLIPMANAGER_H

#include "GameObject.h"
#include "InputHandler.h"
#include "ContentManager.h"
#include "Blip.h"
#include <vector>

using std::vector;

class BlipManager
{
public:
	BlipManager(ContentManager* conManRef);
	~BlipManager();
	void Update(Uint32, InputHandler*);
	void Draw(SDL_Renderer*);
	void Add(int x, int y, int);
	vector<Blip*> Blips;
	float timer;
	ContentManager* con;
	int hit;
};
#endif