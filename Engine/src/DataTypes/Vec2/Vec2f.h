#pragma once

#include "../../Core/PCH.h"

namespace Utilities
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

		//static sf::Vector2f ConvertToSF(Vec2f vec)
		//{
		//	return sf::Vector2f(vec.x, vec.y);
		//}
	};
}