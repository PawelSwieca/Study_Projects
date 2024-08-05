package Gierka;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Laser extends JLabel implements ActionListener{
    static Rectangle hitlaser;
    int width = 10, height = 10, time = 10;
    Timer timer;
    boolean move_up = false;
    public Laser() {
        setSize(width, height);
        setBackground(Color.CYAN);
        setVisible(true);
        setOpaque(true);

        hitlaser = this.getBounds();

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
            hitlaser.setLocation(getLocation().x,getLocation().y - 5);
        }
        if (!move_up){
            timer.stop();
            setLocation(700, 700);
            hitlaser.setLocation(700, 700);
            setVisible(false);
            Gra.getPanel().remove(this);

        }
        if(Enemy.hitbox.intersects(hitlaser)){
            timer.stop();
            Enemy.live_points --;
            Panel.progressBar.setValue(Enemy.live_points);
            System.out.println("Hited");
            setLocation(700, 700);
            hitlaser.setLocation(700, 700);
            setVisible(false);
            Gra.getPanel().remove(this);
        }
    }
//    public void paint(Graphics g){
//        dispose();
//    }
}
