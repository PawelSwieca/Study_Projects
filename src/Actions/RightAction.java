package Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import Gierka.Gra;

public class RightAction extends AbstractAction {
    public RightAction() {
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Gra.getPlane().setLocation(Gra.getPlane().getLocation().x + 5, Gra.getPlane().getLocation().y);
    }
}
