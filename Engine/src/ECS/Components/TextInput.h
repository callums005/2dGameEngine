#pragma once

#include "../../Core/PCH.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "../../DataTypes/Vec2/Vec2f.h"

#include "Text.h"

namespace Engine
{
	namespace Components
	{
		class TextInput
		{
		public:
			TextInput()
			{}

			

			void System()
			{
				
			}

			Text* m_TextObject;
		};
	}
}