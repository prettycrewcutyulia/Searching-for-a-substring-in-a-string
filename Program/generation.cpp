#include <iostream>
#include <random>
#include "generation.h"

std::string textBin(int size) {
    srand(time(NULL));
    std::string result(size, ' ');
    for (int i = 0; i < size; ++i) {
        result[i] = (rand() % 2 == 0) ? '0' : '1';
    }
    return result;
}

std::string textDNA(int size) {
    srand(time(nullptr));
    std::string result(size, ' ');
    for (int i = 0; i < size; ++i) {
        result[i] = "ATCG"[rand() % 4];
    }
    return result;
}

std::vector<std::string> getSubstring(std::string& text) {
    srand(time(NULL));
    int startPos = rand() % text.size();
    std::vector<std::string> substrings;
    for (int i = 100; i <= 3000; i += 100) {
        substrings.push_back(text.substr(startPos, i));
    }
    return substrings;
}

std::string insertWildcards(std::string& pattern, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int index = rand() % pattern.size();
        pattern[index] = '?';
    }
    return pattern;
}


std::vector<std::string> generateStrings(std::string pattern, std::string alphabet) {
    std::vector<std::string> result;
    int n = pattern.length();
    int m = alphabet.length();
    int count = 1;
    for (int i = 0; i < n; ++i) {
        if (pattern[i] == '?') {
            count *= m;
        }
    }
    for (int i = 0; i < count; ++i) {
        std::string s = pattern;
        int k = i;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '?') {
                s[j] = alphabet[k % m];
                k /= m;
            }
        }
        result.push_back(s);
    }
    return result;
}

