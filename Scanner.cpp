//
// Created by blake on 1/30/2023.
//
#pragma once
#include "Scanner.h"
bool loopLine = true;
Token Scanner::scanToken() {
    //if(input.empty()){
    //    loopLine = false;
    //}
    type = ENDOFFILE;
    value = "EOF";
    line = currLine;
    input = input;
    while(!input.empty()) {
        while (isspace(input.front())) {
            input = input.substr(1);
        }
        if ((input.front() =='\n') || (input.front() =='\t') || (input.front() ==' ') || (input.empty())) {
            loopLine = false;
            break;
        }
        else if (input.front() == ',') {
            type = COMMA;
            value = ",";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == '.') {
            type =  PERIOD;
            value = ".";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == '?') {
            type = Q_MARK;
            value = "?";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == '(') {
            type = LEFT_PAREN;
            value = "(";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == ')') {
            type = RIGHT_PAREN;
            value = ")";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == ':' && input[1] == '-') {
            type = COLON_DASH;
            value = ":-";
            line = currLine;
            input = input.substr(2);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == ':') {
            type = COLON;
            value = ":";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == '*') {
            type = MULTIPLY;
            value = "*";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == '+') {
            type = ADD;
            value = "+";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == 'S' && input[1] == 'c' && input[2] == 'h' && input[3] == 'e' && input[4] == 'm' && input[5] == 'e' && input[6] == 's') {
            type = SCHEMES;
            value = "SCHEMES";
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == 'F' && input[1] == 'a' && input[2] == 'c' && input[3] == 't' && input[4] == 's' && (input[5] == ' ' || input[5] == ':'|| input[5] == '\n')) {
            type = FACTS;
            value = "FACTS";
            line = currLine;
            input = input.substr(5);
            if(input.empty()){loopLine = false;}
            break;
        }
        else if (input.front() == 'Q' && input[1] == 'u' && input[2] == 'e' && input[3] == 'r' && input[4] == 'i' && input[5] == 'e' && input[6] == 's') {
            type = QUERIES;
            value = "QUERIES";
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }

        else if (input.front() == '#') {
            type = COMMENT;
            value = input; //TODO print whole line
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }
        else if ((input.front() && input[(input.length() - 1)] == '\'') || (input.front() && input[(input.length() - 1)] == '"') && (input.front() == input[input.length()-1])) {
            type = STRING;
            value = input;
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }
        else if ((input.front() && input[(input.length() - 1)] != '\'') && (input.front() && input[(input.length() - 1)] != '"')) {
            type = ID;
            value = input;
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }
        /*else if (input.empty()) { //fixme
            type = ENDOFFILE;
            value = "EOF";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            break;
        }*/
        else {
            type = UNDEFINED;
            value = input;
            line = currLine;
            input = input.substr(input.length());
            if(input.empty()){loopLine = false;}
            break;
        }
    }
    return Token(type, value, line);
}
