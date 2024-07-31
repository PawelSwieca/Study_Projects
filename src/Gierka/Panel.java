package Gierka;

import javax.swing.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Panel extends JPanel implements ActionListener {
    Timer timer;
    static Plane plane;
    static Enemy enemy;
    static int bounds_frame = 10;
    boolean move;
    int Velocity = 5, x_position = 0;

    public static Plane getPlane() {
        return plane;
    }
    public static Enemy getEnemy() {
        return enemy;
    }
    public static int getBounds_frame() {
        return bounds_frame;
    }
    Panel(){
        setSize(800, 800);
        setLayout(null);
        setBackground(new Color(50, 50, 50));
        enemy = new Enemy();
        enemy.setBounds(0, 0, 90, 90);

        plane = new Plane();
        plane.setBounds(400, 200, 100, 200);

        timer = new Timer(10, this);
        timer.start();

        add(plane);
        add(enemy);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (x_position > getWidth() - getBounds_frame() - enemy.getWidth()) {
            move = true;
        }
        if (x_position < 0) {
            move = false;
        }
        if (move) {
            x_position -= Velocity;
            enemy.setLocation(x_position, 0);

        } else {
            x_position += Velocity;
            enemy.setLocation(x_position, 0);
        }
        repaint();
    }
}
