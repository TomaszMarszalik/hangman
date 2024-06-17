#pragma once
#include <string>
#include <vector>

#include "WordsGenerator.h"

class Game
{
	enum class GameState
	{
		STARTED,
		UPDATED,
		FINISHED
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
	char m_selected_letter;
	std::vector<char> m_guessed_letters;
	GameState m_game_state = GameState::STARTED;
	WordsGenerator m_word_generator;
	size_t m_errors_counter = 0;
	size_t m_guessed_counter = 0;
};