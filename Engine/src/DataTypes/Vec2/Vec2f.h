#pragma once

#include "../../Core/PCH.h"

#include "SFML/System/Vector2.hpp"

namespace Types
{
	class Vec2f
	{
	public:
		float x = 0;
		float y = 0;

		Vec2f()
		{}

		Vec2f(float x_in, float y_in)
			: x(x_in), y(y_in)
		{}

		Vec2f operator + (const Vec2f& rhs) const // rhs: right hand side
		{
			return Vec2f(x + rhs.x, y + rhs.y);
		}

		Vec2f operator - (const Vec2f& rhs) const // rhs: right hand side
		{
			return Vec2f(x - rhs.x, y - rhs.y);
		}

		Vec2f operator * (const float scale) const // rhs: right hand side
		{
			return Vec2f(x * scale, y * scale);
		}

		Vec2f operator * (const Vec2f scale) const // rhs: right hand side
		{
			return Vec2f(x * scale.x, y * scale.y);
		}

		void operator = (const Vec2f& rhs)
		{
			x = rhs.x;
			y = rhs.y;
		}

		void operator += (const Vec2f& rhs) // rhs: right hand side
		{
			x += rhs.x;
			y += rhs.y;
		}

		void operator -= (const Vec2f& rhs) // rhs: right hand side
		{
			x -= rhs.x;
			y -= rhs.y;
		}

		sf::Vector2f toSF()
		{
			return sf::Vector2f(x, y);
		}
	};
}