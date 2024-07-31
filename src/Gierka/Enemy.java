package Gierka;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Enemy extends JLabel{
    ImageIcon alien;
    int Velocity = 5, x_position = 0;
    public Enemy(){
        setSize(90, 90);
        resizeImages();
        setIcon(alien);
    }
    private void resizeImages(){
        alien = new ImageIcon(new ImageIcon("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Grafiki\\enemy.png").getImage().getScaledInstance(90, 90, Image.SCALE_DEFAULT));
    }
    public int getVelocity() {
        return Velocity;
    }

    public int getX_position() {
        return x_position;
    }
    public ImageIcon getAlien() {
        return alien;
    }
}
