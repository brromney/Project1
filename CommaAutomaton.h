//
// Created by blake on 1/24/2023.
//

#pragma once
#include <iostream>
using namespace std;

class commaAuto {
private:
    void s1(string input) {
        return;
    }
    void serr() {
        return;
    }
    void s0(string input) {
        if (input.front() == ','){
            s1(input);
        }
        else{
            serr();
        }
    }
public:
    void start(string input){
        s0(input);
        return;
    }
};