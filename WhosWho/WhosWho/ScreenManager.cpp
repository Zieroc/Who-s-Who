#include "ScreenManager.h"
#include "GameplayScreen.h"
#include <iostream>


ScreenManager::ScreenManager(SDL_Renderer* renderer, ContentManager* conManRef/*Camera* camera*/)
{
	m_p_Renderer = renderer;
	m_LastState = Quit;
	m_CurrentState = Gameplay;
	m_p_Screen = NULL;
	m_p_InputHandler = new InputHandler();
	m_p_ContentManager = conManRef;
	//m_p_Camera = camera;
}

ScreenManager::~ScreenManager()
{
	delete(m_p_Screen);
	delete(m_p_InputHandler);
}

void ScreenManager::Initialize()
{
	m_p_Screen->Initialize(this);
}

void ScreenManager::LoadContent()
{
	m_p_Screen->LoadContent(m_p_Renderer, m_p_ContentManager);
}

void ScreenManager::UnloadContent()
{
	m_p_Screen->UnloadContent();
}

void ScreenManager::Update(Uint32 timeElapsed)
{
	if(m_CurrentState != m_LastState)
	{
		//States have changed so switch screens
		SwitchScreens();
	}

	m_LastState = m_CurrentState; //Not on a new state so store current state in last state

	m_p_InputHandler->Update(); //Update the input

	m_p_Screen->Update(timeElapsed); //Update the current screen

	m_p_Screen->HandleInput(m_p_InputHandler); //Handle input for the current screen
}

void ScreenManager::HandleEvents(SDL_Event sdlEvent)
{
	m_p_Screen->HandleEvents(sdlEvent);
}

void ScreenManager::Draw()
{
	m_p_Screen->Draw(m_p_Renderer);
}

void ScreenManager::SwitchState(GameState newState)
{
	m_CurrentState = newState;
}

void ScreenManager::SwitchScreens()
{
	//First unload content and delete old screen
	if(m_p_Screen != NULL)
	{
		UnloadContent(); //Unload content for current screen
		delete(m_p_Screen);
	}

	switch(m_CurrentState)
	{
	case Gameplay:
		DEBUG_MSG("GAMEPLAY SCREEN:");
		m_p_Screen = new GameplayScreen();
		break;
	default:
		DEBUG_MSG("Reached default case for screen switch");
		break;
	}

	Initialize(); //Initialize the screen
	LoadContent(); //Load content for new screen
}

//Camera* ScreenManager::GetCamera()
//{
//	return m_p_Camera;
//}