package com.example.grocery;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import android.widget.Spinner;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.RadioGroup;
import android.widget.RadioButton;
import android.widget.Switch;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

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

        Spinner spinner = findViewById(R.id.spinner);
        RadioGroup food = findViewById(R.id.radioGroup);
        RadioGroup beverage = findViewById(R.id.radioGroup2);
        Switch switch_button = findViewById(R.id.switch1);
        Button button = findViewById(R.id.button);

        String[] spinnerItems = {"★", "★★", "★★★", "★★★★", "★★★★★"};
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, spinnerItems);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);

        button.setOnClickListener(v -> {
            if (switch_button.isChecked()) {
                String food_name, beverage_name, rating;

                int selectedFoodId = food.getCheckedRadioButtonId();
                if (selectedFoodId != -1) {
                    RadioButton selectedFood = null;
                    for (int i = 0; i < food.getChildCount(); i++) {
                        RadioButton radioButton = (RadioButton) food.getChildAt(i);
                        if (radioButton.getId() == selectedFoodId) {
                            selectedFood = radioButton;
                            break;
                        }
                    }
                    food_name = "Selected food: " + selectedFood.getText();
                }
                else food_name = "Food: No food selected!";

                int selectedBeverageId = beverage.getCheckedRadioButtonId();
                if (selectedBeverageId != -1) {
                    RadioButton selectedBeverage = null;
                    for (int i = 0; i < beverage.getChildCount(); i++) {
                        RadioButton radioButton = (RadioButton) beverage.getChildAt(i);
                        if (radioButton.getId() == selectedBeverageId) {
                            selectedBeverage = radioButton;
                            break;
                        }
                    }
                    beverage_name = "Selected beverage: " + selectedBeverage.getText();
                }
                else beverage_name = "Beverage: No beverage selected!";

                rating = "Selected rating: " + spinner.getSelectedItem().toString();
                String message = food_name + ", " + beverage_name + ", " + rating;
                Toast.makeText(MainActivity.this, message, Toast.LENGTH_LONG).show();
            }
        });
    }
}