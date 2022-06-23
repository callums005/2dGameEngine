# 2D Game Engine

You can find the project Trello [here]("https://trello.com/b/G24FWYry/2d-game-engine")

## Technical Specs
- Language: C++
- IDE: Visual Studio 2022
- Libarary(ies):
	- [SFML](https://www.sfml-dev.org/)

---

## Program Architecture
The program is iscolated into 2 projects within the solution, the game engine ([Engine]("./Engine")) and the client ([Game]("./Game")). The entry point is within the Engine project. Within the Client project, there is a class that derives from the `Game` class. The entry point will instanciate the class within the Client on the heap and run the setup functions.
<br>
There are 3 functions that must be implemented, `void OnStart()` this is called when the program starts, `void OnUpdate()` this is called each frame. `void OnExit()` this is called at the end of the program.

**Boilerplate Application Class:**

```cpp
#include "Engine.h"

class Application : public Engine::Game
{
public:
	Application() { }
	~Application() { }

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
```
---

# Engine Unilities

## Event System
You are able to create events on the client or use events created in the Engine by subscribing a function to the event. Subscribing to an event will call the function when the event is dispatched.

### Events
| Event Name | Description |
| ---------- | ----------- |
| OnApplicationStart | This event is dispatched when the application starts |
| OnApplicationExit | This event is dispatched when the application ends |
| OnWindowClose | This event is dispatched when you tell the window to close (Using ant+F4 or the exit cross) |
| OnWindowResize | This event is dispatched when the window is resized |
| OnWindowMove | This event is dispatched when the window is moved |
| MouseDown | This event is dispatched when a mouse button is pressed |
| MouseUp | This event is dispatched when a mouse button is released |
| MouseMove | This event is dispatched when the mouse is moved |
| MouseScroll | This event is dispatched when the mouse scroll wheel is moved |
| KeyDown | This event is dispatched when a key is pressed |
| KeyUp | This event is dispatched when a key is released |

You can access the data via the corresponding classes on the event.

**Using an Engine Event Example:**
```cpp
// Printing out the keycode when a key is pressed
void LogKeyPress(Engine::Event& e)
{
	std::cout << "KEY PRESSED: " << (int)e.KeyEvent->KeyCode << std::endl;
}

void OnStart()
{
	// Subscribing event using the GetEventFromName function
	Engine::EventDispatcher::GetEventFromName("KeyDown") += EventFunc(LogKeyPress);
}
```

**Using a Client Event Example:**
```cpp
// Printing out the keycode when a key is pressed
void Test(Engine::Event& e)
{
	std::cout << "Hello World" << std::endl;
}

void OnStart()
{
	// Creates the event called "TestEvent" and returns the event ID
	size_t eventID = Engine::EventDispatcher::GenerateEvent("TestEvent",Engine::EventType::UserDefined);
	// Uses the GetEventFromID function to get the event and subscribes
	Engine::EventDispatcher::GetEventFromID(eventID) += EventFunc(Test);
}
```

---
# Input & Output

## Input

There are two ways to get user input, by using the event system (described above this) or using the Input class. However the event system will take more to set up.

Both the keyboard and mouse make use of 3 types of functions:
- `IsDown()` this will check if the key/button is down that frame
- `IsReleasedThisFrame()` this will check if the key/button was released that frame
- `IsUp()` this will check if the key/button is not pressed that frame.

Keyboard Implementations:
- `IsKeyDown(Keys _keyCode)`
- `IsKeyReleasedThisFrame(Keys _keyCode)`
- `IsKeyUp(Keys _keyCode)`

Mouse Implementations:
- `IsMouseButtonDown(MouseButton _button)`
- `IsMouseButtonReleasedThisFrame(MouseButton _button)`
- `IsMouseButtonUp(MouseButton _button)`

Examples:
```cpp
if (Engine::Input::IsKeyDown(Engine::Keys::KEY_A))
	std::cout << "A was pressed" << std::endl;
if (Engine::Input::IsKeyReleasedThisFrame(Engine::Keys::KEY_B))
	std::cout << "B was released" << std::endl;
if (Engine::Input::IsKeyUp(Engine::Keys::KEY_C))
	std::cout << "C is not pressed" << std::endl;

if (Engine::Input::IsMouseButtonDown(Engine::MouseButton::MOUSE_BUTTON_LEFT))
	std::cout << "Left button is down" << std::endl;
if (Engine::Input::IsMouseButtonReleasedThisFrame(Engine::MouseButton::MOUSE_BUTTON_RIGHT))
	std::cout << "Right button was released" << std::endl;
if (Engine::Input::IsMouseButtonUp(Engine::MouseButton::MOUSE_BUTTON_LEFT))
	std::cout << "Left button is not down" << std::endl;
```
---
## Output

The engine has a `Logger` class, this will allow you to print messages to the console in colour. You are also able to use C++ predefined functions to print to the console.

| Function Name | Color 
| ------------- | ----- 
| `Trace()` | <span style="color:white">White</span> 
| `Debug()` | <span style="color:green">Green</span> 
| `Info()` 	| <span style="color:grey">Grey</span> 	
| `Warn()` 	| <span style="color:yellow">Yellow</span> 
| `Error()` | <span style="color:red">Red</span> 	
| `Fatal()` | <span style="color:blue">Blue</span> 	

**Example:**

```cpp
void OnStart()
{
	Engine::Logger::Debug("Hello World");
}
```

Use the `Logger` functions the same as `printf()`, you can find references [here](https://cplusplus.com/reference/cstdio/printf/).

---

# Entity Component System
You are able to create entities(parents) with components(children). You can access entities with the `ECS` namespace and components with the `Components` namespace.

## Creating an entity
To create an entity, give the `AddEntity` function a tag to assign with the entity. The function will return a pointer that points to the entity stored in the engine.
```cpp
Engine::Entity* e = Engine::ECS::AddEntity("player");
```

## Deleting an entity
To delete an entity, use the `Destroy` function. Note that the entity will be destroyed at the start of the next frame.
```cpp
e->Destroy();
```

## Adding components to an entity
To add a component to an entity, you must first have a pointer to the entity. Simply access the class on the entity and assign it a new component.
```cpp
e->transform = new Engine::Components::Transform(Types::Vec2f(5.0f, 5.0f), Types::Vec2f(100.0f, 100.0f), Types::Vec2f(0.2f, 0.2f), 0);
```

## Deleting a component
To delete a component, assign the entity's component class as a `nullptr`
```cpp
e->transform = nullptr;
```

## Components

| Component | Description | Args |
| --------- | ----------- | ---- |
| Transform | Stores position, size, velocity and rotation of an entity. | Vec2f pos, Vec2f size, Vec2f vel, float rotation |
| BoxCollider | Allows 2D box collision. **Requires Transform**. | Vec2f size |
| RectMesh | Renders a square or rectangle shape. **Requires Transform**. | int outlineThickness, RGBA outlineColour |
| CircleMesh | Renders a circle shape. **Requires Transform**. Note the size of the circle is the radius and determined by the width(x value) of Transform.m_Size | int outlineThickness, RGBA outlineColour |
| ConvexMesh | Renders a shape defined by a list of Type::Vec2f points. **Requires Transform**. | int outlineThickness, RGBA outlineColour, std::vector<Types::Vec2f> points |
| Colour | Tells the renderer what colour to assign to the entity. **Requires Mesh**. | RGBA colour |
| Texture | Tells the renderer what texture to assign to the entity **Requires Mesh** | STRING filePath |
| Renderer | Renderers an entity to the screen. **Requires Mesh, Colour/Texture, Transform** | sf::Mesh object, int order, RenderType renderType, RenderShape shape |
| Parent | Sets the entity's parent object, use offset Transform to position away from parent. **Requires Parent.Transform, Transform** | size_t parentID, Transform* parentTransform, Transform offsetTransform |