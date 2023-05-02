// Copyright 2021 GHA Test Team
#include "textgen.h"

int main() {
    setlocale(LC_ALL, "rus");
    MarkovChain markChain = MarkovChain("input.txt");
    vector<string> genText = markChain.Generator(MAXGEN);
    for (auto word : genText) {
        if (word != "." && word != ";" && word !=
            "!" && word != "," && word != ":")
            cout << " ";
        cout << word;
    }
    return 0;
}
