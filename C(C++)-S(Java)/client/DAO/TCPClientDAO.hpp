/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPClient.hpp
 * Author: nesrine
 *
 * Created on October 19, 2018, 11:46 PM
 */

#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h> 
#include <cstring>
#include "ClientDAO.hpp"

using namespace std;

class TCPClientDAO : public ClientDAO {
public:
    TCPClientDAO();
    TCPClientDAO(const TCPClientDAO& orig);
    virtual ~TCPClientDAO();
    virtual char* ReadFromServer() override;
    virtual void SendToServer(char c) override;
    virtual void CloseSocket() override;
    void error(const char* msg);
private:
    int sockfd,readb;
    struct sockaddr_in serv_addr;
    char buffer[256];

};

#endif /* TCPCLIENT_HPP */

