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
		class CircleMesh
		{
		public:
			CircleMesh() {}

			CircleMesh(int outlineThickness, Types::RGBA outlineColour)
				: m_OutlineThickness(m_OutlineThickness), m_OutlineColour(outlineColour)
			{
				m_Shape = sf::CircleShape();
			}

			void System(Types::Vec2f pos, float radius, float rotation)
			{
				if (m_Shape.getPosition() != pos.toSF())
					m_Shape.setPosition(pos.toSF());
				if (m_Shape.getRadius() != radius)
					m_Shape.setRadius(radius);
				if (m_Shape.getRotation() != rotation)
					m_Shape.setRotation(rotation);
			}


			int m_OutlineThickness = 0;
			Types::RGBA m_OutlineColour = { 0, 0, 0, 100 };

			sf::CircleShape m_Shape;
		};
	}
}