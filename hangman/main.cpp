#include "Game.h"

#include <cstdlib>
#include <ctime>

using namespace std;

void Initialize();
void GetInput();
void Update(float deltaTime);
void Render();
void Shutdown();


bool g_exitGame = true;
Game g_game;

int main()
{
	Initialize();
	while (g_exitGame)
	{
		GetInput();
		Update(0.0f);
		Render();
	}
	Shutdown();
	return 0;
}

void Initialize()
{
	srand(std::time(NULL));
	g_game.OnInit();
}

void GetInput()
{
	g_game.OnInput();
}

void Update(float deltaTime)
{
	g_exitGame = g_game.OnUpdate(deltaTime);
}

void Render()
{
	g_game.OnRender();
}

void Shutdown()
{
	g_game.OnShutdown();
}
