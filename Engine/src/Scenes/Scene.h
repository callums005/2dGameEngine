#pragma once

#include "../Core/PCH.h"

namespace Engine
{
	class Scene
	{
	public:
		virtual ~Scene() {}

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Close() = 0;
	protected:
		Scene() {}
	};
}