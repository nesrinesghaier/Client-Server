/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerDAO.cpp
 * Author: nesrine
 * 
 * Created on November 1, 2018, 3:36 PM
 */

#include <iostream>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <exception>
#include <unistd.h>
#include <string>
#include<cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ServerDAO.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define portno 8000

ServerDAO::ServerDAO() {
}

ServerDAO::ServerDAO(const ServerDAO& orig) {
}

ServerDAO::~ServerDAO() {
}

ServerDAOObserver* ServerDAO::GetObserver() {
    return observer;
}
void dostuff(int);

void ServerDAO::SetObserver(ServerDAOObserver* observer) {
    this->observer = observer;
}

void ServerDAO::StartServer() {
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error(ANSI_COLOR_RED"ERROR opening socket");
        //exit();
    }
    bzero((char *) &serv_addr, sizeof (serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr*) &serv_addr, sizeof (serv_addr)) < 0) {
        error(ANSI_COLOR_RED"ERROR on binding");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        error(ANSI_COLOR_RED"Listen Failed");
    }
    while (true) {
        bzero(buffer, 1024);
        printf(ANSI_COLOR_BLUE"waiting for client connection on port TCP %d\n", portno);
        cli_len = sizeof (cli_addr);
        new_socket = accept(server_fd, (struct sockaddr*) &cli_addr, (socklen_t*) & cli_len);
        if (new_socket < 0) {
            error(ANSI_COLOR_RED"ERROR on accept");
        }
        printf(ANSI_COLOR_GREEN"received connection from host [IP %s ,TCP port %d]\n",
                inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        while (true) {
            bzero(buffer, 1024);
            int msg = read(new_socket, buffer, 1024);
            if (msg == -1) {
                return;
            }
            if (buffer[0]>'9') {
                printf(ANSI_COLOR_RED"Client/Server Application exited\n");
                break;
            }
            printf("received from host [IP %s ,TCP port %d] : %c\n",
                    inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buffer[0]);
            char received = buffer[0];
            char* rslt = GetObserver()->OnNewChar(received);
            strcpy(buffer, rslt);
            if (IsEquals(received)) {
                char* message = "The result equals : ";
                memset(line, 0x0, 1024);
                strcpy(line, message);
                strcat(line, buffer);
                strcat(line, "\n");
                write(new_socket, line, strlen(line));
                GetObserver()->EmptyExp();
            } else {

                strcat(buffer, "\n");
                write(new_socket, buffer, strlen(buffer));
            }
        }
        close(new_socket);

    }
}

void ServerDAO::dostuff(int socket) {
    while (true) {
        msg = read(socket, buffer, 1024);

        if (!msg) return;
        char c = buffer[0];
        strcpy(buffer, observer->OnNewChar(c));
    }
}

void ServerDAO::ProcessSocket(int sock) {
    int n = 0;
    if (n < 0) {

        error("ERROR writing to socket");
    }
}

void ServerDAO::error(char* msg) {

    perror(msg);
    exit(1);
}

bool ServerDAO::IsEquals(char c) {
    if (c == '=') {
        return true;
    }
    return false;
}

