/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 3:34 PM
 */

#include <cstdlib>
#include "Presentation/ServerPresentation.hpp"
#include "Service/ServerService.hpp"
#include "DAO/ServerDAO.hpp"
#include <stdio.h>

using namespace std;
class ServerDAO;
class ServerService;

/*
 * 
 */
int main(int argc, char** argv) {
    ServerPresentation presentation;
    ServerDAO dao;
    ServerService service;
    presentation.SetService(&service);
    dao.SetObserver(&service);
    service.SetDao(&dao);
    presentation.Display();
    return 0;
}

