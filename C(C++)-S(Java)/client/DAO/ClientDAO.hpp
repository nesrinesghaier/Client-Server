/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientDAO.hpp
 * Author: nesrine
 *
 * Created on October 23, 2018, 7:33 PM
 */

#ifndef CLIENTDAO_HPP
#define CLIENTDAO_HPP
#include <string>
using namespace std;

class ClientDAO {
public:
    ClientDAO();
    ClientDAO(const ClientDAO& orig);
    virtual ~ClientDAO();
    virtual char* ReadFromServer()=0;
    virtual void SendToServer(char c)=0;
    virtual void CloseSocket()=0;

};

#endif /* CLIENTDAO_HPP */

