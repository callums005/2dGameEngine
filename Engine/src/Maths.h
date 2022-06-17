#pragma once

#include "./Core/PCH.h"

namespace Engine
{
	class Maths
	{
	public:
		static bool Range(int value, int min, int max)
		{
			if (value >= min && value <= max)
				return true;

			return false;
		}

		static bool Range(float value, float min, float max)
		{
			if (value >= min && value <= max)
				return true;

			return false;
		}

		static int Min(int values[])
		{
			int min = values[0];

			for (int i = 1; i < (sizeof(values)/sizeof(int)); i++)
			{
				if (values[i] < min)
					min = values[i];
			}

			return min;
		}

		static int Min(float values[])
		{
			float min = values[0];

			for (int i = 1; i < (sizeof(values) / sizeof(float)); i++)
			{
				if (values[i] < min)
					min = values[i];
			}

			return min;
		}

		static int Max(int values[])
		{
			int max = values[0];

			for (int i = 1; i < (sizeof(values) / sizeof(int)); i++)
			{
				if (values[i] > max)
					max = values[i];
			}

			return max;
		}

		static int Max(float values[])
		{
			float max = values[0];

			for (int i = 1; i < (sizeof(values) / sizeof(float)); i++)
			{
				if (values[i] > max)
					max = values[i];
			}

			return max;
		}
	};
}