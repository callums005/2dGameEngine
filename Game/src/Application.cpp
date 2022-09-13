#include "Engine.h"

#include "Scenes/TestScene.h"
#include "Scenes/AnotherTestScene.h"

class Application : public Engine::Game
{
public:
	Application() {}
	~Application() 
	{
		delete testScene;
	}

	Engine::Entity* e;
	sf::Font Roboto;

	int sceneID = 0;

	TestScene* testScene = new TestScene();

	void OnStart()
	{
		if (!Roboto.loadFromFile("./res/fonts/roboto.ttf"))
			printf("Unable to load font\n");

		e = Engine::ECS::AddEntity("test");
		e->transform = new Engine::Components::Transform(Types::Vec2f(10, 10), Types::Vec2f(1, 1), Types::Vec2f(0, 0), 0);
		e->colour = new Engine::Components::Colour(Types::RGBA(255, 255, 0, 255));
		//e->text = new Engine::Components::Text("Button", 24, &Roboto);
		e->textInput = new Engine::Components::TextInput("Placeholder", 24, &Roboto, Types::Vec2f(10, 10), Types::Vec2f(50, 75));
		e->renderer = new Engine::Components::Renderer(&e->textInput->m_TextObject->m_Object, 0, Engine::RenderType::Colour, Engine::RenderShape::Text);
	} 

	void OnUpdate()
	{
		if (Engine::Input::IsKeyReleasedThisFrame(Engine::Keys::KEY_SPACE))
		{
			if (sceneID == 0)
			{
				sceneID = 1;
				Engine::SceneManager::SetScene(testScene);
			}
		}
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