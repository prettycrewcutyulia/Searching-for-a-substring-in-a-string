#include <iostream>
#include <string>
#include <vector>
#include "algorithm.h"
// d is the number of characters in the input alphabet
int d = 4;
int q = INT_MAX;

int rabinKarp(std::string& text, std::string& pattern) {
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
    int n = text.length(), m_len = pattern.length();
    int cur_occurences = -1;
    for (int k = 0; k < strings.size(); k++) {
        int p = 0, t = 0, h = 1, last_occurrence = -1;
        for (int i = 0; i < m_len - 1; i++) {
            h = (h * d) % q;
        }
        for (int i = 0; i < m_len; i++) {
            p = (d * p + strings[k][i]) % q;
            t = (d * t + text[i]) % q;
        }
        for (int i = 0; i <= n - m_len; i++) {
            if (p == t) {
                int j;
                for (j = 0; j < m_len; j++) {
                    if (text[i + j] != strings[k][j]) {
                        break;
                    }
                }
                if (j == m_len) {
                    last_occurrence = i;
                }
            }
            if (i < n - m_len) {
                t = (d * (t - text[i] * h) + text[i + m_len]) % q;
                if (t < 0) {
                    t += q;
                }
            }
        }
        if (last_occurrence > cur_occurences) {
            cur_occurences = last_occurrence;
        }
    }
    return cur_occurences;
}