#pragma once

#include "../Core/PCH.h"

#include "Scene.h"

namespace Engine
{
	class SceneManager
	{
	public:
		static void SetScene(Scene* scene);
		static void ClearScene();
		static Scene* GetScene();
	private:
		static inline Scene* m_CurrentScene = nullptr;
	};
}

