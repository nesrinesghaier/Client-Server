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
public abstract class ClientDAO {

    public ClientDAO() {
    }

    public abstract void sendToServer(char nextChar);

    public abstract String readFromServer();

}
