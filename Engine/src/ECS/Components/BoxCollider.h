#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "../../DataTypes/Vec2/Vec2f.h"

namespace Engine
{
	namespace Components
	{
		class BoxCollider : public Component
		{
		public:
			BoxCollider() {}

			BoxCollider(Types::Vec2f size) 
				: m_Size(size) {}

			void System(const Types::Vec2f* pos, const Types::Vec2f* size)
			{
				if (m_Position.x != pos->x || m_Position.y != pos->y)
					m_Position = *pos;

				if (m_Size.x != size->x || m_Size.y != size->y)
					m_Size = *size;
			}
			
			Types::Vec2f m_Position = { 0.0f, 0.0f };
			Types::Vec2f m_Size = { 0.0f, 0.0f };
			
		};
	}
}