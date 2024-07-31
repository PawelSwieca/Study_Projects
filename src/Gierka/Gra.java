package Gierka;

import javax.swing.*;
import java.awt.*;
import Actions.*;

public class Gra extends JFrame{
//    static Plane plane;
//    static Enemy enemy;
//    static int bounds_frame = 10;
//
//    public static Plane getPlane() {
//        return plane;
//    }
//    public static Enemy getEnemy() {
//        return enemy;
//    }
//    public static int getBounds_frame() {
//        return bounds_frame;
//    }
    Panel panel;
    public Gra() {
        setTitle("Gra");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 800);
        setLocationRelativeTo(null);
        setLayout(null);
        setResizable(false);
        //getContentPane().setBackground(new Color(50, 50, 50));

//        enemy = new Enemy();
//        enemy.setBounds(0, 0, 90, 90);
//
//        plane = new Plane();
//        plane.setBounds(400, 200, 100, 200);
//
//
//        add(plane);
//        add(enemy);
        panel = new Panel();
        add(panel);
        setVisible(true);
    }
}
