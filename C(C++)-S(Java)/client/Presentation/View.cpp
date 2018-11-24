/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.cpp
 * Author: nesrine
 * 
 * Created on October 23, 2018, 7:06 PM
 */

#include "View.hpp"

View::View() {
}

View::View(const View& orig) {
}

View::~View() {
}

void View::Display() {
    printf(ANSI_COLOR_GREEN"%s\n", this->GetModel()->GetDisplayedString());
}

Model* View::GetModel() {
    return model;
}

void View::SetModel(Model* model) {
    this->model = model;
}

Controller* View::GetController() {
    return controller;
}

void View::SetController(Controller* controller) {
    this->controller = controller;
}

void View::Show() {
    printf(ANSI_COLOR_MAGENTA"Client connected to Server\n");
    printf(ANSI_COLOR_BLUE"Please enter your message:\n");
    while (true) {
        string l;
        cin>>l;
        if (l[0] == 'e') {
            controller->onNewModelUpload('e');
            printf(ANSI_COLOR_RED"Client/Server Application exited");
            controller->Close();
            break;
        }
        if (l.length() > 0) {
            char c = l[0];
            controller->onNewModelUpload(c);
        }
    }
}
