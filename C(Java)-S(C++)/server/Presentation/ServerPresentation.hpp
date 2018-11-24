/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerPresentation.hpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 3:37 PM
 */

#ifndef SERVERPRESENTATION_HPP
#define SERVERPRESENTATION_HPP
#include "../Service/ServerService.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class ServerPresentation {
public:
    ServerPresentation();
    ServerPresentation(const ServerPresentation& orig);
    virtual ~ServerPresentation();
    void Display();
    ServerService* GetService();
    void SetService(ServerService* service);
private:
    ServerService* service;
};

#endif /* SERVERPRESENTATION_HPP */

