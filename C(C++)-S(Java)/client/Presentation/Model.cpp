/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.cpp
 * Author: nesrine
 * 
 * Created on October 23, 2018, 7:11 PM
 */

#include "Model.hpp"
#include <string>
#include <iostream>

using namespace std;
Model::Model() {
}

Model::Model(const Model& orig) {
}

Model::~Model() {
}

char* Model::GetDisplayedString() {
    return displayedString;
}

char Model::GetNextChar(){
    return nextChar;
}

void Model::SetDisplayedString(char* displayedString) {
    this->displayedString = displayedString;
}

void Model::SetNextChar(char nextChar) {
    this->nextChar = nextChar;
}
