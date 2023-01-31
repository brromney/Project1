//
// Created by blake on 1/24/2023.
//

#pragma once
#include "iostream"
#include "Token.h"
#include "cctype"
extern bool loopLine;
using namespace std;

class Scanner {
private:
    string input;
    TokenType type;
    int line;
    string value;
    int currLine = 1;

public:
    Scanner(const string &input) : input(input) {}
    Token scanToken();
};