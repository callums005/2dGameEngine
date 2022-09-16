#pragma once

#include "Engine.h"

class TestScene : public Engine::Scene
{
public:
	TestScene() {}
	~TestScene()
	{}

	Engine::Entity* player;

	void Init() override
	{
		Engine::Logger::Info("TestScene");

		player = Engine::ECS::AddEntity("Player");
		player->transform = new Engine::Components::Transform(Types::Vec2f(10, 10), Types::Vec2f(50, 50), Types::Vec2f(0, 0), 0);
		player->rectMesh = new Engine::Components::RectMesh(0, Types::RGBA(0, 0, 0, 0));
		player->colour = new Engine::Components::Colour(Types::RGBA(255, 0, 0, 255));
		player->renderer = new Engine::Components::Renderer(&player->rectMesh->m_Shape, 1, Engine::RenderType::Colour, Engine::RenderShape::Rectangle);
	}

	void Update() override
	{
		player->transform->m_Velocity = Types::Vec2f(0, 0);


		if (Engine::Input::IsKeyDown(Engine::Keys::KEY_D))
			player->transform->m_Velocity = Types::Vec2f(1, 0);

		if (Engine::Input::IsKeyDown(Engine::Keys::KEY_A))
			player->transform->m_Velocity = Types::Vec2f(-1, 0);
	}

	void Close() override
	{
		Engine::Logger::Info("Closed TestScene");
	}
};