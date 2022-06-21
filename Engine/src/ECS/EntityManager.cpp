#include "EntityManager.h"

namespace Engine
{
	void ECS::Update()
	{
		HandleEntityDelete();
		HandleEntityAdd();

		// Entity Systems here
		for (Entity* e : m_Entities)
		{
			if (!e->m_Enabled)
				continue;

			if (e->transform)
				e->transform->System();
			if (e->boxCollider && e->transform)
				e->boxCollider->System(&e->transform->m_Position, &e->transform->m_Size);
			if (e->rectMesh && e->transform)
				e->rectMesh->System(e->transform->m_Position, e->transform->m_Size, e->transform->m_Rotation);
			if (e->parent && e->transform)
				e->parent->System(e->transform);

		}
	}
	
	void ECS::HandleEntityDelete()
	{
		for (Entity* e : m_Entities)
		{
			if (!e->m_ShouldDestroy)
			{
				m_DeleteEntityBuffer.push_back(e);
				m_DeleteEntityMapBuffer[e->m_Tag].push_back(e);
			}
		}

		m_Entities.clear();
		m_EntityMap.clear();
		m_Entities = m_DeleteEntityBuffer;
		m_EntityMap = m_DeleteEntityMapBuffer;
		m_DeleteEntityBuffer.clear();
		m_DeleteEntityMapBuffer.clear();
	}

	void ECS::HandleEntityAdd()
	{
		for (Entity* e : m_AddEntityBuffer)
		{
			m_Entities.push_back(e);
			m_EntityMap[e->m_Tag].push_back(e);
		}

		m_AddEntityBuffer.clear();
	}

	Entity* ECS::AddEntity(const STRING& tag)
	{
		Entity* e = new Entity(tag, m_EntityCount++);
		m_AddEntityBuffer.push_back(e);
		return e;
	}
	boolean ECS::IsColliding(const Entity* e1, const Entity* e2)
	{
		if (!e1->m_Enabled || !e2->m_Enabled)
			return false;

		if (e1->boxCollider && e2->boxCollider)
		{
			if (e1->boxCollider->m_Position.x <= e2->boxCollider->m_Position.x + e2->boxCollider->m_Size.x
				&& e2->boxCollider->m_Position.x <= e1->boxCollider->m_Position.x + e1->boxCollider->m_Size.x
				&& e1->boxCollider->m_Position.y <= e2->boxCollider->m_Position.y + e2->boxCollider->m_Size.y
				&& e2->boxCollider->m_Position.y <= e1->boxCollider->m_Position.y + e1->boxCollider->m_Size.y)
			{
				return true;
			}

			return false;
		}

		return false;
	}
	EntityVector& ECS::GetEntities()
	{
		return m_Entities;
	}
	EntityVector& ECS::GetEntitiesByTag(const STRING& tag)
	{
		return m_EntityMap[tag];
	}
	Entity* ECS::GetEntityByID(const size_t id)
	{
		for (Entity* e : m_Entities)
			if (e->m_Id == id)
				return e;

		return nullptr;
	}
}