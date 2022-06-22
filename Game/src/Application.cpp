#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() {}
	~Application() {}

	void OnStart()
	{
	} 

	void OnUpdate()
	{
	}

	void OnExit()
	{
	}
};

/// <summary>
/// Gives the engine a main class derived from Engine::Game
/// </summary>
/// <returns>Engine::Game*</returns>
Engine::Game* Engine::CreateGame()
{
	return new Application();
}