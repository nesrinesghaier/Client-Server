/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.hpp
 * Author: nesrine
 *
 * Created on October 23, 2018, 7:16 PM
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include"View.hpp"
#include "Model.hpp"
#include "../Service/ClientService.hpp"
class Model;
class View;
class Controller {
public:
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
    void onNewModelUpload(char c);
    ClientService* GetClientService();
    Model* GetModel();
    View* GetView();
    void SetClientService(ClientService* clientService);
    void SetModel(Model* model);
    void SetView(View* view);
    void Close();
private:
    ClientService* clientService;
    Model* model;
    View* view;
};

#endif /* CONTROLLER_HPP */

