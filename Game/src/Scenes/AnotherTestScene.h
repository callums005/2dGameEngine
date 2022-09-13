#pragma once

#include "Engine.h"

class AnotherTestScene : public Engine::Scene
{
public:
	AnotherTestScene() {}
	~AnotherTestScene() {}

	void Init() override
	{
		Engine::Logger::Info("AnotherTestScene");
	}

	void Update() override
	{

	}

	void Close() override
	{

	}
};