using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class Form1 : Form
    {
        private User currentUser;

        public Form1()
        {
            InitializeComponent();
            currentUser = new User("user", "password", 1000);
        }
        private void loginButton_Click(object sender, EventArgs e)
        {
            // Check if credentials are correct
            if (usernameTextBox.Text == currentUser.Username && passwordTextBox.Text == currentUser.Password)
            {
                // Open AccountInfoForm
                AccountInfoForm accountInfoForm = new AccountInfoForm(currentUser);
                accountInfoForm.ShowDialog();
            }
            else
            {
                MessageBox.Show("Invalid username or password.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void changePasswordButton_Click(object sender, EventArgs e)
        {
            // Open ChangePasswordForm
            ChangePasswordForm changePasswordForm = new ChangePasswordForm(currentUser);
            changePasswordForm.ShowDialog();
        }
    }

    public partial class AccountInfoForm : Form
    {
        private User currentUser;

        public AccountInfoForm(User user)
        {
            InitializeComponent();
            currentUser = user;
            // Display user information
            usernameLabel.Text = "Username: " + currentUser.Username;
            balanceLabel.Text = "Balance: $" + currentUser.Balance;
            lastAccessLabel.Text = "Last Access: " + currentUser.LastAccess;

            // Display last 5 transactions
            for (int i = Math.Max(0, currentUser.Transactions.Count - 5); i < currentUser.Transactions.Count; i++)
            {
                transactionsListBox.Items.Add(currentUser.Transactions[i]);
            }
            transferButton_Click(user,new EventArgs(),user);
        }
        void transferButton_Click(Object sender, EventArgs e, User user)
        {
            MoneyTransferForm moneyTransferForm = new MoneyTransferForm(user);
            moneyTransferForm.ShowDialog();
        }
    }

    public partial class MoneyTransferForm : Form
    {
        private User currentUser;

        public MoneyTransferForm(User user)
        {
            InitializeComponent();
            currentUser = user;
        }

        private void transferButton_Click(object sender, EventArgs e)
        {
            decimal amount;
            if (decimal.TryParse(amountTextBox.Text, out amount))
            {
                if (amount <= 0)
                {
                    MessageBox.Show("Invalid amount.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                // Perform money transfer (not implemented here)
                // Update user balance
                currentUser.Balance -= amount;
                // Add transaction
                currentUser.Transactions.Add("- $" + amount + " transferred to beneficiary.");
                // Display transfer amount and current balance
                MessageBox.Show("Amount transferred: $" + amount + "\nCurrent balance: $" + currentUser.Balance, "Money Transfer", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Invalid amount.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }

    public partial class ChangePasswordForm : Form
    {
        private User currentUser;

        public ChangePasswordForm(User user)
        {
            InitializeComponent();
            currentUser = user;
        }

        private void changePasswordButton_Click(object sender, EventArgs e)
        {
            // Check if current password is correct
            if (currentPasswordTextBox.Text == currentUser.Password)
            {
                // Update password
                currentUser.Password = newPasswordTextBox.Text;
                MessageBox.Show("Password changed successfully.", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            else
            {
                MessageBox.Show("Incorrect current password.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
    public class User
    {
        public string Username { get; set; }
        public string Password { get; set; }
        public decimal Balance { get; set; }
        public DateTime LastAccess { get; set; }
        public List<string> Transactions { get; set; }

        public User(string username, string password, decimal balance)
        {
            Username = username;
            Password = password;
            Balance = balance;
            LastAccess = DateTime.Now;
            Transactions = new List<string>();
        }
    }
