#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "../../DataTypes/Vec2/Vec2f.h"
#include "../../DataTypes/RGBA.h"

#include "SFML/Graphics.hpp"

namespace Engine
{
	namespace Components
	{
		class RectMesh
		{
		public:
			RectMesh() {}

			RectMesh(int outlineThickness, Types::RGBA outlineColour) 
				: m_OutlineThickness(m_OutlineThickness), m_OutlineColour(outlineColour) 
			{
				m_Shape = sf::RectangleShape();
			}

			void System(Types::Vec2f pos, Types::Vec2f size, float rotation)
			{
				if (m_Shape.getPosition() != pos.toSF())
					m_Shape.setPosition(pos.toSF());
				if (m_Shape.getSize() != size.toSF())
					m_Shape.setSize(size.toSF());
				if (m_Shape.getRotation() != rotation)
					m_Shape.setRotation(rotation);
			}

			
			int m_OutlineThickness = 0;
			Types::RGBA m_OutlineColour = {0, 0, 0, 100 };

			sf::RectangleShape m_Shape;
		};
	}
}