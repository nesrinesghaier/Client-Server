/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package net.eniso.sockets.server;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

/**
 *
 * @author vpc
 */
public class ServerService implements ServerDAOObserver {

    private ServerDAO dao;
    StringBuilder sb = new StringBuilder();

    public void run() {
        dao = new ServerDAO();
        dao.setObserver(this);
        dao.startServer();
    }

    @Override
    public String onNewChar(char c) {
        if (c == '=') {
            ScriptEngineManager engineManager = new ScriptEngineManager();
            ScriptEngine engine = engineManager.getEngineByName("JavaScript");
            String result = sb.toString();
            try {
                return String.valueOf(engine.eval(result));
            } catch (ScriptException ex) {
                Logger.getLogger(ServerService.class.getName()).log(Level.SEVERE, null, ex);
            }
        } else if (c == '0') {
            sb = new StringBuilder();
        } else {
            sb.append(c);
        }
        return sb.toString();
    }

}
