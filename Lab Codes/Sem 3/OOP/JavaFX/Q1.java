import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.layout.*;
import javafx.scene.input.*;
public class Q1 extends Application {
    public void start(Stage primaryStage)
    {
        primaryStage.setTitle("This is the first javafx application");
        Label l=new Label();
        l.setText("Welcome to javafx programming");
        l.setTextFill(Color.RED);
        HBox bl=new HBox(30);
        Button b=new Button("button");
        bl.getChildren().add(b);
        VBox root = new VBox(20);
        root.getChildren().addAll(l,bl);
        b.setOnMouseEntered(new EventHandler<MouseEvent>(){
            public void handle(MouseEvent event)
            {
                Label l1=new Label("HOVER!");
                bl.getChildren().add(l1);
            }
        });
        b.setOnMouseExited(new EventHandler<MouseEvent>(){
            public void handle(MouseEvent event)
            {
                bl.getChildren().remove(l1);
            }
        });
        Scene s=new Scene(root,500,200);
        primaryStage.setScene(s);
        primaryStage.show();
    }
    public static void main(String[] args) {
        launch(args);
    }
}