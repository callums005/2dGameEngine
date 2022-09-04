#pragma once

#include "../../Core/PCH.h"
#include "../../DataTypes/Vec2/Vec2i.h"
#include "../../DataTypes/Vec2/Vec2f.h"

#include "../../Input/Input.h"

namespace Engine
{
	namespace Components
	{
		/// <summary>
		/// When a mouse button is pressed, it checks if the mouse is within a defined box, if so
		/// it will toggle the state of the stored value.
		/// </summary>
		class Checkbox
		{
		public:
			Checkbox()
			{}

			Checkbox(MouseButton button, Types::Vec2f pos, Types::Vec2f size)
				: m_Button(button), m_Position(pos), m_Size(size)
			{
				EventDispatcher::GetEventFromName("MouseDown") += EventFunc(MouseEventFunc);
			}

			void System()
			{
				if (!trigger)
					return;


				int mouseX = Input::GetMousePos().first;
				int mouseY = Input::GetMousePos().second;


				if (mouseX >= m_Position.x && mouseX <= m_Position.x + m_Size.x
					&& mouseY >= m_Position.y && mouseY <= m_Position.y + m_Size.y
					)
				{
					m_Value = !m_Value;
				}
				trigger = false;
			}

			boolean m_Value = false;
			MouseButton m_Button;
			Types::Vec2f m_Position;
			Types::Vec2f m_Size;
		private:
			boolean trigger = false;

			void MouseEventFunc(Event& e)
			{
				if (e.MouseButtonEvent->Button == m_Button)
					trigger = true;
			}
		};
	}
}