#pragma once

#include "../Core/PCH.h"

#include "Event.h"

namespace Engine
{
	class EventDispatcher
	{
	public:
		static size_t GenerateEvent(const char* _name, EventType _type);

		#define EventFunc(function) [this](Engine::Event& ev) {this->function(ev);}
		static bool DispatchEvent(EventType _dispatchEventType, bool _markAsHandled = false);
		static Event& GetEventFromID(size_t _eventID);
		static Event& GetEventFromName(STRING _eventName);
		static size_t GetEventID(STRING _eventName);
	private:
		static std::map<size_t, Event*> m_Events;
		static size_t m_EventCount;
	};
}