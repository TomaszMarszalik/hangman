#include "WordsGenerator.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

WordsGenerator::WordsGenerator(const std::string& file_name)
{
	std::ifstream ifs(file_name);
	
	std::string word;
	while (std::getline(ifs, word))
	{
		m_words.push_back(word);
	}
	ifs.close();
}

const std::string& WordsGenerator::get_random_word()
{
	int randomIndex = rand() % m_words.size();
	return m_words[randomIndex];
}
