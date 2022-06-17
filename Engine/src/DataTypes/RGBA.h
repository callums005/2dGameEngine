#pragma once

#include "../Core/PCH.h"

namespace Utilities
{
	class RGBA
	{
	public:
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 100;

		RGBA()
		{}

		RGBA(int r_in, int g_in, int b_in, int a_in)
			: r(r_in), g(g_in), b(b_in), a(a_in)
		{}

		RGBA operator + (const RGBA& rhs) const // rhs: right hand side
		{
			return RGBA(r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a);
		}

		RGBA operator - (const RGBA& rhs) const // rhs: right hand side
		{
			return RGBA(r - rhs.r, g - rhs.g, b - rhs.b, a - rhs.a);
		}

		RGBA operator * (const int scale) const // rhs: right hand side
		{
			return RGBA(r * scale, g * scale, b * scale, a * scale);
		}

		RGBA operator * (const RGBA scale) const // rhs: right hand side
		{
			return RGBA(r * scale.r, g * scale.g, b * scale.b, a * scale.a);
		}

		void operator += (const RGBA& rhs) // rhs: right hand side
		{
			r += rhs.r;
			g += rhs.g;
			b += rhs.b;
			a += rhs.a;
		}

		void operator -= (const RGBA& rhs) // rhs: right hand side
		{
			r -= rhs.r;
			g -= rhs.g;
			b -= rhs.b;
			a -= rhs.a;
		}
	};
}