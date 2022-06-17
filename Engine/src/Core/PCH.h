#pragma once

#include <iostream>
#include <stdio.h>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <Windows.h>
#include <mutex>

#define STRING std::string

namespace Engine
{
	enum class EventType
	{
		OnApplicationStart, OnApplicationExit, // Application Events
		OnWindowClose, OnWindowResize, OnWindowMove, // Window Events
		MouseDown, MouseUp, MouseMove, MouseScroll, // Mouse Events
		KeyDown, KeyUp, // Keyboard Events
		UserDefined // Other
	};

	enum class Keys {
		KEY_UNKNOWN = -1, 
		KEY_A = 0, 
		KEY_B, 
		KEY_C,
		KEY_D, 
		KEY_E, 
		KEY_F, 
		KEY_G,
		KEY_H, 
		KEY_I, 
		KEY_J, 
		KEY_K,
		KEY_L, 
		KEY_M, 
		KEY_N, 
		KEY_O,
		KEY_P, 
		KEY_Q, 
		KEY_R, 
		KEY_S,
		KEY_T, 
		KEY_U, 
		KEY_V, 
		KEY_W,
		KEY_X, 
		KEY_Y, 
		KEY_Z, 
		KEY_NUM0,
		KEY_NUM1, 
		KEY_NUM2, 
		KEY_NUM3, 
		KEY_NUM4,
		KEY_NUM5, 
		KEY_NUM6, 
		KEY_NUM7, 
		KEY_NUM8,
		KEY_NUM9, 
		KEY_ESCAPE, 
		KEY_LCONTROL, 
		KEY_LSHIFT,
		KEY_LALT, 
		KEY_LSYSTEM, // Left "Super" key
		KEY_RCONTROL, 
		KEY_RSHIFT,
		KEY_RALT, 
		KEY_RSYSTEM, // Right "Super" key
		KEY_MENU, 
		KEY_LBRACKET,
		KEY_RBRACKET, 
		KEY_SEMICOLON, 
		KEY_COMMA, 
		KEY_PERIOD,
		KEY_QUOTE, 
		KEY_SLASH, 
		KEY_BACKSLASH, 
		KEY_TILDE,
		KEY_EQUAL, 
		KEY_HYPHEN, 
		KEY_SPACE, 
		KEY_ENTER,
		KEY_BACKSPACE, 
		KEY_TAB, 
		KEY_PAGEUP, 
		KEY_PAGEDOWN,
		KEY_END, 
		KEY_HOME, 
		KEY_INSERT, 
		KEY_DELETE,
		KEY_ADD, 
		KEY_SUBTRACT, 
		KEY_MULTIPLY, 
		KEY_DIVIDE,
		KEY_LEFT, 
		KEY_RIGHT, 
		KEY_UP, 
		KEY_DOWN,
		KEY_NUMPAD0, 
		KEY_NUMPAD1, 
		KEY_NUMPAD2, 
		KEY_NUMPAD3,
		KEY_NUMPAD4, 
		KEY_NUMPAD5, 
		KEY_NUMPAD6, 
		KEY_NUMPAD7,
		KEY_NUMPAD8, 
		KEY_NUMPAD9, 
		KEY_F1, 
		KEY_F2,
		KEY_F3, 
		KEY_F4, 
		KEY_F5, 
		KEY_F6,
		KEY_F7, 
		KEY_F8, 
		KEY_F9, 
		KEY_F10,
		KEY_F11, 
		KEY_F12, 
		KEY_F13, 
		KEY_F14,
		KEY_F15, 
		KEY_PAUSE, 
		KEY_KEYCOUNT,
	};

	enum class MouseButton
	{
		MOUSE_BUTTON_UNKNOWN = -1,
		MOUSE_BUTTON_LEFT = 0, 
		MOUSE_BUTTON_RIGHT, 
		MOUSE_BUTTON_MIDDLE, 
		MOUSE_BUTTON_XBUTTON1, // Extra Mouse Button, usually button3
		MOUSE_BUTTON_XBUTTON2, // Extra Mouse Button, usually button4
		MOUSE_BUTTON_BUTTONCOUNT
	};
}