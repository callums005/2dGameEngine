#pragma once

#include "../Core/PCH.h"

#include "../EventSystem/EventDispatcher.h"

namespace Engine
{
	enum class InputState
	{
		Pressed, // When the key is pressed
		Released, // When the key is released that frame
		Up, // When the key is not pressed
	};

	class Input
	{
	public:
		// Engine Functions
		static void Init();
		static void HandleEvent(Event& e);
		static void UpdateReleasedStates();

		// Client Functions
		static bool IsKeyDown(Keys _keyCode);
		static bool IsKeyReleasedThisFrame(Keys _keyCode);
		static bool IsKeyUp(Keys _keyCode);
		static bool IsMouseButtonDown(MouseButton _button);
		static bool IsMouseButtonReleasedThisFrame(MouseButton _button);
		static bool IsMouseButtonUp(MouseButton _button);
	private:
		static InputState inline keyStates[34];
		static InputState inline mouseButtonStates[6];
		static bool inline isInit = false;
	};
}
