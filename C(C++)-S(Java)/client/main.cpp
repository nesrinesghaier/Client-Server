/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nesrine
 *
 * Created on November 1, 2018, 2:10 PM
 */
#include "Presentation/View.hpp"
#include "Presentation/Model.hpp"
#include "Service/ClientService.hpp"
#include "DAO/TCPClientDAO.hpp"
#include "Presentation/Controller.hpp"

using namespace std;

/*
 * 
 */

int main(int argc, char *argv[]) {
    View v;
    Model m;
    Controller c;
    TCPClientDAO dao;
    ClientService cs;
    cs.SetDao(&dao);
    v.SetModel(&m);
    v.SetController(&c);
    c.SetView(&v);
    c.SetModel(&m);
    c.SetClientService(&cs);
    v.Show();
    return 0;
}
