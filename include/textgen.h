// Copyright 2021 GHA Test Team
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <deque>
#include <fstream>

using std::deque;
using std::map;
using std::vector;
using std::string;
using std::ifstream;
using std::cout;

const int NPREF = 2;
const int MAXGEN = 1000;

typedef deque<string> prefix;
typedef vector<string> suffix;

class MarkovChain {
 private:
        map<prefix, suffix> statetab;

        vector<string> ReadFile(string path);
 public:
        explicit MarkovChain(string path);

        vector<string> Generator(int maxLength);
        map<prefix, suffix> Get_statetab();
};


