/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerPresentation.cpp
 * Author: nesrine
 * 
 * Created on November 1, 2018, 3:37 PM
 */

#include <cstdio>

#include "ServerPresentation.hpp"
class ServerService;

ServerPresentation::ServerPresentation() {
}

ServerPresentation::ServerPresentation(const ServerPresentation& orig) {
}

ServerPresentation::~ServerPresentation() {
}

void ServerPresentation::Display() {
    printf(ANSI_COLOR_MAGENTA"The server started Yey...\n"ANSI_COLOR_MAGENTA);
    GetService()->GetDao()->StartServer();
}

ServerService* ServerPresentation::GetService() {
    return service;
}

void ServerPresentation::SetService(ServerService* service) {
    this->service = service;
}
