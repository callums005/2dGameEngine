#pragma once

#include "../Core/PCH.h"
#include "Components/Transform.h"
#include "Components/BoxCollider.h"
#include "Components/RectMesh.h"
#include "Components/Colour.h"
#include "Components/Texture.h"
#include "Components/Renderer.h"

namespace Engine
{
	class Entity
	{
	public:
		Entity() {}
		Entity(const STRING& tag, size_t id)
			: m_Tag(tag), m_Id(id) {}

		~Entity()
		{
			// Make sure to delete all components
			delete transform;
			delete boxCollider;
			delete rectMesh;
			delete colour;
			delete texture;
			delete renderer;
		}

		// Components
		
		Components::Transform* transform = nullptr;
		Components::BoxCollider* boxCollider = nullptr;
		Components::RectMesh* rectMesh = nullptr;
		Components::Colour* colour = nullptr;
		Components::Texture* texture = nullptr;
		Components::Renderer* renderer = nullptr;
		

		// Entity Functions
		boolean isEnabled() { return m_Enabled; }
		void setEnabled(boolean enabled) { m_Enabled = enabled; }
		const STRING& getTag() { return m_Tag; }
		const size_t getId() { return m_Id; }

		void Destroy() { m_ShouldDestroy = true; }
	private:
		const size_t m_Id = 0;
		const STRING m_Tag = "Default";
		boolean m_Enabled = true;
		boolean m_ShouldDestroy = false;

		friend class ECS; // Makes private varaibles accessable to EntityManager.h/.cpp
	};
}