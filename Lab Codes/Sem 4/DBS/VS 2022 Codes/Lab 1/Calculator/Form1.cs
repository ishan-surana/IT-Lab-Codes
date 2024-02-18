using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Calculator
{
    public partial class Form1 : Form
    {
        string input = string.Empty;
        string Op1 = string.Empty;
        string Op2 = string.Empty;
        char Operator;
        double res = 0.0;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //this.Text = "Death Note";
            //this.title = "CalcyBoi"
        }
        private void ans_TextChanged(object sender, EventArgs e)
        { }

        private void button17_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "0";
            this.ans.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "1";
            this.ans.Text += input;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "2";
            this.ans.Text += input;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "3";
            this.ans.Text += input;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "4";
            this.ans.Text += input;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "5";
            this.ans.Text += input;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "6";
            this.ans.Text += input;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "7";
            this.ans.Text += input;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "8";
            this.ans.Text += input;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.ans.Text = string.Empty;
            input += "9";
            this.ans.Text += input;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '+';
            input = string.Empty;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '-';
            input = string.Empty;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '*';
            input = string.Empty;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '/';
            input = string.Empty;
        }

        private void button16_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '^';
            input = string.Empty;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            Op2 = input;
            double num1, num2;
            double.TryParse(Op1, out num1);
            double.TryParse(Op2, out num2);
            if (Operator == '+')
            {
                res = num1 + num2;
                this.ans.Text = res.ToString();
            }
            else if (Operator == '-')
            {
                res = num1 - num2;
                ans.Text = res.ToString();
            }
            else if (Operator == '*')
            {
                res = num1 * num2;
                ans.Text = res.ToString();
            }
            else if (Operator == '/')
            {
                if (num2 != 0)
                {
                    res = num1 / num2;
                    ans.Text = res.ToString();
                }
                else
                {
                    ans.Text = "DIV/Zero!";
                }
            }
            else if (Operator == '^')
            {
                res = Math.Pow(num1, num2);
                ans.Text = res.ToString();
            }
            input = string.Empty;
        }

        private void button15_Click(object sender, EventArgs e)
        {
            ans.Text = string.Empty;
        }

        private void button18_Click(object sender, EventArgs e)
        {
            try
            {
                ans.Text = ans.Text.Substring(0, ans.Text.Length - 1);
                input = ans.Text;
            }
            catch (ArgumentOutOfRangeException)
            {
                hovering(sender, e);
            }
        }
        private void hovering(object sender, EventArgs e)
        {
            if(ans.Text==string.Empty)
            this.Cursor = Cursors.No;
        }
        private void dehovering(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }
    }
}