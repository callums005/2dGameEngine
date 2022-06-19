#include "Input.h"

namespace Engine
{
	void Input::Init()
	{
		if (isInit)
			return;

		Engine::EventDispatcher::GetEventFromName("KeyDown") += [](Engine::Event& ev) {HandleEvent(ev); };
		Engine::EventDispatcher::GetEventFromName("KeyUp") += [](Engine::Event& ev) {HandleEvent(ev); };
		Engine::EventDispatcher::GetEventFromName("MouseDown") += [](Engine::Event& ev) {HandleEvent(ev); };
		Engine::EventDispatcher::GetEventFromName("MouseUp") += [](Engine::Event& ev) {HandleEvent(ev); };
		Engine::EventDispatcher::GetEventFromName("MouseMove") += [](Engine::Event& ev) {HandleEvent(ev); };

		for (int i = 0; i < 34; i++)
		{
			keyStates[i] = InputState::Up;
		}
		for (int i = 0; i < 6; i++)
		{
			mouseButtonStates[i] = InputState::Up;
		}
	}

	void Input::HandleEvent(Event& e)
	{
		if (e.Name == "KeyDown")
			keyStates[(int)e.KeyEvent->KeyCode] = InputState::Pressed;
		else if (e.Name == "KeyUp")
			keyStates[(int)e.KeyEvent->KeyCode] = InputState::Released;
		else if (e.Name == "MouseDown")
			mouseButtonStates[(int)e.MouseButtonEvent->Button] = InputState::Pressed;
		else if (e.Name == "MouseUp")
			mouseButtonStates[(int)e.MouseButtonEvent->Button] = InputState::Released;
		else if (e.Name == "MouseMove")
		{
			mouseX = e.MouseMoveEvent->MouseX;
			mouseY = e.MouseMoveEvent->MouseY;
		}
	}

	void Input::UpdateReleasedStates()
	{
		for (int i = 0; i < 34; i++)
		{
			if (keyStates[i] == InputState::Released)
				keyStates[i] = InputState::Up;
		}
		for (int i = 0; i < 6; i++)
		{
			if (mouseButtonStates[i] == InputState::Released)
				mouseButtonStates[i] = InputState::Up;
		}
	}

	// Keys

	boolean Input::IsKeyDown(Keys _keyCode)
	{
		if (keyStates[(int)_keyCode] == InputState::Pressed)
			return true;

		return false;
	}

	boolean Input::IsKeyReleasedThisFrame(Keys _keyCode)
	{
		if (keyStates[(int)_keyCode] == InputState::Released)
			return true;

		return false;
	}

	boolean Input::IsKeyUp(Keys _keyCode)
	{
		if (keyStates[(int)_keyCode] == InputState::Up)
			return true;

		return false;
	}

	// Mouse

	boolean Input::IsMouseButtonDown(MouseButton _button)
	{
		if (mouseButtonStates[(int)_button] == InputState::Pressed)
			return true;

		return false;
	}

	boolean Input::IsMouseButtonReleasedThisFrame(MouseButton _button)
	{
		if (mouseButtonStates[(int)_button] == InputState::Released)
			return true;

		return false;
	}

	boolean Input::IsMouseButtonUp(MouseButton _button)
	{
		if (mouseButtonStates[(int)_button] == InputState::Up)
			return true;

		return false;
	}

	std::pair<int, int> Input::GetMousePos()
	{
		return std::pair<int, int>(mouseX, mouseY);
	}

}