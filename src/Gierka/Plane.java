package Gierka;

import javax.swing.*;

import Actions.*;

import java.awt.*;

public class Plane extends JLabel {
    Action leftAction, rightAction, upAction, downAction, spaceAction;
    ImageIcon rocket;
    static int Velocity = 5;
    static int width, height;

    public static int getVelocity() {
        return Velocity;
    }


    public Plane() {
        setSize(100, 200);
        width = getWidth();
        height = getHeight();
        resizeImages();
        setIcon(rocket);
        setActions();

    }

    private void resizeImages() {
        rocket = new ImageIcon(new ImageIcon("C:\\Users\\Admin\\Java - nauka\\Gierka na zakonczenie\\src\\Assets\\rocket.png").getImage().getScaledInstance(100, 200, Image.SCALE_DEFAULT));
    }

    private void setActions() {
        leftAction = new LeftAction();
        rightAction = new RightAction();
        upAction = new UpAction();
        downAction = new DownAction();
        spaceAction = new SpaceAction();


        getInputMap().put(KeyStroke.getKeyStroke("UP"), "up");
        getActionMap().put("up", upAction);

        getInputMap().put(KeyStroke.getKeyStroke("DOWN"), "down");
        getActionMap().put("down", downAction);

        getInputMap().put(KeyStroke.getKeyStroke("LEFT"), "left");
        getActionMap().put("left", leftAction);

        getInputMap().put(KeyStroke.getKeyStroke("RIGHT"), "right");
        getActionMap().put("right", rightAction);

        getInputMap().put(KeyStroke.getKeyStroke("SPACE"), "space");
        getActionMap().put("space", spaceAction);
    }
}
