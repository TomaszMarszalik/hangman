#pragma once
#include <string>
#include <vector>

class WordsGenerator
{
public:
	WordsGenerator(const std::string& file_name);

	const std::string& get_random_word();

private:
	std::vector<std::string> m_words;
};