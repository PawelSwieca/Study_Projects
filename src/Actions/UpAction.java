package Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import Gierka.Gra;

public class UpAction extends AbstractAction {
    public UpAction(){}

    @Override
    public void actionPerformed(ActionEvent e) {
        Gra.getPlane().setLocation(Gra.getPlane().getLocation().x, Gra.getPlane().getLocation().y - 10);
    }
}
