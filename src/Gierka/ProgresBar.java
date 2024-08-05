package Gierka;

import javax.swing.*;
import java.awt.*;

public class ProgresBar extends JProgressBar {
    public ProgresBar() {
        setForeground(Color.GREEN);
        setBackground(Color.WHITE);
        setFont(new Font("joystix monospace", Font.PLAIN, 10));
        setString("BOSS HP");
        setStringPainted(true);
        setMaximum(Enemy.getLive_points());
        setOpaque(true);
        setValue(Enemy.getLive_points());

    }
}
