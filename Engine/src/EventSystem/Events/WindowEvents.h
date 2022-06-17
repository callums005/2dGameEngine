#pragma once

#include "../../Core/PCH.h"

namespace Engine
{
	class WindowMoveEvent
	{
	public:
		int XPos = 0;
		int YPos = 0;
	};

	class WindowResizeEvent
	{
	public:
		int Width = 0;
		int Height = 0;
	};
}