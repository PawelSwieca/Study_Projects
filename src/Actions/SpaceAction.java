package Actions;

import Gierka.Laser;
import Gierka.Panel;
import Gierka.Gra;

import javax.swing.*;
import java.awt.event.ActionEvent;

public class SpaceAction extends AbstractAction {
    public SpaceAction() {}

    @Override
    public void actionPerformed(ActionEvent e) {
        Laser laser = new Laser();
        laser.setBounds((Panel.getPlane().getX() + 50), (Panel.getPlane().getY() + 150), 5, 20);
        Gra.getPanel().add(laser);
        //Panel.setLaser(laser);

    }
}
