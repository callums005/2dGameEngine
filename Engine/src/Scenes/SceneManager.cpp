#include "SceneManager.h"

namespace Engine
{
	
	void SceneManager::SetScene(Scene* scene)
	{
		ClearScene();

		m_CurrentScene = scene;
		m_CurrentScene->Init();
	}

	void SceneManager::ClearScene()
	{
		if (m_CurrentScene)
			m_CurrentScene->Close();

		m_CurrentScene = nullptr;
	}

	Scene* SceneManager::GetScene()
	{
		return m_CurrentScene;
	}
}