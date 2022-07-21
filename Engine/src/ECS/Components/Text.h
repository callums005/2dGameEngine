#pragma once

#include "../../Core/PCH.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "../../DataTypes/Vec2/Vec2f.h"

namespace Engine
{
	namespace Components
	{
		class Text
		{
		public:
			Text() {}
			Text(const STRING text, const int fontSize, sf::Font* font)
				: m_Text(text), m_FontSize(fontSize), m_Font(font) {}

			void System(Types::Vec2f pos, Types::Vec2f scale, float rotation)
			{
				if (m_Object.getPosition() != pos.toSF())
					m_Object.setPosition(pos.toSF());
				if (m_Object.getScale() != scale.toSF())
					m_Object.setScale(scale.toSF());
				if (m_Object.getRotation() != rotation)
					m_Object.setRotation(rotation);
				
				if (m_Object.getString() != m_Text)
					m_Object.setString(m_Text);
				if (m_Object.getFont() != m_Font)
					m_Object.setFont(*m_Font);
				if (m_Object.getCharacterSize() != m_FontSize)
					m_Object.setCharacterSize(m_FontSize);

				if (!m_Bold && !m_Underlined && !m_Italic)
					m_Object.setStyle(sf::Text::Regular);

				if (m_Bold && !m_Underlined && !m_Italic)
					m_Object.setStyle(sf::Text::Bold);
				if (m_Bold && m_Underlined && !m_Italic)
					m_Object.setStyle(sf::Text::Bold | sf::Text::Underlined);
				if (m_Bold && !m_Underlined && m_Italic)
					m_Object.setStyle(sf::Text::Bold | sf::Text::Italic);
				if (!m_Bold && m_Underlined && !m_Italic)
					m_Object.setStyle(sf::Text::Underlined);
				if (!m_Bold && m_Underlined && m_Italic)
					m_Object.setStyle(sf::Text::Underlined | sf::Text::Italic);
				if (!m_Bold && !m_Underlined && m_Italic)
					m_Object.setStyle(sf::Text::Italic);
				if (m_Bold && m_Underlined && m_Italic)
					m_Object.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);
			}

			STRING m_Text;
			int m_FontSize;
			sf::Text m_Object;
			sf::Font* m_Font;
			boolean m_Bold;
			boolean m_Underlined;
			boolean m_Italic;
		};
 	}
}