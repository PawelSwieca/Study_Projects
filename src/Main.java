import Gierka.*;
import Gierka.Menu;

import java.awt.*;
import java.io.IOException;

public class Main {
    public static void main(String[] args){
        try {
            Menu menu = new Menu();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (FontFormatException e) {
            throw new RuntimeException(e);
        }

    }
}