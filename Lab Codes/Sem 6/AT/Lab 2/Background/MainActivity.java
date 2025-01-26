package com.example.background;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import android.text.Layout;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Declare views as member variables
    private TextView textView;
    private Switch switchMode;
    private ConstraintLayout parentLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        textView = findViewById(R.id.textView);
        switchMode = findViewById(R.id.switch1);
        parentLayout = findViewById(R.id.main);

        setLightMode();

        switchMode.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (isChecked) setDarkMode();
            else setLightMode();
        });
    }

    // Method to set Light Mode
    private void setLightMode() {
        parentLayout.setBackgroundColor(getResources().getColor(android.R.color.white));
        textView.setTextColor(getResources().getColor(android.R.color.black));
        textView.setText("Light Mode");
        switchMode.setTextColor(getResources().getColor(android.R.color.black));
        Toast.makeText(this, "Light Mode Activated", Toast.LENGTH_SHORT).show();
    }

    // Method to set Dark Mode
    private void setDarkMode() {
        parentLayout.setBackgroundColor(getResources().getColor(android.R.color.black));
        textView.setTextColor(getResources().getColor(android.R.color.white));
        textView.setText("Dark Mode");
        switchMode.setTextColor(getResources().getColor(android.R.color.white));
        Toast.makeText(this, "Dark Mode Activated", Toast.LENGTH_SHORT).show();
    }
}
