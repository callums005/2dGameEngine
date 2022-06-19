#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "../../DataTypes/RGBA.h"

namespace Engine
{
	namespace Components
	{
		class Colour : public Component
		{
		public:
			Colour() {}

			Colour(Types::RGBA colour)
				: m_Colour(colour) {}

			void System()
			{
			}

			Types::RGBA m_Colour = {0, 0, 0, 100};
		};
	}
}