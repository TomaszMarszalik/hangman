#include "Game.h"

#include <iostream>

constexpr const char* WORDS_FILE = "words.txt";

Game::Game() :
	m_word_generator(WORDS_FILE)
{
}

void Game::OnInit()
{
	m_guessedLetters.clear();
	m_word = m_word_generator.get_random_word();
}

void Game::OnInput()
{
}

bool Game::OnUpdate(float deltaTime)
{
	return false;
}

void Game::OnRender()
{
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();
}
