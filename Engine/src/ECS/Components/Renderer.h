#pragma once

#include "../../Core/PCH.h"
#include "../ComponentBase.h"

#include "SFML/Graphics.hpp"

namespace Engine
{
	namespace Components
	{
		class Renderer : public Component
		{
		public:
			Renderer() {}

			Renderer(sf::Drawable* object, int order, RenderType renderType, RenderShape shape)
				: m_Object(object), m_RenderOrder(order), m_RenderType(renderType), m_RenderShape(shape) {}

			void System()
			{
			}

			int m_RenderOrder = 0;
			sf::Drawable* m_Object;
			RenderType m_RenderType = RenderType::Colour;
			RenderShape m_RenderShape = RenderShape::Rectangle;
		};
	}
}