/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.client;

/**
 *
 * @author vpc
 */
public class ClientService {

    ClientDAO d = new TCPClientDAO();
    
    String addChar(char nextChar) {
        d.sendToServer(nextChar);
        String v = d.readFromServer();
        return v;
    }

}
