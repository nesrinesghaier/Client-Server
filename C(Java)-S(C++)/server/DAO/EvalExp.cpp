/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EvalExp.cpp
 * Author: nesrine
 * 
 * Created on November 22, 2018, 12:54 AM
 */

#include "EvalExp.hpp"

EvalExp::EvalExp() {
}

EvalExp::EvalExp(const EvalExp& orig) {
}

EvalExp::~EvalExp() {
}

int expression();

char EvalExp::Peek() {
    return *expressionToParse;
}

char EvalExp::Get() {
    return *expressionToParse++;
}

int EvalExp::Number() {
    int result = Get() - '0';
    while (Peek() >= '0' && Peek() <= '9') {
        result = 10 * result + Get() - '0';
    }
    return result;
}

int EvalExp::Factor() {
    if (Peek() >= '0' && Peek() <= '9')
        return Number();
    else if (Peek() == '(') {
        Get(); // '('
        int result = EvalResult();
        Get(); // ')'
        return result;
    } else if (Peek() == '-') {
        Get();
        return -Factor();
    }
    return 0; // error
}

int EvalExp::Term() {
    int result = Factor();
    while (Peek() == '*' || Peek() == '/')
        if (Get() == '*')
            result *= Factor();
        else
            result /= Factor();
    return result;
}

int EvalExp::EvalResult() {
    int result = Term();
    while (Peek() == '+' || Peek() == '-')
        if (Get() == '+')
            result += Term();
        else
            result -= Term();
    return result;
}
