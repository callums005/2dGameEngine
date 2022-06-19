#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "../../DataTypes/Vec2/Vec2f.h"

namespace Engine
{
	namespace Components
	{
		class Transform : public Component
		{
		public:
			Transform() {}

			Transform(Types::Vec2f pos, Types::Vec2f size, Types::Vec2f vel, float rotation)
				: m_Position(pos), m_Size(size), m_Velocity(vel), m_Rotation(rotation) {}

			void System()
			{
				m_LastPosition = m_Position;
				m_Position += m_Velocity;
			}

			Types::Vec2f m_Position = { 0.0f, 0.0f };
			Types::Vec2f m_LastPosition = { 0.0f, 0.0f };
			Types::Vec2f m_Size = { 0.0f, 0.0f };
			Types::Vec2f m_Velocity = { 0.0f, 0.0f };
			float m_Rotation = 0.0f; // Negative Numbers will rotate left, positive will rotate right
		};
	}
}