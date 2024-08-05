package Gierka;

import javax.swing.*;
import java.awt.*;


public class Panel extends JPanel{

    public static JProgressBar progressBar;
    static Plane plane;
    static Enemy enemy;
    static int bounds_frame = 10;


    public static Plane getPlane() {
        return plane;
    }
    public static int getBounds_frame() {
        return bounds_frame;
    }
    Panel() {
        setSize(800, 800);
        setLayout(null);
        setBackground(new Color(50, 50, 50));

        plane = new Plane();
        plane.setBounds(400, 200, 100, 200);

//        progressBar = new JProgressBar();
//        progressBar.setForeground(Color.GREEN);
//        progressBar.setBackground(Color.WHITE);
//        progressBar.setMaximum(Enemy.getLive_points());
//        progressBar.setOpaque(true);
//        progressBar.setBounds(0,0, 800, 30);
//        progressBar.setValue(Enemy.getLive_points());
        progressBar = new ProgresBar();
        progressBar.setBounds(0, 0, 800, 30);

        enemy = new Enemy();
        enemy.setBounds(0, 100, 90, 90);
        enemy.setLocation(0, 100);

        add(plane);
        add(enemy);
        add(progressBar);

    }
    public int gamewon(){
        removeAll();
        System.out.println("Zwycieztwo!");
        repaint();
        return 1;
    }

}

