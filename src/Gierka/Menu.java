package Gierka;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class Menu extends JFrame implements ActionListener {
    Gra game;
    JButton play, exit;
    JLabel label;
    GraphicsEnvironment ge;

    public Menu() throws IOException, FontFormatException {
        setTitle("SPACE WARS!");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        setSize(800, 800);
        getContentPane().setBackground(Color.BLACK);
        setLocationRelativeTo(null);
        label = new JLabel("SPACE WARS!");
        label.setForeground(new Color(20, 255, 0));
        label.setBorder(new EmptyBorder(50, 100, 70, 100));
        ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        ge.registerFont(Font.createFont(Font.TRUETYPE_FONT, new File("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Assets\\joystix monospace.otf")));
        label.setFont(new Font("joystix monospace", Font.PLAIN, 70));

        play = new JButton("Start game");
        play.setFont(new Font("joystix monospace", Font.PLAIN, 30));
        play.setForeground(new Color(20, 255, 0));
        play.setFocusable(false);
        play.setBackground(Color.BLACK);
        play.setBorder(new EmptyBorder(50, 300, 70, 300));

        exit = new JButton("Exit");
        exit.setFont(new Font("joystix monospace", Font.PLAIN, 30));
        exit.setForeground(new Color(20, 255, 0));
        exit.setFocusable(false);
        exit.setBackground(Color.BLACK);
        exit.setBorder(new EmptyBorder(50, 350, 70, 350));

        play.addActionListener(this);
        exit.addActionListener(this);


        add(label);
        add(play);
        add(exit);
        setVisible(true);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand()) {
            case "Start game":
                dispose();
                game = new Gra();
                break;
            case "Exit":
                dispose();
        }
    }
}
