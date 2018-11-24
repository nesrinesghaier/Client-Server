/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: nesrine
 * 
 * Created on October 23, 2018, 7:16 PM
 */

#include "Controller.hpp"

#include <string>

using namespace std;

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

ClientService* Controller::GetClientService() {
    return clientService;
}

void Controller::SetClientService(ClientService* clientService) {
    this->clientService = clientService;
}

Model* Controller::GetModel() {
    return model;
}

void Controller::SetModel(Model* model) {
    this->model = model;
}

void Controller::onNewModelUpload(char c) {
    model->SetNextChar(c);
    char* newStringToDisplay = clientService->AddChar(model->GetNextChar());
    model->SetDisplayedString(newStringToDisplay);
    view->Display();
}

View* Controller::GetView() {
    return view;
}

void Controller::SetView(View* view) {
    this->view = view;
}

void Controller::Close() {
    clientService->Close();
}
