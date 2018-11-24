/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.server;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author vpc
 */
public class ServerDAO {

    private ServerDAOObserver observer;

    public ServerDAOObserver getObserver() {
        return observer;
    }

    public void setObserver(ServerDAOObserver observer) {
        this.observer = observer;
    }

    public void startServer() {
        try {
            ServerSocket ss = new ServerSocket(
                    7997,//bind port
                    10, //listen queue size
                    InetAddress.getByName("localhost")
            );
            while (true) {
                Socket s = ss.accept();
                processSocket(s);
            }

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void processSocket(Socket s) {
        try {
            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            while (true) {
                char c = in.readChar();
                String r = observer.onNewChar(c);
                out.writeUTF(r);
            }

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

}
