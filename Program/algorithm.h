// алгоритмы
#ifndef PROGRAM_ALGORITHM_H
#define PROGRAM_ALGORITHM_H
#include <iostream>
#include "generation.h"

int native(std::string& str, std::string& substr);
int kmp(std::string& pattern, std::string& text);
int kmpBest(std::string& pattern, std::string& text);
int rabinKarp(std::string& text, std::string& pattern);

#endif //PROGRAM_ALGORITHM_H