package Gierka;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Enemy extends JLabel implements ActionListener {
    public static Rectangle hitbox;
    Timer timer;
    boolean move;
    static int live_points = 3;
    ImageIcon alien;
    int Velocity = 5, x_position = 0;

    public Enemy() {
        setSize(90, 90);
        resizeImages();
        setIcon(alien);
        hitbox = this.getBounds();
        timer = new Timer(10, this);
        timer.start();
    }

    private void resizeImages() {
        alien = new ImageIcon(new ImageIcon("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Grafiki\\enemy.png").getImage().getScaledInstance(90, 90, Image.SCALE_DEFAULT));
    }

    public static int getLive_points() {
        return live_points;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (x_position > 800 - Panel.getBounds_frame() - getWidth()) {
            move = true;
        }
        if (x_position < 0) {
            move = false;
        }
        if (move) {
            x_position -= Velocity;
            setLocation(x_position, 50);
            hitbox.setLocation(x_position, 50);

        } else {
            x_position += Velocity;
            setLocation(x_position, 50);
            hitbox.setLocation(x_position, 50);
        }
        if(live_points == 0) {
            timer.stop();
            setLocation(0, 0);
            hitbox.setLocation(0, 0);
            Gra.getPanel().gamewon();
        }
        repaint();
    }
}
