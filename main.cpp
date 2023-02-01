#include <iostream>
#include <fstream>
#include "Scanner.h"
using namespace std;

int main(/*int argc, char *argv[]*/) {
    bool loopLine;
    ifstream infile(/*argv[1]*/"C:/Users/blake/Documents/BYU/CS236/Project 1/noErrors.txt");
    string fileString;
    string fileContent;
    int tokenCounter = 0;
    if(!infile.is_open()){
        cerr << "Could not open/find file" << endl;
    }
    else if(infile.is_open()){
        while(getline(infile, fileString)){
            //cout << fileString << endl;
            fileContent += fileString + "\n";
        }
       //cout << fileContent << endl;
        infile.close();
        Scanner s = Scanner(fileContent);
        while(loopLine) {
            Token t = s.scanToken();
            cout << t.typeName() << endl;
            tokenCounter++;
        }
    }
    cout << "Total Tokens = " << tokenCounter;
}