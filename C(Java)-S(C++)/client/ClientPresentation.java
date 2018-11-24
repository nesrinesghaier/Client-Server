/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.client;

import java.util.Scanner;

/**
 *
 * @author vpc
 */
public class ClientPresentation {

    public Model model = new Model();
    public View view = new View();
    public Controller controller = new Controller();

    public static void main(String[] args) {
        ClientPresentation c = new ClientPresentation();
        c.view.show();
    }

    public static class Model {

        public char nextChar;
        public String displayedString;
    }

    public class View {

        private void display() {
            System.out.println(model.displayedString);
        }

        public void show() {
            Scanner s = new Scanner(System.in);
            while (true) {
                String l = s.nextLine();
                if (l.length() > 0) {
                    char model = l.charAt(0);
                    controller.onNewModelUpdated(model);
                }
            }
        }
    }

    public class Controller {

        public ClientService service = new ClientService();
            
        private void onNewModelUpdated(char c) {
            //V2M : View To Model
            model.nextChar = c;
            //CB  : Call Business
            String newStringToDisplay = service.addChar(model.nextChar);
            model.displayedString = newStringToDisplay;
            //M2V : Model To View
            view.display();
        }
    }

}
