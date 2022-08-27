#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() {}
	~Application() {}

	Engine::Entity* e;
	sf::Font Roboto;

	void OnStart()
	{
		if (!Roboto.loadFromFile("./res/fonts/roboto.ttf"))
			printf("Unable to load font\n");

		e = Engine::ECS::AddEntity("test");
		e->transform = new Engine::Components::Transform(Types::Vec2f(10, 10), Types::Vec2f(1, 1), Types::Vec2f(0, 0), 0);
		e->colour = new Engine::Components::Colour(Types::RGBA(255, 255, 0, 255));
		e->text = new Engine::Components::Text("Button", 24, &Roboto);
		e->renderer = new Engine::Components::Renderer(&e->text->m_Object, 0, Engine::RenderType::Colour, Engine::RenderShape::Text);
		
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