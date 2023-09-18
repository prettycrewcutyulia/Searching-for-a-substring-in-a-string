#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "generation.h"

long long int time (std::string& text, std::string& substring, int (*algorithm)(std::string&, std::string&)) {
    long long int duration;
    auto start = std::chrono::high_resolution_clock::now();
    algorithm(text, substring);
    auto end = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
typedef int (*Algorithm)(std::string&, std::string&);

void
getData(std::vector<Algorithm>& algorithms, std::vector<std::string> names, std::string &text, std::vector<std::string> &substring,
        std::ofstream &outputFile1);

void dataWithout(std::vector<Algorithm> algorithms, std::vector<std::string> names) {
    std::string text = textBin(10000);
    std::vector<std::string> substring = getSubstring(text);
    std::ofstream outputFile1("bin10000.csv");
    getData(algorithms, names, text, substring, outputFile1);
    outputFile1.close();
    text = textBin(100000);
    substring = getSubstring(text);
    std::ofstream outputFile2("bin100000.csv");
    getData(algorithms, names, text, substring, outputFile2);
    outputFile2.close();
    text = textDNA(10000);
    substring = getSubstring(text);
    std::ofstream outputFile3("DNA10000.csv");
    getData(algorithms, names, text, substring, outputFile3);
    outputFile3.close();
    text = textDNA(100000);
    substring = getSubstring(text);
    std::ofstream outputFile4("DNA100000.csv");
    getData(algorithms, names, text, substring, outputFile4);
    outputFile4.close();
}
void dataWith(std::vector<Algorithm> algorithms, std::vector<std::string> names) {
    std::string text = textBin(10000);
    std::vector<std::string> substring = getSubstring(text);
    int count;
    for (count = 1; count <= 4; count++) {
        for (int i = 0; i < substring.size(); i++) {
            substring[i] = insertWildcards(substring[i], count);
        }
        std::ofstream outputFile1("bin10000?" + std::to_string(count)+".csv");
        outputFile1 << "Количество ?:" << count << "\n";
        getData(algorithms, names, text, substring, outputFile1);
        outputFile1.close();
        text = textBin(100000);
        substring = getSubstring(text);
        std::ofstream outputFile2("bin100000?"+ std::to_string(count) +".csv");
        outputFile2 << "Количество ?:" << count << "\n";
        getData(algorithms, names, text, substring, outputFile2);
        outputFile2.close();
        text = textDNA(10000);
        substring = getSubstring(text);
        std::ofstream outputFile3("DNA10000?"+ std::to_string(count) +".csv");
        outputFile3 << "Количество ?:" << count << "\n";
        getData(algorithms, names, text, substring, outputFile3);
        outputFile3.close();
        text = textDNA(100000);
        substring = getSubstring(text);
        std::ofstream outputFile4("DNA100000?"+ std::to_string(count) +".csv");
        outputFile4 << "Количество ?:" << count << "\n";
        getData(algorithms, names, text, substring, outputFile4);
        outputFile4.close();
    }
}


void
getData( std::vector<Algorithm>& algorithms, std::vector<std::string> names, std::string &text, std::vector<std::string> &substring,
        std::ofstream &outputFile1) {
    outputFile1 << "Название алгоритма";
    for (int i = 100; i <= 3000; i += 100) {
        outputFile1 << ";" << i;
    }
    outputFile1 << std::endl;
    for (int i = 0; i < names.size(); i++) {
        outputFile1 << names[i];
        for (int n = 0; n <= 29; n++) {
            long long int duration = 0;
            for (int k = 0; k < 20; k++) {
                duration += time(text, substring[n], algorithms[i]);
            }
            outputFile1 << ";" << duration / 20;
        }
        outputFile1 << std::endl;
    }
}

int main() {
    std::vector<Algorithm> algorithms = {native, kmp, kmpBest, rabinKarp};
    std::vector<std::string> names  =  {"Наивный", "КМП со стандартными гранями", "КМП с уточненными гранями", "Алгоритм Рабина-Карпа"};
    dataWith(algorithms, names);
    dataWithout(algorithms, names);
    return 0;
}
