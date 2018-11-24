/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EvalExp.hpp
 * Author: nesrine
 *
 * Created on November 22, 2018, 12:54 AM
 */

#ifndef EVALEXP_HPP
#define EVALEXP_HPP

class EvalExp {
public:
    EvalExp();
    EvalExp(const EvalExp& orig);
    virtual ~EvalExp();
    char Peek();
    char Get();
    int Number();
    int Factor();
    int Term();
    int EvalResult();
    const char * expressionToParse = "";

private:
    

};

#endif /* EVALEXP_HPP */

