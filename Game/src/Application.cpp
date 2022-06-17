#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() { }
	~Application() { }

	void LogKeyPress(Engine::Event& e)
	{
		std::cout << "KEY PRESSED: " << (int)e.KeyEvent->KeyCode << std::endl;
	}

	void OnStart()
	{
		Engine::EventDispatcher::GetEventFromName("KeyDown") += EventFunc(LogKeyPress);
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