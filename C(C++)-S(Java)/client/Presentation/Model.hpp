/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.hpp
 * Author: nesrine
 *
 * Created on October 23, 2018, 7:11 PM
 */

#ifndef MODEL_HPP
#define MODEL_HPP
#include <bits/stdc++.h>

using namespace std;

class Model {
public:
    Model();
    Model(const Model& orig);
    virtual ~Model();
    char* GetDisplayedString();
    void SetDisplayedString(char* displayedString);
    char GetNextChar();
    void SetNextChar(char nextChar);

private:
    char nextChar;
    char* displayedString;

};

#endif /* MODEL_HPP */

