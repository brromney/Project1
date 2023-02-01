//
// Created by blake on 1/30/2023.
//
#pragma once
#include "Scanner.h"


bool loopLine = true;
Token Scanner::scanToken() {
    if(input.empty()){
        type = ENDOFFILE;
        value = "";
        line = currLine;
        loopLine = false;
    }
    while(!input.empty()) {
        while (isspace(input.front())) {
            if(input.front() == '\n'){
                currLine++;
            }
            input = input.substr(1);
        }
        if(input.empty()){
            type = ENDOFFILE;
            value = "";
            line = currLine;
            loopLine = false;
        }
        else if (input.front() == ',') {
            type = COMMA;
            value = ",";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == '.') {
            type =  PERIOD;
            value = ".";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == '?') {
            type = Q_MARK;
            value = "?";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == '(') {
            type = LEFT_PAREN;
            value = "(";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == ')') {
            type = RIGHT_PAREN;
            value = ")";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == ':' && input[1] == '-') {
            type = COLON_DASH;
            value = ":-";
            line = currLine;
            input = input.substr(2);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == ':') {
            type = COLON;
            value = ":";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == '*') {
            type = MULTIPLY;
            value = "*";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (input.front() == '+') {
            type = ADD;
            value = "+";
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else if (((input.front() >= 'A') && (input.front() <= 'Z')) || ((input.front() >= 'a') && (input.front() <= 'z')) || (input.front() == '\'')){
            if (input.front() == 'S' && input[1] == 'c' && input[2] == 'h' && input[3] == 'e' && input[4] == 'm' && input[5] == 'e' && input[6] == 's') {
                type = SCHEMES;
                value = "Schemes";
                line = currLine;
                input = input.substr(7);
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
            else if (input.front() == 'F' && input[1] == 'a' && input[2] == 'c' && input[3] == 't' && input[4] == 's' && (input[5] == ' ' || input[5] == ':'|| input[5] == '\n')) {
                type = FACTS;
                value = "Facts";
                line = currLine;
                input = input.substr(5);
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
            else if (input.front() == 'Q' && input[1] == 'u' && input[2] == 'e' && input[3] == 'r' && input[4] == 'i' && input[5] == 'e' && input[6] == 's') {
                type = QUERIES;
                value = "Queries";
                line = currLine;
                input = input.substr(7);
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
            else if (input.front() == 'R' && input[1] == 'u' && input[2] == 'l' && input[3] == 'e' && input[4] == 's') {
                type = RULES;
                value = "Rules";
                line = currLine;
                input = input.substr(5);
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
            else if (input.front() == '\'') {
                int i = 1;//STRING
                string outString;
                do {
                    if(input.front() == '\n'){
                        outString += "\\n";
                        i++;
                        input = input.substr(1);
                        if(input.front() == '\000'){break;}
                        continue;
                    }
                    outString += input.front();
                    i++;
                    input = input.substr(1);
                    if(input.front() == '\000'){break;}
                    if(input.front() == '\''){outString += input.front();}
                } while (input.front() != '\'');
                if(input.front() == '\''){input = input.substr(1);}
                if(input.empty()){
                    type = UNDEFINED;
                    value = outString;
                    line = currLine;
                    input = input.substr(input.length());
                    if(input.empty()){loopLine = false;}
                    return Token(type, value, line);
                }
                type = STRING;
                value = outString;
                line = currLine;
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
            else {
                int i = 0;
                string outID;
                while((input[i] != ' ' ) && (input[i] != '\n' ) && (input[i] != '\t' ) && (input[i] != ',' ) && (input[i] != '.' ) && (input[i] != '?' ) && (input[i] != '(' ) && (input[i] != ')' ) && (input[i] != ':' )&& (input[i] != '*' ) && (input[i] != '+' ) && (input[i] != '#' )) {
                    if (!isspace(input[i])) {
                        outID += input[i];
                        i++;
                    }
                }
                type = ID;
                value = outID;
                line = currLine;
                input = input.substr(i);
                if(input.empty()){loopLine = false;}
                return Token(type, value, line);
            }
        }
        else if (input.front() == '#') {
            int i = 0;
            string outString;
            while(input[i] != '\n'){
                outString += input[i];
                i++;
            }
            type = COMMENT;
            value = outString;
            line = currLine;
            input = input.substr(i);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
        else {
            type = UNDEFINED;
            value = input.front();
            line = currLine;
            input = input.substr(1);
            if(input.empty()){loopLine = false;}
            return Token(type, value, line);
        }
    }
    return Token(type,value, line);
}

