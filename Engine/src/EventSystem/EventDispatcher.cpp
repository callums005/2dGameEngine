#include "EventDispatcher.h"

namespace Engine
{
	std::map<size_t, Event*> EventDispatcher::m_Events;
	size_t EventDispatcher::m_EventCount;

	/// <summary>
	/// Create an event, applies the data class to the event and add to the array
	/// </summary>
	/// <param name="_name">const char*</param>
	/// <param name="_type">EventType</param>
	/// <returns>size_t</returns>
	size_t EventDispatcher::GenerateEvent(const char* _name, EventType _type)
	{
		Event* e = new Event(m_EventCount, std::string(_name), _type);

		switch (_type)
		{
		case EventType::OnWindowResize:
			e->WindowResizeEvent = new WindowResizeEvent();
			break;
		case EventType::OnWindowMove:
			e->WindowMoveEvent = new WindowMoveEvent();
			break;
		case EventType::MouseDown:
			e->MouseButtonEvent = new MouseButtonEvent();
			break;
		case EventType::MouseUp:
			e->MouseButtonEvent = new MouseButtonEvent();
			break;
		case EventType::MouseMove:
			e->MouseMoveEvent = new MouseMoveEvent();
			break;
		case EventType::MouseScroll:
			e->MouseScrollEvent = new MouseScrollEvent();
			break;
		case EventType::KeyDown:
			e->KeyEvent = new KeyEvent();
			break;
		case EventType::KeyUp:
			e->KeyEvent = new KeyEvent();
			break;
		}

		e->IsHandled = false;
		m_Events[e->ID] = e;
		m_EventCount++;
		return e->ID;

		return -1;
	}

	/// <summary>
	/// Loops through list of events,
	/// If the event type matches the dispatched event type it will call all functions that are subscribed to the event
	/// then marked as handled
	/// </summary>
	/// <param name="_dispatchEventType">EventType</param>
	/// <param name="_markAsHandled">boolean</param>
	/// <returns>boolean</returns>
	boolean EventDispatcher::DispatchEvent(EventType _dispatchEventType, boolean _markAsHandled)
	{
		for (auto e : m_Events)
		{
			Event* ev = e.second;

			if (ev->IsHandled)
				continue;

			if (ev->Type != _dispatchEventType)
				continue;

			for (auto callback : ev->SubscribedCallbacks)
			{
				callback(*ev);
			}

			if (_markAsHandled)
				ev->IsHandled = true;

			return true;
		}

		return false;
	}

	/// <summary>
	/// Returns event with the id
	/// </summary>
	/// <param name="_eventID">size_t</param>
	/// <returns>Event&</returns>
	Event& EventDispatcher::GetEventFromID(size_t _eventID)
	{
		return *m_Events[_eventID];
	}

	/// <summary>
	/// Returns event with the name
	/// </summary>
	/// <param name="_eventName">std::string</param>
	/// <returns>Event&</returns>
	Event& EventDispatcher::GetEventFromName(STRING _eventName)
	{
		return *m_Events[GetEventID(_eventName)];
	}

	/// <summary>
	/// Return the event ID with the event name
	/// </summary>
	/// <param name="_eventName">std::string</param>
	/// <returns>size_t</returns>
	size_t EventDispatcher::GetEventID(STRING _eventName)
	{
		for (auto e : m_Events)
		{
			Event* ev = e.second;

			if (ev->Name == _eventName)
				return ev->ID;
		}

		return NULL;
	}
}