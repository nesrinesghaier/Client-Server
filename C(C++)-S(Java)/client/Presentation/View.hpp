/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   View.hpp
 * Author: nesrine
 *
 * Created on October 23, 2018, 7:06 PM
 */

#ifndef VIEW_HPP
#define VIEW_HPP

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "Model.hpp"
#include "Controller.hpp"
class Controller;
class Model;

class View {
public:
    View();
    View(const View& orig);
    virtual ~View();
    void Display();
    void Show();
    Model* GetModel();
    void SetModel(Model* model);
    Controller* GetController();
    void SetController(Controller* controller);


private:
    Model* model;
    Controller* controller;

};

#endif /* VIEW_HPP */

