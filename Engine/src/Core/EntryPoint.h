#pragma once

#include "PCH.h"
#include "Game.h"

#include "../Graphics/Window/Window.h"

extern Engine::Game* Engine::CreateGame();

/// <summary>
/// Entry Point to the application:
/// Creates the main window and attaches it to the Engine::Game class
/// Calls OnStart, Run->OnUpdate, OnExit functions from the game client
/// </summary>
int main(int argc, char** argv)
{
	Engine::Window* window = new Engine::Window();

	window->InitWindow(Engine::WindowProps(640, 480, "Game V1"));

	Engine::Game* app = Engine::CreateGame();
	app->SetWindow(window);
	app->OnStart();
	app->Run();
	app->OnExit();
	delete app;

	window->CloseWindow();
	return 0;
}