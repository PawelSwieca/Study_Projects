package Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import Gierka.Panel;
import Gierka.Plane;

public class LeftAction extends AbstractAction {
    public LeftAction(){}

    @Override
    public void actionPerformed(ActionEvent e) {
        Panel.getPlane().setLocation(Panel.getPlane().getLocation().x - Plane.getVelocity(), Panel.getPlane().getLocation().y);
    }
}
