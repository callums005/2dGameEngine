#pragma once

#include "../../Core/PCH.h"

#include "../../EventSystem/EventDispatcher.h"
#include "../../ECS/EntityManager.h"
#include "SFML/Graphics.hpp"


namespace Engine
{
	struct WindowProps
	{
		int width;
		int height;
		const char* title;
	};

	class Window
	{
	public:
		Window()
			: m_Window(nullptr) {}

		boolean InitWindow(WindowProps _props);
		void CloseWindow();

		void Render();
		void PollEvents();

		sf::RenderWindow* GetSFWindow();
		boolean GetWindowOpenState();
	private:
		sf::RenderWindow* m_Window;
		std::map<int, EntityVector> m_RenderOrder;
	};
}