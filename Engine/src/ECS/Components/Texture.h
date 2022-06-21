#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "SFML/Graphics/Texture.hpp"

namespace Engine
{
	namespace Components
	{
		class Texture : public Component
		{
		public:
			Texture() {}

			Texture(STRING filePath)
			{
				SetTexture(filePath);
			}

			void System()
			{
			}

			void SetTexture(STRING filePath)
			{
				m_FilePath = filePath;

				if (!m_Texture.loadFromFile(filePath))
					std::cerr << "Error loading texture from disk.\n";

				m_Texture.setSmooth(true);
				m_Texture.setRepeated(true);
			}

			STRING m_FilePath;
			sf::Texture m_Texture;
		};
	}
}