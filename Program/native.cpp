#include <iostream>
#include "algorithm.h"
// Наивный алгоритм

int native(std::string& str, std::string& substr) {
    int str_len = str.length();
    int substr_len = substr.length();
    int last_occurrence = -1;

    for (int i = 0; i <= str_len - substr_len; i++) {
        bool match = true;

        for (int j = 0; j < substr_len; j++) {
            if (substr[j] != '?' && str[i+j] != substr[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            last_occurrence = i;
        }
    }

    return last_occurrence;
}