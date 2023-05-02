// Copyright 2021 GHA Test Team
#include "textgen.h"

MarkovChain::MarkovChain(string path) {
    vector<string> words = ReadFile(path);
    statetab = map<prefix, vector<string>>();

    prefix pref = prefix();

    for (int i = 0; i < NPREF; i++)
        pref.push_back(words[i]);
    for (int i = NPREF; i < words.size(); i++) {
        if (statetab.find(pref) == statetab.end())
            statetab[pref] = suffix();
        statetab[pref].push_back(words[i]);
        pref.pop_front();
        pref.push_back(words[i]);
    }
}

vector<string> MarkovChain::Generator(int maxLength) {
    vector<string> buf = vector<string>();
    prefix pref = statetab.begin()->first;
    int num;
    srand(time(NULL));

    for (int i = 0 ; i < maxLength && 
        statetab.find(pref) != statetab.end(); i++) {
        num = rand_r() % (statetab[pref].size());
        suffix bufsuf = statetab[pref];
        buf.push_back(bufsuf[num]);
        pref.pop_front();
        pref.push_back(bufsuf[num]);
    }

    return buf;
}

map<prefix, suffix> MarkovChain::Get_statetab() {
    return statetab;
}

vector<string> MarkovChain::ReadFile(string path) {
    ifstream read(path);
    string word;
    string buf;
    vector<string> words;

    while (getline(read, word)) {
        buf = "";
        for (int i = 0; ; i++) {
            if (word[i] == ' ' || word[i] == '.' || word[i] == ';' || word[i]
                == '!' || word[i] == ',' || word[i] == ':' || word[i] == '"') {
                if (buf != "") {
                    words.push_back(buf);
                    buf = "";
                }

                if (word[i] != ' ') {
                    buf += word[i];
                    words.push_back(buf);
                    buf = "";
                }
            } else {
                buf += word[i];
            }
            if (word[i] == '\0')
                break;
        }
        words.push_back("\n");
    }
    read.close();
    return words;
}
