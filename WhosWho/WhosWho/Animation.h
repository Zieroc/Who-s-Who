#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <string>

class Animation
{
public:
	Animation(int startFrame, int endFrame, bool looping);
	~Animation();
	void NextState();
	int GetFrame();
private:
	int m_StartFrame;
	int m_CurrentState;
	int m_EndFrame;
	bool m_looping;
};

#endif