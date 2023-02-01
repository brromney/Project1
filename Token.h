#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

enum TokenType {
    COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON_DASH, COLON, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, ENDOFFILE
};

class Token{
private:
    TokenType type;
    string value;
    int line;
public:
    Token(TokenType type, const string &value, int line) : type(type), value(value), line(line) {}

    string typeName() const{

        stringstream out;
        string strToPrint;
        if(type == COMMA){
            strToPrint = "COMMA";
        }
        else if (type == PERIOD){
            strToPrint = "PERIOD";
        }
        else if (type == Q_MARK){
            strToPrint = "Q_MARK";
        }
        else if (type == LEFT_PAREN){
            strToPrint = "LEFT_PAREN";
        }
        else if (type == RIGHT_PAREN){
            strToPrint = "RIGHT_PAREN";
        }
        else if (type == COLON_DASH){
            strToPrint = "COLON_DASH";
        }
        else if (type == COLON){
            strToPrint = "COLON";
        }
        else if (type == MULTIPLY){
            strToPrint = "MULTIPLY";
        }
        else if (type == ADD){
            strToPrint = "ADD";
        }
        else if (type == SCHEMES){
            strToPrint = "SCHEMES";
        }
        else if (type == FACTS){
            strToPrint = "FACTS";
        }
        else if (type == RULES){
            strToPrint = "RULES";
        }
        else if (type == QUERIES){
            strToPrint = "QUERIES";
        }
        else if (type == ID){
            strToPrint = "ID";
        }
        else if (type == STRING){
            strToPrint = "STRING";
        }
        else if (type == COMMENT){
            strToPrint = "COMMENT";
        }
        else if (type == UNDEFINED){
            strToPrint = "UNDEFINED";
        }
        else if (type == ENDOFFILE){
            strToPrint = "EOF";
        }
        out << "(" << strToPrint << "," << "\""<< value << "\"" << "," << line << ")";
        return out.str();
    }
};