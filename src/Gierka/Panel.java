package Gierka;

import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;


public class Panel extends JPanel{

    public static JProgressBar progressBar;
    static Plane plane;
    static Enemy enemy;
    static int bounds_frame = 10;
    File file;
    Clip music;


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

        progressBar = new ProgresBar();
        progressBar.setBounds(0, 0, 800, 30);

        enemy = new Enemy();
        enemy.setBounds(0, 100, 90, 90);
        enemy.setLocation(0, 100);

        try {
            file = new File("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Assets\\Home.wav");
            AudioInputStream ais = AudioSystem.getAudioInputStream(file);
            music = AudioSystem.getClip();
            music.open(ais);
            music.start();
        } catch (LineUnavailableException | IOException | UnsupportedAudioFileException e) {
            throw new RuntimeException(e);
        }

        add(plane);
        add(enemy);
        add(progressBar);

    }
    public void gamewon(){
        removeAll();
        JLabel label = new JLabel("Victory!!!", SwingConstants.CENTER);
        label.setFont(new Font("joystix monospace", Font.PLAIN, 35));
        label.setForeground(Color.GREEN);
        label.setSize(200, 200);
        add(label);
        label.setBounds(0, 250, 800, 80);
        repaint();
    }

}

