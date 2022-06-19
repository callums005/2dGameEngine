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
		static boolean IsKeyDown(Keys _keyCode);
		static boolean IsKeyReleasedThisFrame(Keys _keyCode);
		static boolean IsKeyUp(Keys _keyCode);
		static boolean IsMouseButtonDown(MouseButton _button);
		static boolean IsMouseButtonReleasedThisFrame(MouseButton _button);
		static boolean IsMouseButtonUp(MouseButton _button);
		static std::pair<int, int> GetMousePos();
	private:
		static InputState inline keyStates[34];
		static InputState inline mouseButtonStates[6];
		static int inline mouseX = 0;
		static int inline mouseY = 0;
		static boolean inline isInit = false;
	};
}
