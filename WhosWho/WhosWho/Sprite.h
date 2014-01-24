#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
//#include "Animation.h"
#include "CC_Texture.h"
#include "Debug.h"
//#include "Camera.h"

class Sprite
{
public:
	Sprite(CC_Texture* texture, int width, int height);
	~Sprite();
	void Update(Uint32 timeElapsed);
	void Draw(SDL_Renderer* renderer,  int x, int y, bool flipped /*Camera* camera*/);
private:
	CC_Texture* m_p_Texture;
	SDL_Rect m_SourceRect; //Used to crop the image for animation frames
	SDL_Rect m_DestinationRect; //Used to draw the image to the screen
	int m_Columns;
	int m_Rows;
	Uint32 m_Timer;
	Uint32 m_Interval;
	//std::vector<Animation*> m_p_Animations;
	bool m_Animate;
	//Animation* m_CurrentAnimation;
};

#endif

