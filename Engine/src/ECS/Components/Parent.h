#pragma once

#include "../../Core/PCH.h"

#include "../ComponentBase.h"

namespace Engine
{
	namespace Components
	{
		class Parent
		{
		public:
			Parent()
			{}

			Parent(Transform* parentTransform, Transform offsetTransform)
				: m_ParentTransform(parentTransform), m_OffsetTransform(offsetTransform) {}

			void System(Components::Transform* childTransform)
			{
				if (!m_ParentTransform)
					return;

				childTransform->m_Position.x = (m_ParentTransform->m_Position.x + m_OffsetTransform.m_Position.x);
				childTransform->m_Position.y = (m_ParentTransform->m_Position.y + m_OffsetTransform.m_Position.y);
			}

			Transform m_OffsetTransform;
			Transform* m_ParentTransform;
		};
	}
}