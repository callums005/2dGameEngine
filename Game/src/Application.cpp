#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() { }
	~Application() { }

	Engine::Entity* e;

	void LogKeyPress(Engine::Event& e)
	{
		std::cout << "KEY PRESSED: " << (int)e.KeyEvent->KeyCode << std::endl;
	}

	void OnStart()
	{
		Engine::EventDispatcher::GetEventFromName("KeyDown") += EventFunc(LogKeyPress);	

		e = Engine::ECS::AddEntity("player");
		e->Destroy();
		e->transform = new Engine::Components::Transform(Types::Vec2f(5.0f, 5.0f), Types::Vec2f(100.0f, 100.0f), Types::Vec2f(0.2f, 0.2f), 0);
		e->rectMesh = new Engine::Components::RectMesh(0, Types::RGBA(0, 0, 0, 100));
		e->colour = new Engine::Components::Colour(Types::RGBA(255, 0, 0, 255));
		e->renderer = new Engine::Components::Renderer(&e->rectMesh->m_Shape, 0, Engine::RenderType::Colour, Engine::RenderShape::Rectangle);
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