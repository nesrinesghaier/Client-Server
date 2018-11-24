/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServerDAOObserver.hpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 3:41 PM
 */

#ifndef SERVERDAOOBSERVER_HPP
#define SERVERDAOOBSERVER_HPP
#include <string>

using namespace std;


class ServerDAOObserver {
public:
    ServerDAOObserver();
    ServerDAOObserver(const ServerDAOObserver& orig);
    virtual ~ServerDAOObserver();
    virtual char* OnNewChar(char c)=0 ;
    virtual void EmptyExp()=0 ;

};

#endif /* SERVERDAOOBSERVER_HPP */

