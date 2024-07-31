package Gierka;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import Gierka.Plane;

public class Laser extends JLabel implements ActionListener {
    int width = 10, height = 10;
    Timer timer;
    boolean move_up = false;
    public Laser() {
        setSize(width, height);
        setBackground(Color.CYAN);
        setVisible(true);
        setOpaque(true);

        timer = new Timer(10, this);
        timer.start();

    }
    public void actionPerformed(ActionEvent e){
        if(this.getY() + 10 > Panel.getBounds_frame() + 10){
            move_up = true;
        }
        if(this.getY() + 10 < Panel.getBounds_frame() + 10){
            move_up = false;
        }
        if(move_up){
            setLocation(getLocation().x,getLocation().y - 5);
        }
        if (!move_up){
            setLocation(0, 0);
            setVisible(false);
        }
    }
}
