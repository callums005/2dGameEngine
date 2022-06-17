#pragma once

#include "../../Core/PCH.h"

namespace Engine
{
	class KeyEvent
	{
	public:
		Keys KeyCode = Keys::KEY_UNKNOWN;
		bool State = false;
	};
}