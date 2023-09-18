//
// Created by Юлия Гудошникова on 10.04.2023.
//

#ifndef PROGRAM_GENERATION_H
#define PROGRAM_GENERATION_H
#include <iostream>

std::string textBin(int size);
std::string textDNA(int size);
std::vector<std::string> getSubstring(std::string& text);
std::string insertWildcards(std::string& pattern, int count);
std::vector<std::string> generateStrings(std::string pattern, std::string alphabet);

#endif //PROGRAM_GENERATION_H
