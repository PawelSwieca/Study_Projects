package Gierka;

import javax.swing.*;
import java.awt.*;
import Actions.*;

public class Gra extends JFrame{
    Action leftAction, rightAction, upAction, downAction;
    ImageIcon rocket, alien;

    public static Plane getPlane() {
        return plane;
    }

    static Plane plane;
    //static JLabel plane;
    JLabel enemy;
    public Gra() {
        setTitle("Gra");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 800);
        setLocationRelativeTo(null);
        setLayout(null);
        setResizable(false);
        getContentPane().setBackground(new Color(50, 50, 50));
        resizeImages();

        enemy = new JLabel();
        enemy.setSize(90, 90);
        enemy.setIcon(alien);
        enemy.setBounds(0, 0, 90, 90);

        plane = new Plane();
        plane.setBounds(400, 200, 100, 200);


        add(plane);
        add(enemy);

        setVisible(true);
    }

    private void resizeImages(){
        alien = new ImageIcon(new ImageIcon("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Grafiki\\enemy.png").getImage().getScaledInstance(90, 90, Image.SCALE_DEFAULT));
        rocket = new ImageIcon(new ImageIcon("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Grafiki\\rocket.png").getImage().getScaledInstance(100, 200, Image.SCALE_DEFAULT));
    }
}
