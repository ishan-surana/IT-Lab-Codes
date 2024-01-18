using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace StudentsForm
{
    public partial class Form1 : Form
    {
        string name, regno, branch, sem, pref, gender, bday, reason, choices = "Selected ";
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            combobox_init();
            radioButton1.Select();
            //label7_Modify();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox1.ForeColor = System.Drawing.Color.White;
            name = textBox1.Text;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.ForeColor = System.Drawing.Color.White;
            regno = textBox2.Text;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.ForeColor = System.Drawing.Color.White;
            branch = textBox3.Text;
        }

        private void combobox_init()
        {
            comboBox1.Items.Add("I");
            comboBox1.Items.Add("II");
            comboBox1.Items.Add("III");
            comboBox1.Items.Add("IV");
            comboBox1.Items.Add("V");
            comboBox1.Items.Add("VI");
            comboBox1.Items.Add("VII");
            comboBox1.Items.Add("VIII");
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            reason = textBox5.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gender = "";
            gender = groupBox1.Controls.OfType<System.Windows.Forms.RadioButton>().FirstOrDefault(r => r.Checked).Text;
            if (gender.Contains("Other"))
                gender=gender.Substring(0, gender.Length - 3)+" ("+textBox4.Text+')';
            MessageBox.Show("RESPONSE:-\nName = " + name + "\nRegistration Number = " + regno + "\nBranch = " + branch + "\nSemester = " + sem + "\nGender = " + gender + "\nBirthday = " + bday + "\nSelected = " + choices + "\nAdditional = " + reason);
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            choices = string.Join(", ", checkedListBox1.CheckedItems.Cast<object>());
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            sem = comboBox1.GetItemText(comboBox1.SelectedItem);
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            bday = monthCalendar1.SelectionRange.Start.ToLongDateString();
        }

        private void button1_hover(object sender, EventArgs e)
        {
            button1.BackColor = System.Drawing.Color.SeaGreen;
            button1.ForeColor = System.Drawing.Color.White;
        }

        private void button1_dishover(object sender, EventArgs e)
        {
            button1.BackColor = System.Drawing.Color.MediumSpringGreen;
            button1.ForeColor = System.Drawing.Color.Black;
        }
        /*
public void label7_Modify()
{
string selectedOptions = "Selected ";
foreach (var item in checkedListBox1.CheckedItems)
{
selectedOptions += item.ToString() + ", ";
}
selectedOptions = selectedOptions.TrimEnd(',', ' ');
label7.Text = selectedOptions;
}

private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
{
label7_Modify();
}

private void checkedListBox1_MouseHover(object sender, EventArgs e)
{
label7_Modify();
}
* */
    }
}
