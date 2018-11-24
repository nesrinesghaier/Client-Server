/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerService.cpp
 * Author: nesrine
 * 
 * Created on November 1, 2018, 3:36 PM
 */

#include "ServerService.hpp"
#include <bits/stdc++.h> 
#include <iostream> 
#include <vector> 

using namespace std;

std::vector<char> buffer(1024);

ServerService::ServerService() {
    sb = (char*) malloc(1024 * sizeof (char));
}

ServerService::ServerService(const ServerService& orig) {
}

ServerService::~ServerService() {
}

bool ServerService::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool ServerService::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

char* ServerService::OnNewChar(char c) {
    EvalExp evalService;
    if (isDigit(c)) {
        sb[index] = c;
        index++;
    } else if (isOperator(c)) {
        if (index == 0 || !isDigit(sb[index - 1])) {
            return sb;
        }
        sb[index] = c;
        index++;
    } else if (c == '=') {
        if (index > 0 && !isDigit(sb[index - 1])) {
            index--;
        }
        sb[index] = '\0';
        evalService.expressionToParse = sb;
        int res = evalService.EvalResult();
        //std::string s = std::to_string(res);
        //char const *pchar = s.c_str(); 
        //strcat(sb, pchar);
        sprintf(sb, "%d", res);
        Init();
    }
    return sb;
}

char* ServerService::GetSb() {
    return sb;
}

void ServerService::SetSb(char* c) {
    this->sb = c;
}

ServerDAO* ServerService::GetDao() {
    return dao;
}

void ServerService::SetDao(ServerDAO* dao) {
    this->dao = dao;
}

void ServerService::Init() {
    index = 0;
}

void ServerService::EmptyExp() {
    sb = new char[1024]();
}

