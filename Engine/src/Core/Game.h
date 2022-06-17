#pragma once

#include "PCH.h"

#include "../Graphics/Window/Window.h"

namespace Engine
{
	class Game
	{
	public:
		Game();
		virtual ~Game();

		// Function called for the engine
		void Run();
		void SetWindow(Window* _window); 

		// Functions the client need to implement
		virtual void OnStart() = 0; // Is called at the start of the programs lifetime
		virtual void OnUpdate() = 0; // Is called each frame
		virtual void OnExit() = 0; // Is called at the end of the programs lifetime
	private:
		void CreateEvents();
		Window* m_Window;
	};

	Game* CreateGame(); // Implemented on the client
}