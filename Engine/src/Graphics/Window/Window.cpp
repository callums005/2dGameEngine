#include "Window.h"


namespace Engine
{
	/// <summary>
	/// Creates a window and returns success state
	/// </summary>
	/// <param name="_props">Engine::WindowProps</param>
	/// <returns>bool</returns>
	bool Window::InitWindow(WindowProps _props)
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(_props.width, _props.height), _props.title);

		if (!m_Window)
			return false;

		//glfwSetWindowPosCallback(m_Window, [](GLFWwindow* ctx, int xpos, int ypos) {
		//	EventDispatcher::GetEventFromName("OnWindowMove").WindowMoveEvent->XPos = xpos;
		//	EventDispatcher::GetEventFromName("OnWindowMove").WindowMoveEvent->YPos = ypos;
		//	EventDispatcher::DispatchEvent(EventType::OnWindowMove);
		//	});


		return true;
	}

	void Window::CloseWindow()
	{
		m_Window->close();
	}

	/// <summary>
	/// Handles window rendering
	/// </summary>
	void Window::Render()
	{
		m_Window->clear();
		// Render object here
		m_Window->display();
	}

	/// <summary>
	/// Polls events and dispatches events with window data
	/// </summary>
	void Window::PollEvents()
	{
		sf::Event e;

		while (m_Window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				EventDispatcher::DispatchEvent(EventType::OnWindowClose);
				CloseWindow();
				break;
			case sf::Event::Resized:
				EventDispatcher::GetEventFromName("OnWindowResize").WindowResizeEvent->Width = e.size.width;
				EventDispatcher::GetEventFromName("OnWindowResize").WindowResizeEvent->Height = e.size.height;
				EventDispatcher::DispatchEvent(EventType::OnWindowResize);
				break;
			case sf::Event::MouseMoved:
				EventDispatcher::GetEventFromName("MouseMove").MouseMoveEvent->MouseX = e.mouseMove.x;
				EventDispatcher::GetEventFromName("MouseMove").MouseMoveEvent->MouseY = e.mouseMove.y;
				EventDispatcher::DispatchEvent(EventType::MouseMove);
				break;
			case sf::Event::MouseButtonPressed:
				EventDispatcher::GetEventFromName("MouseDown").MouseButtonEvent->State = true;
				EventDispatcher::GetEventFromName("MouseDown").MouseButtonEvent->Button = (MouseButton)e.mouseButton.button;
				EventDispatcher::DispatchEvent(EventType::MouseDown);
				break;
			case sf::Event::MouseButtonReleased:
				EventDispatcher::GetEventFromName("MouseUp").MouseButtonEvent->State = false;
				EventDispatcher::GetEventFromName("MouseUp").MouseButtonEvent->Button = (MouseButton)e.mouseButton.button;
				EventDispatcher::DispatchEvent(EventType::MouseUp);
				break;
			case sf::Event::MouseWheelScrolled:
				EventDispatcher::GetEventFromName("MouseScroll").MouseScrollEvent->XPos += e.mouseWheel.x;
				EventDispatcher::GetEventFromName("MouseScroll").MouseScrollEvent->YPos += e.mouseWheel.y;
				EventDispatcher::DispatchEvent(EventType::MouseScroll);
				break;
			case sf::Event::KeyPressed:
				EventDispatcher::GetEventFromName("KeyDown").KeyEvent->KeyCode = (Keys)e.key.code;
				EventDispatcher::GetEventFromName("KeyDown").KeyEvent->State = true;
				EventDispatcher::DispatchEvent(EventType::KeyDown);
				break;
			case sf::Event::KeyReleased:
				EventDispatcher::GetEventFromName("KeyUp").KeyEvent->KeyCode = (Keys)e.key.code;
				EventDispatcher::GetEventFromName("KeyUp").KeyEvent->State = true;
				EventDispatcher::DispatchEvent(EventType::KeyUp);
				break;
			}
		}
	}

	sf::RenderWindow* Window::GetSFWindow()
	{
		return m_Window;
	}

	bool Window::GetWindowOpenState()
	{
		return m_Window->isOpen();
	}
}