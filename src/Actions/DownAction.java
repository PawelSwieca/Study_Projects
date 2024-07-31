package Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import Gierka.Panel;
import Gierka.Plane;

public class DownAction extends AbstractAction {

    public DownAction(){

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Panel.getPlane().setLocation(Panel.getPlane().getLocation().x, Panel.getPlane().getLocation().y + Plane.getVelocity());
    }
}
