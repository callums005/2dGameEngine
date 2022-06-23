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
		class ConvexMesh
		{
		public:
			ConvexMesh() {}

			ConvexMesh(int outlineThickness, Types::RGBA outlineColour, std::vector<Types::Vec2f> points)
				: m_OutlineThickness(m_OutlineThickness), m_OutlineColour(outlineColour)
			{
				m_Shape = sf::ConvexShape();
				UpdatePoints(points);
			}

			void System(Types::Vec2f pos, Types::Vec2f scale, float rotation)
			{
				if (m_Shape.getPosition() != pos.toSF())
					m_Shape.setPosition(pos.toSF());
				if (m_Shape.getScale() != scale.toSF())
					m_Shape.setScale(scale.toSF());
				if (m_Shape.getRotation() != rotation)
					m_Shape.setRotation(rotation);
			}

			void UpdatePoints(std::vector<Types::Vec2f> points)
			{
				m_Points = points;
				
				m_Shape.setPointCount(m_Points.size());

				for (int i = 0; i < m_Points.size(); i++)
				{
					m_Shape.setPoint(i, m_Points[i].toSF());
				}

			}

			int m_OutlineThickness = 0;
			Types::RGBA m_OutlineColour = { 0, 0, 0, 100 };
			std::vector<Types::Vec2f> m_Points;

			sf::ConvexShape m_Shape;
		};
	}
}