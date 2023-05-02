// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/MCHeader.h"
#include "../src/MarkovChain.cpp"

TEST(prefixCheck, test1) {
    MarkovChain chain = MarkovChain("input.txt");
    prefix prefixTest = chain.Get_statetab().begin()->first;
    EXPECT_EQ(prefixTest.size(), NPREF);
}

TEST(prefixCheck, test2) {
    MarkovChain chain = MarkovChain("input.txt");
    prefix prefixTest = prefix();
    prefixTest.push_back("С");
    prefixTest.push_back("непростою");
    EXPECT_TRUE(!chain.Get_statetab().find(prefixTest)->second.empty());
}

TEST(suffixCheck, test3) {
    MarkovChain chain = MarkovChain("input.txt");
    prefix prefixTest = prefix();
    prefixTest.push_back("Старик");
    prefixTest.push_back("ловил");
    suffix suf = chain.Get_statetab().find(prefixTest)->second;
    suffix expectedSuf = suffix();
    expectedSuf.push_back("неводом");
    EXPECT_EQ(suf, expectedSuf);
}

TEST(suffixCheck, test4) {
    MarkovChain chain = MarkovChain("input.txt");
    prefix prefixTest = prefix();
    prefixTest.push_back("Так");
    prefixTest.push_back("и");
    suffix suf = chain.Get_statetab().find(prefixTest)->second;
    suffix expectedSuf = suffix();
    expectedSuf.push_back("быть");
    expectedSuf.push_back("вздулись");
    expectedSuf.push_back("ходят");
    EXPECT_EQ(suf, expectedSuf);
}

TEST(generatorCheck, test5) {
    MarkovChain chain = MarkovChain("input.txt");
    vector<string> genText = chain.Generator(100);
    EXPECT_EQ(genText.size(), 100);
}
