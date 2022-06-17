#include "Game.h"

#include "../EventSystem/EventDispatcher.h"

namespace Engine
{
	Game::Game()
	{
		// Makes sure that the events are created as soon as a class is created
		CreateEvents();
	}

	Game::~Game()
	{
	}

	/// <summary>
	/// Contains main game loop, polling events, renderering & calling client update function
	/// </summary>
	void Game::Run()
	{
		EventDispatcher::DispatchEvent(EventType::OnApplicationStart, true);

		// Main Game Loop
		while (m_Window->GetWindowOpenState())
		{
			m_Window->PollEvents();
			m_Window->Render();
			OnUpdate();

		}

		EventDispatcher::DispatchEvent(EventType::OnApplicationExit, true);
	}

	/// <summary>
	/// Allows the entry point to set the game class's window
	/// </summary>
	/// <param name="_window">Engine::Window*</param>
	void Game::SetWindow(Window* _window)
	{
		m_Window = _window;
	}

	/// <summary>
	/// Create all engine events
	/// </summary>
	void Game::CreateEvents()
	{
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("OnApplicationStart", EventType::OnApplicationStart));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("OnApplicationExit", EventType::OnApplicationExit));

		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("OnWindowClose", EventType::OnWindowClose));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("OnWindowResize", EventType::OnWindowResize));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("OnWindowMove", EventType::OnWindowMove));

		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("MouseDown", EventType::MouseDown));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("MouseUp", EventType::MouseUp));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("MouseMove", EventType::MouseMove));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("MouseScroll", EventType::MouseScroll));

		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("KeyDown", EventType::KeyDown));
		EventDispatcher::GetEventFromID(EventDispatcher::GenerateEvent("KeyUp", EventType::KeyUp));
	}
}