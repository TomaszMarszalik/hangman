#pragma once
#include <string>
#include <vector>

#include "WordsGenerator.h"

class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};

public:
	Game();

	void OnInit();
	void OnInput();
	bool OnUpdate(float deltaTime);
	void OnRender();
	void OnShutdown();

private:
	std::string m_word;
	std::vector<bool> m_guessedLetters;
	GameState m_gameState = GameState::START;
	WordsGenerator m_word_generator;
};