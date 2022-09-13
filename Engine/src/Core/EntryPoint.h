#pragma once

#include "PCH.h"
#include "Game.h"

#include "../Graphics/Window/Window.h"

extern Engine::Game* Engine::CreateGame();

/// <summary>
/// This is the entry point of the application,
/// It creates and stores a window and game application, 
/// then calls the client side functions and runs the main game loop.
/// </summary>
/// <param name="argc">Number of arguments</param>
/// <param name="argv">Arguments</param>
/// <returns>Exit code</returns>
int main(int argc, char** argv)
{
	Engine::Window* window = new Engine::Window();

	window->InitWindow(Engine::WindowProps(640, 480, "Game V1"));

	Engine::Game* app = Engine::CreateGame();
	app->SetWindow(window);
	app->Run();
	delete app;

	window->CloseWindow();
	return 0;
}