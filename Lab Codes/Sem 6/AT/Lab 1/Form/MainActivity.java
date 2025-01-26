package com.example.form;

import android.os.Bundle;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import android.widget.EditText;
import android.widget.Button;
import android.widget.Switch;
import android.widget.Toast;

import android.text.TextUtils;
import android.util.Patterns;

public class MainActivity extends AppCompatActivity {

    private EditText name, mail, phone, pass;
    private Button button;
    private Switch toggle;

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
        name = findViewById(R.id.editTextText);
        mail = findViewById(R.id.editTextTextEmailAddress);
        phone = findViewById(R.id.editTextPhone);
        pass = findViewById(R.id.editTextTextPassword);
        button = findViewById(R.id.button);
        toggle = findViewById(R.id.switch1);
        toggle.setOnCheckedChangeListener((buttonView, isChecked) -> togglePasswordVisibility(isChecked));
        button.setOnClickListener(v -> validateAndSubmit());
    }

    private void togglePasswordVisibility(boolean isChecked) {
        if(!isChecked) pass.setInputType(129); // InputType.TYPE_CLASS_TEXT | TYPE_TEXT_VARIATION_PASSWORD
        else pass.setInputType(128); // InputType.TYPE_CLASS_TEXT | TYPE_TEXT_VARIATION_PASSWORD
        pass.setSelection(pass.getText().length());
    }

    private void validateAndSubmit() {
        String name_string = name.getText().toString().trim();
        String email = mail.getText().toString().trim();
        String mobile = phone.getText().toString().trim();
        String password = pass.getText().toString().trim();

        if (TextUtils.isEmpty(name_string)) {
            showToast("Name cannot be empty");
            return;
        }

        if (TextUtils.isEmpty(email)) {
            showToast("Email cannot be empty");
            return;
        } else if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
            showToast("Please enter a valid email address");
            return;
        }

        if (TextUtils.isEmpty(mobile)) {
            showToast("Mobile number cannot be empty");
            return;
        } else if (!mobile.matches("[0-9]+") || mobile.length() != 10) {
            showToast("Please enter a valid 10-digit mobile number");
            return;
        }

        if (TextUtils.isEmpty(password)) {
            showToast("Password cannot be empty");
            return;
        } else if (password.length() < 6) {
            showToast("Password must be at least 6 characters long");
            return;
        }

        showToast("Registration successful!");
    }

    private void showToast(String message) {
        Toast.makeText(MainActivity.this, message, Toast.LENGTH_SHORT).show();
    }
}