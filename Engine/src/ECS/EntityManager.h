#pragma once

#include "../Core/PCH.h"

#include "Entity.h"

namespace Engine
{
	typedef std::vector<Entity*> EntityVector;
	typedef std::map<std::string, EntityVector> EntityMap;

	class ECS 
	{
	public:
		static void Update();
		static Entity* AddEntity(const STRING& tag);
		static boolean IsColliding(const Entity* e1, const Entity* e2);
		static EntityVector& GetEntities(); // Returns alll entities
		static EntityVector& GetEntitiesByTag(const STRING& tag); // Returns all entities with the tatg
		static Entity* GetEntityByID(const size_t id);
	private:
		static inline EntityVector m_Entities;
		static inline EntityMap m_EntityMap;

		static inline EntityVector m_AddEntityBuffer;
		static inline EntityVector m_DeleteEntityBuffer;
		static inline EntityMap m_DeleteEntityMapBuffer;

		static void HandleEntityDelete();
		static void HandleEntityAdd();

		static inline size_t m_EntityCount = 1;
	};
}