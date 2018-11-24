/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerService.hpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 3:36 PM
 */

#ifndef SERVERSERVICE_HPP
#define SERVERSERVICE_HPP

#include <string>
#include "../DAO/ServerDAOObserver.hpp"
#include "../DAO/ServerDAO.hpp"
#include "../DAO/EvalExp.hpp"
using namespace std;

class ServerService : public ServerDAOObserver {
public:
    ServerService();
    ServerService(const ServerService& orig);
    virtual ~ServerService();
    char* OnNewChar(char c) override;
    bool isDigit(char c);
    bool isOperator(char c);
    void SetSb(char* c);
    char* GetSb();
    ServerDAO* GetDao();
    void SetDao(ServerDAO* dao);
    void EmptyExp() override;
private:
    char* sb;
    ServerDAO* dao;
    int index = 0;
    void Init();

};

#endif /* SERVERSERVICE_HPP */

