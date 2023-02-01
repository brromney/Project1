#include <iostream>
#include <fstream>
#include "Scanner.h"
using namespace std;

int main() {
    ifstream infile("C:/Users/blake/Documents/BYU/CS236/Project 1/noErrors.txt");
    string fileString;
    string fileContent;
    int tokenCounter;
    if(!infile.is_open()){
        cerr << "Could not open/find file" << endl;
    }
    else if(infile.is_open()){
        while(getline(infile, fileString)){
            //cout << fileString << endl;
            fileContent += fileString + "\n";
        }
        cout << fileContent << endl;
        infile.close();
        Scanner s = Scanner(fileContent);
        while(loopLine) {
            Token t = s.scanToken();
            cout << t.typeName() << endl;
            tokenCounter++;
        }
    }
    cout << "Total Tokens = " << tokenCounter - 1;
}