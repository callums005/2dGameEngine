#pragma once

#include "Engine.h"

class TestScene : public Engine::Scene
{
public:
	TestScene() {}
	~TestScene()
	{}

	void Init() override
	{
		Engine::Logger::Info("TestScene");
	}

	void Update() override
	{

	}

	void Close() override
	{
		Engine::Logger::Info("Closed TestScene");
	}
};