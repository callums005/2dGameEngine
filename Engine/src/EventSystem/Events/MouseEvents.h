#pragma once

#include "../../Core/PCH.h"

namespace Engine
{
	class MouseMoveEvent
	{
	public:
		int MouseX = 0;
		int MouseY = 0;
	};

	class MouseButtonEvent
	{
	public:
		MouseButton Button = MouseButton::MOUSE_BUTTON_UNKNOWN;
		bool State = false;
	};

	class MouseScrollEvent
	{
	public:
		double XPos = 0;
		double YPos = 0;
	};
}