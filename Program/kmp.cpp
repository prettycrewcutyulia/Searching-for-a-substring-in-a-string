#include <iostream>
#include "algorithm.h"

// Кнута-Морриса-Прата с применением стандартных граней
std::vector<int> calculatePrefix(std::string& pattern) {
    std::vector<int> prefix(pattern.length(), 0);
    int j = 0;
    for (size_t i = 1; i < pattern.length(); ++i) {
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

int kmp(std::string& text, std::string& pattern) {
    std::vector<std::string> strings(0);
    if (pattern.find('?') != std::string::npos) {
        if (pattern[0] == '0' || pattern[0] == '1') {
            strings = generateStrings(pattern, "01");
        } else {
            strings = generateStrings(pattern, "ACGT");
        }
    } else {
        strings.push_back(pattern);
    }
    int cur_occurences = -1;
    for (auto & string : strings) {
        std::vector<int> prefix = calculatePrefix(string);
        size_t j = 0;
        int occurrences = - 1;
        for (size_t i = 0; i < text.length(); ++i) {
            while (j > 0 && string[j] != text[i]) {
                j = prefix[j - 1];
            }
            if (string[j] == text[i]) {
                j++;
            }
            if (j == string.length()) {
                occurrences = i - string.length() + 1;
                j = prefix[j - 1];
            }
        }
        if (occurrences > cur_occurences) {
            cur_occurences = occurrences;
        }
    }
    return cur_occurences;
}