#include <iostream>
#include <fstream>
#include <sstream>
#include "Scanner.h"
using namespace std;

int main() {
    ifstream infile;
    infile.open(R"(C:\Users\blake\Documents\BYU\CS236\Project 1\noErrors.txt)");
    string fileLine;
    string fileContents;
    if(!infile.is_open()){
        cerr << "Could not open/find file" << endl;
    }
    else if(infile.is_open()){
        ostringstream ss;
        while(!infile.eof()){
            getline(infile, fileLine);
            cout << fileLine << endl;
            file

            Scanner s = Scanner(fileContents);
            while(loopLine) {
                Token t = s.scanToken();
                cout << t.typeName() << endl;
            }
            loopLine = true;
        }
        infile.close();
    }
}
