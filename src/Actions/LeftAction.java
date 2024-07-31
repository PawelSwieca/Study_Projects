package Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import Gierka.Gra;

public class LeftAction extends AbstractAction {
    public LeftAction(){}

    @Override
    public void actionPerformed(ActionEvent e) {
        Gra.getPlane().setLocation(Gra.getPlane().getLocation().x - 5, Gra.getPlane().getLocation().y);
    }
}
