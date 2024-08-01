package Gierka;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Panel extends JPanel{


    static Laser laser;
    static Plane plane;
    static Enemy enemy;
    static int bounds_frame = 10;


    public static Plane getPlane() {
        return plane;
    }

    public static Enemy getEnemy() {
        return enemy;
    }

    public static Laser getLaser() {
        return laser;
    }

    public static int getBounds_frame() {
        return bounds_frame;
    }
    public static void setLaser(Laser laser) {
        Panel.laser = laser;
    }

    Panel() {
        setSize(800, 800);
        setLayout(null);
        setBackground(new Color(50, 50, 50));
        enemy = new Enemy();
        enemy.setBounds(0, 0, 90, 90);

        plane = new Plane();
        plane.setBounds(400, 200, 100, 200);



        add(plane);
        add(enemy);
    }
}

