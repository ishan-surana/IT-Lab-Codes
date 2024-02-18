using System;
using System.Drawing;
using System.Windows.Forms;

namespace BankingApp
{
    partial class Form1 : Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            loginButton = new Button();
            changePasswordButton = new Button();
            usernameTextBox = new TextBox();
            passwordTextBox = new TextBox();
            SuspendLayout();
            // 
            // loginButton
            // 
            loginButton.Location = new Point(24, 128);
            loginButton.Name = "loginButton";
            loginButton.Size = new Size(150, 46);
            loginButton.TabIndex = 0;
            loginButton.Text = "Login";
            loginButton.UseVisualStyleBackColor = true;
            loginButton.Click += loginButton_Click;
            // 
            // changePasswordButton
            // 
            changePasswordButton.Location = new Point(224, 128);
            changePasswordButton.Name = "changePasswordButton";
            changePasswordButton.Size = new Size(222, 46);
            changePasswordButton.TabIndex = 1;
            changePasswordButton.Text = "Change Password";
            changePasswordButton.UseVisualStyleBackColor = true;
            changePasswordButton.Click += changePasswordButton_Click;
            // 
            // usernameTextBox
            // 
            usernameTextBox.Location = new Point(24, 32);
            usernameTextBox.Name = "usernameTextBox";
            usernameTextBox.Size = new Size(422, 27);
            usernameTextBox.TabIndex = 2;
            usernameTextBox.Text = "Username";
            // 
            // passwordTextBox
            // 
            passwordTextBox.Location = new Point(24, 83);
            passwordTextBox.Name = "passwordTextBox";
            passwordTextBox.Size = new Size(422, 27);
            passwordTextBox.TabIndex = 3;
            passwordTextBox.Text = "Password";
            passwordTextBox.UseSystemPasswordChar = true;
            // 
            // Form1
            // 
            ClientSize = new Size(500, 200);
            Controls.Add(passwordTextBox);
            Controls.Add(usernameTextBox);
            Controls.Add(changePasswordButton);
            Controls.Add(loginButton);
            Name = "Form1";
            Text = "Banking App";

            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Button loginButton;
        private System.Windows.Forms.Button changePasswordButton;
        private System.Windows.Forms.TextBox usernameTextBox;
        private System.Windows.Forms.TextBox passwordTextBox;
    }

    partial class AccountInfoForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.usernameLabel = new System.Windows.Forms.Label();
            this.balanceLabel = new System.Windows.Forms.Label();
            this.lastAccessLabel = new System.Windows.Forms.Label();
            this.transactionsListBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // usernameLabel
            // 
            this.usernameLabel.AutoSize = true;
            this.usernameLabel.Location = new System.Drawing.Point(13, 13);
            this.usernameLabel.Name = "usernameLabel";
            this.usernameLabel.Size = new System.Drawing.Size(0, 13);
            this.usernameLabel.TabIndex = 0;
            // 
            // balanceLabel
            // 
            this.balanceLabel.AutoSize = true;
            this.balanceLabel.Location = new System.Drawing.Point(13, 36);
            this.balanceLabel.Name = "balanceLabel";
            this.balanceLabel.Size = new System.Drawing.Size(0, 13);
            this.balanceLabel.TabIndex = 1;
            // 
            // lastAccessLabel
            // 
            this.lastAccessLabel.AutoSize = true;
            this.lastAccessLabel.Location = new System.Drawing.Point(13, 59);
            this.lastAccessLabel.Name = "lastAccessLabel";
            this.lastAccessLabel.Size = new System.Drawing.Size(0, 13);
            this.lastAccessLabel.TabIndex = 2;
            // 
            // transactionsListBox
            // 
            this.transactionsListBox.FormattingEnabled = true;
            this.transactionsListBox.Location = new System.Drawing.Point(16, 86);
            this.transactionsListBox.Name = "transactionsListBox";
            this.transactionsListBox.Size = new System.Drawing.Size(257, 147);
            this.transactionsListBox.TabIndex = 3;
            // 
            // AccountInfoForm
            // 
            this.ClientSize = new System.Drawing.Size(285, 250);
            this.Controls.Add(this.transactionsListBox);
            this.Controls.Add(this.lastAccessLabel);
            this.Controls.Add(this.balanceLabel);
            this.Controls.Add(this.usernameLabel);
            this.Name = "AccountInfoForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label usernameLabel;
        private System.Windows.Forms.Label balanceLabel;
        private System.Windows.Forms.Label lastAccessLabel;
        private System.Windows.Forms.ListBox transactionsListBox;
    }

    partial class MoneyTransferForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.transferButton = new System.Windows.Forms.Button();
            this.amountTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // transferButton
            // 
            this.transferButton.Location = new System.Drawing.Point(93, 64);
            this.transferButton.Name = "transferButton";
            this.transferButton.Size = new System.Drawing.Size(75, 23);
            this.transferButton.TabIndex = 0;
            this.transferButton.Text = "Transfer";
            this.transferButton.UseVisualStyleBackColor = true;
            this.transferButton.Click += new System.EventHandler(this.transferButton_Click);
            // 
            // amountTextBox
            // 
            this.amountTextBox.Location = new System.Drawing.Point(33, 38);
            this.amountTextBox.Name = "amountTextBox";
            this.amountTextBox.Size = new System.Drawing.Size(193, 20);
            this.amountTextBox.TabIndex = 1;
            this.amountTextBox.Text = "Amount";
            // 
            // MoneyTransferForm
            // 
            this.ClientSize = new System.Drawing.Size(260, 120);
            this.Controls.Add(this.amountTextBox);
            this.Controls.Add(this.transferButton);
            this.Name = "MoneyTransferForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button transferButton;
        private System.Windows.Forms.TextBox amountTextBox;
    }

    partial class ChangePasswordForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.currentPasswordTextBox = new System.Windows.Forms.TextBox();
            this.newPasswordTextBox = new System.Windows.Forms.TextBox();
            this.changePasswordButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // currentPasswordTextBox
            // 
            this.currentPasswordTextBox.Location = new System.Drawing.Point(12, 12);
            this.currentPasswordTextBox.Name = "currentPasswordTextBox";
            this.currentPasswordTextBox.Size = new System.Drawing.Size(211, 20);
            this.currentPasswordTextBox.TabIndex = 0;
            this.currentPasswordTextBox.Text = "Current Password";
            this.currentPasswordTextBox.UseSystemPasswordChar = true;
            // 
            // newPasswordTextBox
            // 
            this.newPasswordTextBox.Location = new System.Drawing.Point(12, 38);
            this.newPasswordTextBox.Name = "newPasswordTextBox";
            this.newPasswordTextBox.Size = new System.Drawing.Size(211, 20);
            this.newPasswordTextBox.TabIndex = 1;
            this.newPasswordTextBox.Text = "New Password";
            this.newPasswordTextBox.UseSystemPasswordChar = true;
            // 
            // changePasswordButton
            // 
            this.changePasswordButton.Location = new System.Drawing.Point(71, 64);
            this.changePasswordButton.Name = "changePasswordButton";
            this.changePasswordButton.Size = new System.Drawing.Size(93, 23);
            this.changePasswordButton.TabIndex = 2;
            this.changePasswordButton.Text = "Change Password";
            this.changePasswordButton.UseVisualStyleBackColor = true;
            this.changePasswordButton.Click += new System.EventHandler(this.changePasswordButton_Click);
            // 
            // ChangePasswordForm
            // 
            this.ClientSize = new System.Drawing.Size(235, 102);
            this.Controls.Add(this.changePasswordButton);
            this.Controls.Add(this.newPasswordTextBox);
            this.Controls.Add(this.currentPasswordTextBox);
            this.Name = "ChangePasswordForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox currentPasswordTextBox;
        private System.Windows.Forms.TextBox newPasswordTextBox;
        private System.Windows.Forms.Button changePasswordButton;
    }
}
