/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientService.hpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 10:24 PM
 */

#ifndef CLIENTSERVICE_HPP
#define CLIENTSERVICE_HPP
#include "../DAO/ClientDAO.hpp"
#include "../DAO/TCPClientDAO.hpp"

#include <string>

using namespace std;

class ClientService {
public:
    ClientService();
    ClientService(const ClientService& orig);
    char* AddChar(char nextChar);
    virtual ~ClientService();
    ClientDAO* GetDao();
    void SetDao(ClientDAO* dao);
    void Close();

private:
    ClientDAO* dao;

};

#endif /* CLIENTSERVICE_HPP */

