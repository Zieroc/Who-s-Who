#include "Animation.h"
#include "Debug.h"
#include <iostream>

Animation::Animation(int startFrame, int endFrame, bool looping)
{
	m_StartFrame = startFrame;
	m_EndFrame = endFrame;
	m_CurrentState = 0;
	m_looping = looping;
}

Animation::~Animation()
{
}

void Animation::NextState()
{
	if(m_CurrentState + m_StartFrame < m_EndFrame)
	{
		m_CurrentState++;
	}
	else
	{
		if(m_looping)
		{
			m_CurrentState = 0;
		}
	}
}

int Animation::GetFrame()
{
	return m_CurrentState + m_StartFrame;
}