package com.example.odtwarzacz;


import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.util.Duration;


import java.io.File;
import java.net.URL;
import java.util.*;

public class HelloController implements Initializable {
    public ProgressBar progress;
    public Label title;
    public ButtonBar button_bar;
    public Button play, down, up, set;
    public Slider volume;
    public TreeView<String> selection;
    public Media media;
    public AnchorPane plane;

    private Timer timer;
    private int songsumber;

    private MediaPlayer mediaPlayer;

    public double getEnd() {
        return end;
    }

    private double end;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        ArrayList<File> songs = new ArrayList<>();
        File directory = new File("music");
        File[] files = directory.listFiles();
        if (files != null) {
            songs.addAll(Arrays.asList(files));
            System.out.println(songs.getFirst());
        }
        up.setDisable(true);
        down.setDisable(true);


        media = new Media(songs.get(songsumber).toURI().toString());
        mediaPlayer = new MediaPlayer(media);

        title.setText("Wybież utwór");

        volume.valueProperty().addListener(new ChangeListener<>() {
            @Override
            public void changed(ObservableValue<? extends Number> observableValue, Number number, Number t1) {
                mediaPlayer.setVolume(volume.getValue() * 0.01);
            }
        });

        TreeItem<String> root = new TreeItem<>("Music");
        selection.setRoot(root);
        for(File file : songs) {
            root.getChildren().add(new TreeItem<>(file.getName()));
        }
        play.setDisable(true);
    }

    public void playmedia() {
        end = mediaPlayer.getTotalDuration().toSeconds();

        up.setDisable(false);
        down.setDisable(false);

        beginTimer();
        mediaPlayer.play();
    }

    public void downmedia() {
        mediaPlayer.seek(Duration.seconds(mediaPlayer.getCurrentTime().toSeconds() - 10));
        double time = mediaPlayer.getCurrentTime().toSeconds() - 10;
        mediaPlayer.seek(Duration.seconds(time));
        if(time-end == 0){
            progress.setProgress(0);
            beginTimer();
            progress.setProgress(end-10);
            mediaPlayer.seek(Duration.seconds(end - 10));
        }
        System.out.println("Current time: " + mediaPlayer.getCurrentTime().toSeconds());
    }

    public void upmedia() {
        mediaPlayer.seek(Duration.seconds(mediaPlayer.getCurrentTime().toSeconds() + 10));
        double time = mediaPlayer.getCurrentTime().toSeconds() + 10;
        if(time/end == 1) {
            //up.setDisable(true);
            endTimer();
        }
        progress.setProgress(time/end);
        System.out.println("Current time: " + mediaPlayer.getCurrentTime().toSeconds());
    }
    public void beginTimer(){
        timer = new java.util.Timer();
        TimerTask timerTask = new TimerTask() {
            public void run() {
                double current = mediaPlayer.getCurrentTime().toSeconds();
                System.out.println("Current time: " + current);
                progress.setProgress(current / getEnd());

                if (current - end == 0) {
                    System.out.println(Math.round(current - end));
                    endTimer();
                }
            }
        };
        timer.scheduleAtFixedRate(timerTask, 1000, 1000);

    }
    public void endTimer(){
        progress.setProgress(0);

        mediaPlayer.seek(Duration.seconds(0));
        mediaPlayer.pause();

        timer.cancel();

        up.setDisable(true);
        down.setDisable(true);
    }
    public void choose_music(){
        selection.setVisible(true);
    }
    public void get_music(){
        if(timer!=null){
            endTimer();
        }
        if(selection.getSelectionModel().getSelectedItem() != null){
            TreeItem<String> item = selection.getSelectionModel().getSelectedItem();
            if(!item.getValue().equals("Music")){
                File file = new File("music\\"+item.getValue());
                media = new Media(file.toURI().toString());
                mediaPlayer = new MediaPlayer(media);
                title.setText(item.getValue());

                mediaPlayer.setVolume(volume.getValue() * 0.01);

                selection.setVisible(false);
                play.setDisable(false);
            }
        }
    }
}