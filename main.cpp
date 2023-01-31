#include <iostream>
#include <fstream>
#include "Scanner.h"
using namespace std;

int main() {
    ifstream infile;
    infile.open(R"(C:\Users\blake\Documents\BYU\CS236\Project 1\noErrors.txt)");
    string fileString;
    if(!infile.is_open()){
        cerr << "Could not open/find file" << endl;
    }
    else if(infile.is_open()){
        while(!infile.eof()){
            getline(infile, fileString);
            cout << fileString << endl;
            Scanner s = Scanner(fileString);
            while(loopLine) {
                Token t = s.scanToken();
                cout << t.typeName() << endl;
            }
            loopLine = true;
        }
        infile.close();
    }
}
