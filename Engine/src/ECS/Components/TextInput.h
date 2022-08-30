#pragma once

#include "../../Core/PCH.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "../../DataTypes/Vec2/Vec2f.h"

#include "../../Input/Input.h"
#include "Text.h"

namespace Engine
{
	namespace Components
	{
		class TextInput
		{
		public:
			TextInput()
			{}

			TextInput(STRING placeHolder, int fontSize, sf::Font* font, Types::Vec2f pos, Types::Vec2f size)
				: m_PlaceholderText(placeHolder), m_Position(pos), m_Size(size)
			{
				EventDispatcher::GetEventFromName("MouseDown") += EventFunc(MouseEventFunc);
				EventDispatcher::GetEventFromName("KeyDown") += EventFunc(KeyEventFunc);
				m_TextObject = new Text(m_PlaceholderText, fontSize, font);
			}

			void System()
			{
				if (m_Value == "")
					m_TextObject->m_Text = m_PlaceholderText;
				else
					m_TextObject->m_Text = m_Value;
			
				if (!trigger)
					return;

				int mouseX = Input::GetMousePos().first;
				int mouseY = Input::GetMousePos().second;


				if (mouseX >= m_Position.x && mouseX <= m_Position.x + m_Size.x
					&& mouseY >= m_Position.y && mouseY <= m_Position.y + m_Size.y
					)
				{
					recordText = true;
				}
				else
				{
					recordText = false;
				}
				trigger = false;
			}

			Text* m_TextObject;
			Types::Vec2f m_Position;
			Types::Vec2f m_Size;
			STRING m_Value;
			STRING m_PlaceholderText;
		private:
			boolean trigger = false;
			boolean recordText = false;

			void MouseEventFunc(Event& e)
			{
				if (e.MouseButtonEvent->Button == MouseButton::MOUSE_BUTTON_LEFT)
					trigger = true;
			}

			void KeyEventFunc(Event& e)
			{
				if (e.KeyEvent->KeyCode == Keys::KEY_BACKSPACE)
				{
					if (m_Value != "")
						m_Value.resize(m_Value.size() - 1);
					return;
				}
				else if (e.KeyEvent->KeyCode == Keys::KEY_ENTER)
				{
					recordText = false;
					return;
				}
				else if (e.KeyEvent->KeyCode < Keys::KEY_A || e.KeyEvent->KeyCode > Keys::KEY_NUM9)
					if (e.KeyEvent->KeyCode < Keys::KEY_LBRACKET || e.KeyEvent->KeyCode > Keys::KEY_SPACE)
						if (e.KeyEvent->KeyCode < Keys::KEY_ADD || e.KeyEvent->KeyCode > Keys::KEY_DIVIDE)
							return;

				if (e.KeyEvent->ShiftModifier)
				{
					switch (e.KeyEvent->KeyCode)
					{
					case Keys::KEY_A:
						m_Value += "A";
						return;
					case Keys::KEY_B:
						m_Value += "B";
						return;
					case Keys::KEY_C:
						m_Value += "C";
						return;
					case Keys::KEY_D:
						m_Value += "D";
						return;
					case Keys::KEY_E:
						m_Value += "E";
						return;
					case Keys::KEY_F:
						m_Value += "F";
						return;
					case Keys::KEY_G:
						m_Value += "G";
						return;
					case Keys::KEY_H:
						m_Value += "H";
						return;
					case Keys::KEY_I:
						m_Value += "I";
						return;
					case Keys::KEY_J:
						m_Value += "J";
						return;
					case Keys::KEY_K:
						m_Value += "K";
						return;
					case Keys::KEY_L:
						m_Value += "L";
						return;
					case Keys::KEY_M:
						m_Value += "M";
						return;
					case Keys::KEY_N:
						m_Value += "N";
						return;
					case Keys::KEY_O:
						m_Value += "O";
						return;
					case Keys::KEY_P:
						m_Value += "P";
						return;
					case Keys::KEY_Q:
						m_Value += "Q";
						return;
					case Keys::KEY_R:
						m_Value += "R";
						return;
					case Keys::KEY_S:
						m_Value += "S";
						return;
					case Keys::KEY_T:
						m_Value += "T";
						return;
					case Keys::KEY_U:
						m_Value += "U";
						return;
					case Keys::KEY_V:
						m_Value += "V";
						return;
					case Keys::KEY_W:
						m_Value += "W";
						return;
					case Keys::KEY_X:
						m_Value += "X";
						return;
					case Keys::KEY_Y:
						m_Value += "Y";
						return;
					case Keys::KEY_Z:
						m_Value += "Z";
						return;
					case Keys::KEY_NUM0:
						m_Value += ")";
						return;
					case Keys::KEY_NUM1:
						m_Value += "!";
						return;
					case Keys::KEY_NUM2:
						m_Value += "\"";
						return;
					case Keys::KEY_NUM3:
						m_Value += "£";
						return;
					case Keys::KEY_NUM4:
						m_Value += "$";
						return;
					case Keys::KEY_NUM5:
						m_Value += "%";
						return;
					case Keys::KEY_NUM6:
						m_Value += "^";
						return;
					case Keys::KEY_NUM7:
						m_Value += "&";
						return;
					case Keys::KEY_NUM8:
						m_Value += "*";
						return;
					case Keys::KEY_NUM9:
						m_Value += "(";
						return;
					case Keys::KEY_LBRACKET:
						m_Value += "{";
						return;
					case Keys::KEY_RBRACKET:
						m_Value += "}";
						return;
					case Keys::KEY_SEMICOLON:
						m_Value += ":";
						return;
					case Keys::KEY_COMMA:
						m_Value += "<";
						return;
					case Keys::KEY_PERIOD:
						m_Value += ">";
						return;
					case Keys::KEY_QUOTE:
						m_Value += "~";
						return;
					case Keys::KEY_SLASH:
						m_Value += "?";
						return;
					case Keys::KEY_BACKSLASH:
						m_Value += "|";
						return;
					case Keys::KEY_TILDE:
						m_Value += "@";
						return;
					case Keys::KEY_EQUAL:
						m_Value += "+";
						return;
					case Keys::KEY_HYPHEN:
						m_Value += "_";
						return;
					case Keys::KEY_SPACE:
						m_Value += " ";
						return;
					case Keys::KEY_ADD:
						m_Value += "+";
						return;
					case Keys::KEY_SUBTRACT:
						m_Value += "-";
						return;
					case Keys::KEY_MULTIPLY:
						m_Value += "*";
						return;
					case Keys::KEY_DIVIDE:
						m_Value += "/";
						return;
					}
				}
				else
				{
				switch (e.KeyEvent->KeyCode)
				{
				case Keys::KEY_A:
					m_Value += "a";
					return;
				case Keys::KEY_B:
					m_Value += "b";
					return;
				case Keys::KEY_C:
					m_Value += "c";
					return;
				case Keys::KEY_D:
					m_Value += "d";
					return;
				case Keys::KEY_E:
					m_Value += "e";
					return;
				case Keys::KEY_F:
					m_Value += "f";
					return;
				case Keys::KEY_G:
					m_Value += "g";
					return;
				case Keys::KEY_H:
					m_Value += "h";
					return;
				case Keys::KEY_I:
					m_Value += "i";
					return;
				case Keys::KEY_J:
					m_Value += "j";
					return;
				case Keys::KEY_K:
					m_Value += "k";
					return;
				case Keys::KEY_L:
					m_Value += "l";
					return;
				case Keys::KEY_M:
					m_Value += "m";
					return;
				case Keys::KEY_N:
					m_Value += "n";
					return;
				case Keys::KEY_O:
					m_Value += "o";
					return;
				case Keys::KEY_P:
					m_Value += "p";
					return;
				case Keys::KEY_Q:
					m_Value += "q";
					return;
				case Keys::KEY_R:
					m_Value += "r";
					return;
				case Keys::KEY_S:
					m_Value += "s";
					return;
				case Keys::KEY_T:
					m_Value += "t";
					return;
				case Keys::KEY_U:
					m_Value += "u";
					return;
				case Keys::KEY_V:
					m_Value += "v";
					return;
				case Keys::KEY_W:
					m_Value += "w";
					return;
				case Keys::KEY_X:
					m_Value += "x";
					return;
				case Keys::KEY_Y:
					m_Value += "y";
					return;
				case Keys::KEY_Z:
					m_Value += "z";
					return;
				case Keys::KEY_NUM0:
					m_Value += "0";
					return;
				case Keys::KEY_NUM1:
					m_Value += "1";
					return;
				case Keys::KEY_NUM2:
					m_Value += "2";
					return;
				case Keys::KEY_NUM3:
					m_Value += "3";
					return;
				case Keys::KEY_NUM4:
					m_Value += "4";
					return;
				case Keys::KEY_NUM5:
					m_Value += "5";
					return;
				case Keys::KEY_NUM6:
					m_Value += "6";
					return;
				case Keys::KEY_NUM7:
					m_Value += "7";
					return;
				case Keys::KEY_NUM8:
					m_Value += "8";
					return;
				case Keys::KEY_NUM9:
					m_Value += "9";
					return;
				case Keys::KEY_LBRACKET:
					m_Value += "[";
					return;
				case Keys::KEY_RBRACKET:
					m_Value += "]";
					return;
				case Keys::KEY_SEMICOLON:
					m_Value += ";";
					return;
				case Keys::KEY_COMMA:
					m_Value += ",";
					return;
				case Keys::KEY_PERIOD:
					m_Value += ".";
					return;
				case Keys::KEY_QUOTE:
					m_Value += "#";
					return;
				case Keys::KEY_SLASH:
					m_Value += "/";
					return;
				case Keys::KEY_BACKSLASH:
					m_Value += "\\";
					return;
				case Keys::KEY_TILDE:
					m_Value += "'";
					return;
				case Keys::KEY_EQUAL:
					m_Value += "=";
					return;
				case Keys::KEY_HYPHEN:
					m_Value += "-";
					return;
				case Keys::KEY_SPACE:
					m_Value += " ";
					return;
				case Keys::KEY_ADD:
					m_Value += "+";
					return;
				case Keys::KEY_SUBTRACT:
					m_Value += "-";
					return;
				case Keys::KEY_MULTIPLY:
					m_Value += "*";
					return;
				case Keys::KEY_DIVIDE:
					m_Value += "/";
					return;
				}
				}
			}
		};
	}
}