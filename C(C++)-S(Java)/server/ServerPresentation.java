/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.server;

/**
 *
 * @author vpc
 */
public class ServerPresentation {
    public static void main(String[] args) {
        ServerPresentation p = new ServerPresentation();
        p.display();
    }

    private void display() {
        System.out.println("Le serveur vient de demarrer. chouette....");
        ServerService s=new ServerService();
        s.run();
    }
}
