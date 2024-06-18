#include "Game.h"

#include <iostream>

constexpr const char* WORDS_FILE = "words.txt";
constexpr size_t MAX_ERRORS_COUNT = 6;

namespace
{
	char get_input(const std::vector<char>& guessed_letters)
	{
		char choice = ' ';
		std::cout << "Enter letter (a-z)" << std::endl;
		std::cin >> choice;
		while (not (((choice >= 'a' and choice <= 'z') or (choice >= 'A' and choice <= 'Z')) and
			(std::find(guessed_letters.begin(), guessed_letters.end(), std::toupper(choice)) == guessed_letters.end())))
		{ // if the user repeat incorrect letters the error count will increase
			std::cout << "Invalid character or it was already entered, try again" << std::endl;
			std::cin >> choice;
		} 

		return choice;
	}

	void render(size_t no_of_errors)
	{
		system("cls");
		switch (no_of_errors)
		{
		case 1: std::cout << "|" << std::endl << "|" << std::endl << "|" << std::endl << "|" << std::endl; break;
		case 2: std::cout << "----" << std::endl << "|" << std::endl << "|" << std::endl << "|" << std::endl << "|" << std::endl; break;
		case 3: std::cout << "----" << std::endl << "|/" << std::endl << "|" << std::endl << "|" << std::endl << "|" << std::endl; break;
		case 4: std::cout << "----" << std::endl << "|/ |" << std::endl << "|  O" << std::endl << "|" << std::endl << "|" << std::endl; break;
		case 5: std::cout << "----" << std::endl << "|/ |" << std::endl << "| \\O/" << std::endl << "|" << std::endl << "|" << std::endl; ; break;
		case 6: std::cout << "----" << std::endl << "|/ |" << std::endl << "| \\O/" << std::endl << "|  |" << std::endl << "| / \\" << std::endl; ; break;
		default: break; // do nothing
		}
	}
}

Game::Game() :
	m_word_generator(WORDS_FILE)
{
}

void Game::OnInit()
{
	m_errors_counter = 0;
	m_guessed_counter = 0;
	m_word = m_word_generator.get_random_word();

	m_guessed_letters.clear();
	m_guessed_letters.reserve(m_word.length());
	for (int i = 0; i < m_word.length(); ++i)
	{
		m_guessed_letters.push_back('-');
	}
}

void Game::OnInput()
{
	m_selected_letter = get_input(m_guessed_letters);
}

bool Game::OnUpdate(float deltaTime)
{
	bool found = false;
	for (int i = 0; i < m_word.length(); ++i)
	{
		if (std::toupper(m_word[i]) == std::toupper(m_selected_letter))
		{
			found = true;
			m_guessed_letters[i] = std::toupper(m_selected_letter);
			if (++m_guessed_counter == m_word.length())
			{
				m_game_state = GameState::FINISHED;
				return false;
			}
		}
	}
	
 	if ((not found) and (++m_errors_counter >= MAX_ERRORS_COUNT))
	{
		m_game_state = GameState::FINISHED;
		return false;
	}

	return true;
}

void Game::OnRender()
{
	render(m_errors_counter);
	for (int i = 0; i < m_word.length(); ++i)
	{
		std::cout << m_guessed_letters[i] << " ";
	}
	std::cout << std::endl;

	if (m_game_state == GameState::FINISHED)
	{
		if (m_word.length() == m_guessed_counter)
		{
			std::cout << "You've won!" << std::endl;
		}
		else if (m_errors_counter >= MAX_ERRORS_COUNT) // should be exclusive, but let's be sure
		{
			std::cout << "You've lost!" << std::endl;
		}
		std::cout << "Searched word: " << m_word;
	}
	else
	{
		std::cout << "No of failed guesses: " << m_errors_counter << std::endl;
	}
}

void Game::OnShutdown()
{
	m_guessed_letters.clear();
	m_errors_counter = 0;
}
