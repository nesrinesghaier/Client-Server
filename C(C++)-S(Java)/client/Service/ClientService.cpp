/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientService.cpp
 * Author: nesrine
 * 
 * Created on November 1, 2018, 10:24 PM
 */

#include "ClientService.hpp"

ClientService::ClientService() {
    dao = new TCPClientDAO();
}

ClientService::ClientService(const ClientService& orig) {
}

ClientService::~ClientService() {
}

char* ClientService::AddChar(char nextChar) {
    dao->SendToServer(nextChar);
    char* read = dao->ReadFromServer();
    return read;
}

ClientDAO* ClientService::GetDao() {
    return dao;
}

void ClientService::SetDao(ClientDAO* dao) {
    this->dao = dao;
}

void ClientService::Close() {
    dao->CloseSocket();
}


