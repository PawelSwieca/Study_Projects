module com.example.odtwarzacz {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.web;

    requires org.controlsfx.controls;
    requires net.synedra.validatorfx;
    requires org.kordamp.bootstrapfx.core;
    requires eu.hansolo.tilesfx;
    requires java.desktop;
    requires javafx.media;
    requires java.management;

    opens com.example.odtwarzacz to javafx.fxml;
    exports com.example.odtwarzacz;
}