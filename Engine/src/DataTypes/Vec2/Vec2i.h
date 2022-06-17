#pragma once

#include "../../Core/PCH.h"

namespace Utilities
{
	class Vec2i
	{
	public:
		int x = 0;
		int y = 0;

		Vec2i()
		{}

		Vec2i(int x_in, int y_in)
			: x(x_in), y(y_in)
		{}

		Vec2i operator + (const Vec2i& rhs) const // rhs: right hand side
		{
			return Vec2i(x + rhs.x, y + rhs.y);
		}

		Vec2i operator - (const Vec2i& rhs) const // rhs: right hand side
		{
			return Vec2i(x - rhs.x, y - rhs.y);
		}

		Vec2i operator * (const int scale) const // rhs: right hand side
		{
			return Vec2i(x * scale, y * scale);
		}

		Vec2i operator * (const Vec2i scale) const // rhs: right hand side
		{
			return Vec2i(x * scale.x, y * scale.y);
		}

		void operator += (const Vec2i& rhs) // rhs: right hand side
		{
			x += rhs.x;
			y += rhs.y;
		}

		void operator -= (const Vec2i& rhs) // rhs: right hand side
		{
			x -= rhs.x;
			y -= rhs.y;
		}
	};
}