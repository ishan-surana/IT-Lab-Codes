using System;
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
            input = res.ToString();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            ans.Text = string.Empty;
            input = string.Empty;
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
            if (ans.Text == string.Empty)
                this.Cursor = Cursors.No;
        }
        private void dehovering(object sender, EventArgs e)
        {
            this.Cursor = Cursors.Default;
        }

        private void button21_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Sin(Math.PI * double.Parse(Op1) / 180);
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button20_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Cos(Math.PI * double.Parse(Op1) / 180);
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button22_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Tan(Math.PI * double.Parse(Op1) / 180);
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button25_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double resc = double.Parse(Op1);
            res = 1;
            for (int i = 1; i < resc; i++, res *= i) ;
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button26_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Floor(double.Parse(Op1));
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button23_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Pow(Math.E, double.Parse(Op1));
            ans.Text = res.ToString();
            input = res.ToString();
        }

        private void button24_Click(object sender, EventArgs e)
        {
            Op1 = input;
            res = Math.Log(double.Parse(Op1));
            ans.Text = res.ToString();
            input = res.ToString();
        }
    }
}