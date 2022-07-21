#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() {}
	~Application() {}

	sf::Font font;
	Engine::Entity* e;
	int c = 0;

	void OnStart()
	{
		if (!font.loadFromFile("./res/fonts/roboto.ttf"))
			Engine::Logger::Error("Unable to load font");
	
		e = Engine::ECS::AddEntity("test");
		e->transform = new Engine::Components::Transform(Types::Vec2f(10, 10), Types::Vec2f(1, 1), Types::Vec2f(0, 0), 0);
		e->colour = new Engine::Components::Colour(Types::RGBA(255, 255, 0, 255));
		e->text = new Engine::Components::Text(std::to_string(c), 24, &font);
		e->renderer = new Engine::Components::Renderer(&e->text->m_Object, 0, Engine::RenderType::Colour, Engine::RenderShape::Text);
	} 

	void OnUpdate()
	{
		c++;
		e->text->m_Text = std::to_string(c);
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