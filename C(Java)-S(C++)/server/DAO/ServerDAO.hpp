/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerDAO.hpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 3:36 PM
 */

#ifndef SERVERDAO_HPP
#define SERVERDAO_HPP
#include <stdio.h>
#include "ServerDAOObserver.hpp"
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

class ServerDAO {
public:
    ServerDAO();
    ServerDAO(const ServerDAO& orig);
    virtual ~ServerDAO();
    ServerDAOObserver* GetObserver();
    void SetObserver(ServerDAOObserver* observer);
    void StartServer();
    void ProcessSocket(int sock);
    void error(char *msg);
    void dostuff(int sock);
    bool IsEquals(char c);
private:
    ServerDAOObserver* observer;
    int server_fd, new_socket, cli_len, msg;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256], line[256];
    char* message;

};

#endif /* SERVERDAO_HPP */

