#pragma once

#include "../Core/PCH.h"

#include "Events/WindowEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyboardEvents.h"

namespace Engine
{
	class Event
	{
	public:
		Event(size_t _id, STRING _name, EventType _type)
			: ID(_id), Name(_name), Type(_type) {}

		size_t ID;
		STRING Name;
		EventType Type;

		// Data classes for engine defined events
		WindowResizeEvent* WindowResizeEvent;
		WindowMoveEvent* WindowMoveEvent;
		MouseButtonEvent* MouseButtonEvent;
		MouseMoveEvent* MouseMoveEvent;
		MouseScrollEvent* MouseScrollEvent;
		KeyEvent* KeyEvent;

		// Stores a list of functions to call when a event is dispatched
		std::vector<std::function<void(Event&)>> SubscribedCallbacks;
		boolean IsHandled;

		/// <summary>
		/// Allows the client to subscribe to events
		/// </summary>
		/// <param name="_rhs">const std::function<void(Event&)></param>
		void operator += (const std::function<void(Event&)> _rhs)
		{
			SubscribedCallbacks.push_back(_rhs);
		}
	};
}