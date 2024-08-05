package Gierka;

import javax.swing.*;


public class Gra extends JFrame{
    static Panel panel;
    public Gra() {
        setTitle("Gra");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 800);
        setLayout(null);
        setResizable(false);
        setLocationRelativeTo(null);
        panel = new Panel();

        add(panel);
        setVisible(true);
    }
    public static Panel getPanel() {
        return panel;
    }
}
