#include <iostream>
#include "algorithm.h"
// Кнута-Морриса-Прата с применением уточненных граней
std::vector<int> calculateBrs(std::vector<int>& br, std::string& pattern);
// реализуй функцию нахождения массива граней
// для строки pattern
std::vector<int> calculateBorders(std::string& pattern) {
    int n = pattern.length();
    std::vector<int> br(n, 0);
    br[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = br[i - 1];
        while (j > 0 && pattern[j] != pattern[i]) {
            j = br[j - 1];
        }
        if (pattern[j] == pattern[i]) {
            j++;
        }
        br[i] = j;
    }
    return br;
}

int kmpBest(std::string& text, std::string& pattern) {
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
    int m = pattern.length();
    int n = text.length();
    std::vector<int> br = calculateBorders(pattern);
    std::vector<int> brs = calculateBrs(br, pattern);
    int count = 0;
    int cur_occurences = -1;
    for (int k = 0; k < strings.size(); k++) {
        int occurrences = -1;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && (strings[k][j] != text[i])) {
                j = brs[j - 1];
            }
            if (strings[k][j] == text[i]) {
                j++;
            }
            if (j == m) {
                count++;
                occurrences = (i - m + 1);
                j = brs[j - 1];
            }
        }
        if (occurrences > cur_occurences) {
            cur_occurences = occurrences;
        }
    }
    return cur_occurences;
}

std::vector<int> calculateBrs(std::vector<int>& br, std::string& pattern) {
    std::vector<int> brs(br.size(), 0);
    for (size_t i = 0; i < br.size(); ++i) {
        if (i + 1 == br.size()) {
            brs[i] = br[i];
        } else {
            if (br[i] >= br[i + 1]) {
                brs[i] = br[i];
            }
        }
    }
    return brs;
}