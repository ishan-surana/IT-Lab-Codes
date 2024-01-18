import javafx.application.Application;
import javafx.scene.control.*;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.paint.Color;
import javafx.scene.layout.*;
class test extends Application {
    public void start(Stage primaryStage)
    {
        primaryStage.setTitle("This is the first javafx application");
        Label l=new Label();
        l.setText("Welcome to javafx programming");
        l.setTextFill(Color.MAGENTA);
        FlowPane root = new FlowPane(10 ,30);
        root.getChildren().add(l);
        Scene s=new Scene(root,500,200);
        primaryStage.setScene(s);
        primaryStage.show();

    }
    public static void main(String[] args) {
        launch(args);
    }
}