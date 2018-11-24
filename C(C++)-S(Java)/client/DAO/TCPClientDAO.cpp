/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPClient.cpp
 * Author: nesrine
 * 
 * Created on October 19, 2018, 11:46 PM
 */

#include "TCPClientDAO.hpp"
#define portno 8000
#include <unistd.h>

TCPClientDAO::TCPClientDAO() {
    // creation de la socket de type TCP/IP
    try {
        struct sockaddr_in serv_addr; //l'addresse OSI4 du serveur (d'ecoute)
        this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (this->sockfd < 0) {
            error("ERROR opening socket");
        }
        bzero((char *) &serv_addr, sizeof (serv_addr));
        serv_addr.sin_family = AF_INET; //definition du domaine de la socket ici TCP/IP
        serv_addr.sin_port = htons(portno); //defintion du port d'ecoute
        serv_addr.sin_addr.s_addr = INADDR_ANY; //definition de l'adresse d'ecoute ici toutes les adresses locales

        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
            error("ERROR connecting");
        }
        bzero(this->buffer, 256);

    } catch (exception& e) {
        cout << "error" << endl;
    }
}

TCPClientDAO::TCPClientDAO(const TCPClientDAO& orig) {
}

TCPClientDAO::~TCPClientDAO() {
}

void TCPClientDAO::error(const char* msg) {
    perror(msg);
    exit(1);
}

char* TCPClientDAO::ReadFromServer() {
    bzero(this->buffer, 255);
    try {
        int n = read(this->sockfd, this->buffer, 255);
        if (n < 0) {
            error("ERROR reading from socket");
        }
    } catch (exception& e) {
        error("Illegal Argument Exception");
    }
    return buffer;
}

void TCPClientDAO::SendToServer(char c) {
    this->buffer[0] = c;
    int n = write(this->sockfd, this->buffer, 1);
}

void TCPClientDAO::CloseSocket() {
    close(sockfd);
}


