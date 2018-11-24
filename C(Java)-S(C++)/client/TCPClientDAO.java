/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.client;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.InetAddress;
import java.net.Socket;

/**
 *
 * @author vpc
 */
public class TCPClientDAO extends ClientDAO {

    private Socket socket;
    private DataInputStream in;
    private DataOutputStream out;

    public TCPClientDAO() {
        try {
            socket = new Socket(InetAddress.getByName("localhost"), 7997);
            in = new DataInputStream(socket.getInputStream());
            out = new DataOutputStream(socket.getOutputStream());
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void sendToServer(char nextChar) {
        try {
            out.writeChar(nextChar);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public String readFromServer() {
        try {
            return in.readUTF();
        } catch (Exception ex) {
            ex.printStackTrace();
            throw new IllegalArgumentException(ex);
        }
    }

}
