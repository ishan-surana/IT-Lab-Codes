using System;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace StudentsForm
{
    public partial class Form1 : Form
    {
        string name, regno, branch, sem, gender, bday, reason, choices = "Selected ";
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            combobox_init();
            radioButton1.Select();
            //label7_Modify();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.White;
            name = textBox1.Text;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.ForeColor = Color.White;
            regno = textBox2.Text;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            textBox3.ForeColor = Color.White;
            branch = textBox3.Text;
        }

        private void combobox_init()
        {
            string[] options = { "I", "II","III","IV","V","VI","VII","VIII"};
            comboBox1.Items.AddRange(options);
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            reason = textBox5.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gender = groupBox1.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked).Text;
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
            button1.BackColor = Color.SeaGreen;
            button1.ForeColor = Color.White;
        }

        private void button1_dishover(object sender, EventArgs e)
        {
            button1.BackColor = Color.MediumSpringGreen;
            button1.ForeColor = Color.Black;
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
