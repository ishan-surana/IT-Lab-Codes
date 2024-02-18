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
            this.title = new System.Windows.Forms.Label();
            this.button17 = new System.Windows.Forms.Button();
            this.ans = new System.Windows.Forms.TextBox();
            this.button18 = new System.Windows.Forms.Button();
            this.button14 = new System.Windows.Forms.Button();
            this.button19 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button16 = new System.Windows.Forms.Button();
            this.button15 = new System.Windows.Forms.Button();
            this.button20 = new System.Windows.Forms.Button();
            this.button21 = new System.Windows.Forms.Button();
            this.button22 = new System.Windows.Forms.Button();
            this.button23 = new System.Windows.Forms.Button();
            this.button24 = new System.Windows.Forms.Button();
            this.button25 = new System.Windows.Forms.Button();
            this.button26 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.Font = new System.Drawing.Font("Old English Text MT", 35F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.title.ForeColor = System.Drawing.Color.White;
            this.title.Location = new System.Drawing.Point(120, 9);
            this.title.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(229, 56);
            this.title.TabIndex = 0;
            this.title.Text = "Calculator";
            // 
            // button17
            // 
            this.button17.BackColor = System.Drawing.Color.DodgerBlue;
            this.button17.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button17.FlatAppearance.BorderSize = 5;
            this.button17.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button17.ForeColor = System.Drawing.Color.White;
            this.button17.Location = new System.Drawing.Point(36, 373);
            this.button17.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button17.Name = "button17";
            this.button17.Size = new System.Drawing.Size(57, 47);
            this.button17.TabIndex = 18;
            this.button17.Text = "0";
            this.button17.UseVisualStyleBackColor = false;
            this.button17.Click += new System.EventHandler(this.button17_Click);
            // 
            // ans
            // 
            this.ans.Font = new System.Drawing.Font("Britannic Bold", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ans.Location = new System.Drawing.Point(43, 86);
            this.ans.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.ans.Name = "ans";
            this.ans.Size = new System.Drawing.Size(399, 37);
            this.ans.TabIndex = 19;
            this.ans.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // button18
            // 
            this.button18.BackColor = System.Drawing.Color.Chartreuse;
            this.button18.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button18.FlatAppearance.BorderSize = 5;
            this.button18.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button18.Location = new System.Drawing.Point(113, 373);
            this.button18.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button18.Name = "button18";
            this.button18.Size = new System.Drawing.Size(57, 47);
            this.button18.TabIndex = 20;
            this.button18.Text = "<=";
            this.button18.UseVisualStyleBackColor = false;
            this.button18.Click += new System.EventHandler(this.button18_Click);
            // 
            // button14
            // 
            this.button14.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.button14.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button14.ForeColor = System.Drawing.Color.White;
            this.button14.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button14.Location = new System.Drawing.Point(195, 373);
            this.button14.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button14.Name = "button14";
            this.button14.Size = new System.Drawing.Size(57, 47);
            this.button14.TabIndex = 15;
            this.button14.Text = "=";
            this.button14.UseVisualStyleBackColor = false;
            this.button14.Click += new System.EventHandler(this.button14_Click);
            // 
            // button19
            // 
            this.button19.ForeColor = System.Drawing.SystemColors.ControlText;
            this.button19.Location = new System.Drawing.Point(254, 50);
            this.button19.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button19.Name = "button19";
            this.button19.Size = new System.Drawing.Size(11, 15);
            this.button19.TabIndex = 21;
            this.button19.UseVisualStyleBackColor = true;
            this.button19.Click += new System.EventHandler(this.Unlock);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.DodgerBlue;
            this.button1.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button1.FlatAppearance.BorderSize = 5;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(36, 166);
            this.button1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(57, 47);
            this.button1.TabIndex = 2;
            this.button1.Text = "9";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.DodgerBlue;
            this.button2.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button2.FlatAppearance.BorderSize = 5;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(113, 166);
            this.button2.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(57, 47);
            this.button2.TabIndex = 3;
            this.button2.Text = "8";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.DodgerBlue;
            this.button3.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button3.FlatAppearance.BorderSize = 5;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ForeColor = System.Drawing.Color.White;
            this.button3.Location = new System.Drawing.Point(195, 166);
            this.button3.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(57, 47);
            this.button3.TabIndex = 4;
            this.button3.Text = "7";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.DodgerBlue;
            this.button6.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button6.FlatAppearance.BorderSize = 5;
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.ForeColor = System.Drawing.Color.White;
            this.button6.Location = new System.Drawing.Point(36, 235);
            this.button6.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(57, 47);
            this.button6.TabIndex = 5;
            this.button6.Text = "6";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.DodgerBlue;
            this.button5.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button5.FlatAppearance.BorderSize = 5;
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.ForeColor = System.Drawing.Color.White;
            this.button5.Location = new System.Drawing.Point(113, 235);
            this.button5.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(57, 47);
            this.button5.TabIndex = 6;
            this.button5.Text = "5";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.DodgerBlue;
            this.button4.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button4.FlatAppearance.BorderSize = 5;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.ForeColor = System.Drawing.Color.White;
            this.button4.Location = new System.Drawing.Point(195, 235);
            this.button4.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(57, 47);
            this.button4.TabIndex = 7;
            this.button4.Text = "4";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.Color.DodgerBlue;
            this.button9.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button9.FlatAppearance.BorderSize = 5;
            this.button9.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button9.ForeColor = System.Drawing.Color.White;
            this.button9.Location = new System.Drawing.Point(36, 304);
            this.button9.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(57, 47);
            this.button9.TabIndex = 8;
            this.button9.Text = "3";
            this.button9.UseVisualStyleBackColor = false;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.DodgerBlue;
            this.button8.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button8.FlatAppearance.BorderSize = 5;
            this.button8.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button8.ForeColor = System.Drawing.Color.White;
            this.button8.Location = new System.Drawing.Point(113, 304);
            this.button8.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(57, 47);
            this.button8.TabIndex = 9;
            this.button8.Text = "2";
            this.button8.UseVisualStyleBackColor = false;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button7
            // 
            this.button7.BackColor = System.Drawing.Color.DodgerBlue;
            this.button7.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button7.FlatAppearance.BorderSize = 5;
            this.button7.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button7.ForeColor = System.Drawing.Color.White;
            this.button7.Location = new System.Drawing.Point(195, 304);
            this.button7.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(57, 47);
            this.button7.TabIndex = 10;
            this.button7.Text = "1";
            this.button7.UseVisualStyleBackColor = false;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button13
            // 
            this.button13.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.button13.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button13.FlatAppearance.BorderSize = 5;
            this.button13.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button13.Location = new System.Drawing.Point(313, 166);
            this.button13.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(57, 47);
            this.button13.TabIndex = 11;
            this.button13.Text = "+";
            this.button13.UseVisualStyleBackColor = false;
            this.button13.Click += new System.EventHandler(this.button13_Click);
            // 
            // button12
            // 
            this.button12.BackColor = System.Drawing.Color.SpringGreen;
            this.button12.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button12.FlatAppearance.BorderSize = 5;
            this.button12.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button12.Location = new System.Drawing.Point(395, 166);
            this.button12.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(57, 47);
            this.button12.TabIndex = 12;
            this.button12.Text = "-";
            this.button12.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button12.UseVisualStyleBackColor = false;
            this.button12.Click += new System.EventHandler(this.button12_Click);
            // 
            // button11
            // 
            this.button11.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.button11.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button11.FlatAppearance.BorderSize = 5;
            this.button11.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button11.Location = new System.Drawing.Point(313, 235);
            this.button11.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(57, 47);
            this.button11.TabIndex = 13;
            this.button11.Text = "*";
            this.button11.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button11.UseVisualStyleBackColor = false;
            this.button11.Click += new System.EventHandler(this.button11_Click);
            // 
            // button10
            // 
            this.button10.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.button10.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button10.FlatAppearance.BorderSize = 5;
            this.button10.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button10.Location = new System.Drawing.Point(395, 235);
            this.button10.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(57, 47);
            this.button10.TabIndex = 14;
            this.button10.Text = "/";
            this.button10.UseVisualStyleBackColor = false;
            this.button10.Click += new System.EventHandler(this.button10_Click);
            // 
            // button16
            // 
            this.button16.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.button16.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button16.FlatAppearance.BorderSize = 5;
            this.button16.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button16.Location = new System.Drawing.Point(313, 308);
            this.button16.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(57, 47);
            this.button16.TabIndex = 16;
            this.button16.Text = "^";
            this.button16.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button16.UseVisualStyleBackColor = false;
            this.button16.Click += new System.EventHandler(this.button16_Click);
            // 
            // button15
            // 
            this.button15.BackColor = System.Drawing.Color.BlueViolet;
            this.button15.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button15.FlatAppearance.BorderSize = 5;
            this.button15.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button15.ForeColor = System.Drawing.Color.White;
            this.button15.Location = new System.Drawing.Point(395, 308);
            this.button15.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(57, 47);
            this.button15.TabIndex = 17;
            this.button15.Text = "AC";
            this.button15.UseVisualStyleBackColor = false;
            this.button15.Click += new System.EventHandler(this.button15_Click);
            // 
            // button20
            // 
            this.button20.BackColor = System.Drawing.Color.Fuchsia;
            this.button20.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button20.FlatAppearance.BorderSize = 5;
            this.button20.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button20.ForeColor = System.Drawing.Color.White;
            this.button20.Location = new System.Drawing.Point(113, 442);
            this.button20.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button20.Name = "button20";
            this.button20.Size = new System.Drawing.Size(57, 47);
            this.button20.TabIndex = 23;
            this.button20.Text = "cos";
            this.button20.UseVisualStyleBackColor = false;
            this.button20.Click += new System.EventHandler(this.button20_Click);
            // 
            // button21
            // 
            this.button21.BackColor = System.Drawing.Color.Red;
            this.button21.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button21.FlatAppearance.BorderSize = 5;
            this.button21.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button21.ForeColor = System.Drawing.Color.White;
            this.button21.Location = new System.Drawing.Point(36, 442);
            this.button21.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button21.Name = "button21";
            this.button21.Size = new System.Drawing.Size(57, 47);
            this.button21.TabIndex = 23;
            this.button21.Text = "sin";
            this.button21.UseVisualStyleBackColor = false;
            this.button21.Click += new System.EventHandler(this.button21_Click);
            // 
            // button22
            // 
            this.button22.BackColor = System.Drawing.Color.DeepPink;
            this.button22.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button22.ForeColor = System.Drawing.Color.White;
            this.button22.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button22.Location = new System.Drawing.Point(195, 442);
            this.button22.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button22.Name = "button22";
            this.button22.Size = new System.Drawing.Size(57, 47);
            this.button22.TabIndex = 22;
            this.button22.Text = "tan";
            this.button22.UseVisualStyleBackColor = false;
            this.button22.Click += new System.EventHandler(this.button22_Click);
            // 
            // button23
            // 
            this.button23.BackColor = System.Drawing.Color.MediumAquamarine;
            this.button23.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button23.FlatAppearance.BorderSize = 5;
            this.button23.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button23.ForeColor = System.Drawing.Color.Black;
            this.button23.Location = new System.Drawing.Point(313, 442);
            this.button23.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button23.Name = "button23";
            this.button23.Size = new System.Drawing.Size(57, 47);
            this.button23.TabIndex = 27;
            this.button23.Text = "eˣ";
            this.button23.UseVisualStyleBackColor = false;
            this.button23.Click += new System.EventHandler(this.button23_Click);
            // 
            // button24
            // 
            this.button24.BackColor = System.Drawing.Color.DarkMagenta;
            this.button24.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button24.ForeColor = System.Drawing.Color.White;
            this.button24.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button24.Location = new System.Drawing.Point(395, 442);
            this.button24.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button24.Name = "button24";
            this.button24.Size = new System.Drawing.Size(57, 47);
            this.button24.TabIndex = 26;
            this.button24.Text = "ln(x)";
            this.button24.UseVisualStyleBackColor = false;
            this.button24.Click += new System.EventHandler(this.button24_Click);
            // 
            // button25
            // 
            this.button25.BackColor = System.Drawing.Color.Gold;
            this.button25.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button25.FlatAppearance.BorderSize = 5;
            this.button25.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button25.Location = new System.Drawing.Point(313, 373);
            this.button25.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button25.Name = "button25";
            this.button25.Size = new System.Drawing.Size(57, 47);
            this.button25.TabIndex = 25;
            this.button25.Text = "n!";
            this.button25.UseVisualStyleBackColor = false;
            this.button25.Click += new System.EventHandler(this.button25_Click);
            // 
            // button26
            // 
            this.button26.BackColor = System.Drawing.Color.Blue;
            this.button26.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button26.ForeColor = System.Drawing.Color.White;
            this.button26.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button26.Location = new System.Drawing.Point(395, 373);
            this.button26.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.button26.Name = "button26";
            this.button26.Size = new System.Drawing.Size(57, 47);
            this.button26.TabIndex = 24;
            this.button26.Text = "⌊x⌋";
            this.button26.UseVisualStyleBackColor = false;
            this.button26.Click += new System.EventHandler(this.button26_Click);
            // 
            // Form1
            // 
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(483, 520);
            this.Controls.Add(this.button23);
            this.Controls.Add(this.button24);
            this.Controls.Add(this.button25);
            this.Controls.Add(this.button26);
            this.Controls.Add(this.button20);
            this.Controls.Add(this.button21);
            this.Controls.Add(this.button22);
            this.Controls.Add(this.button18);
            this.Controls.Add(this.ans);
            this.Controls.Add(this.button17);
            this.Controls.Add(this.button15);
            this.Controls.Add(this.button16);
            this.Controls.Add(this.button14);
            this.Controls.Add(this.button10);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.button12);
            this.Controls.Add(this.button13);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.title);
            this.Controls.Add(this.button19);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.Text = "Death Calc";
            this.Load += new System.EventHandler(this.Form_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private void Form_Load(object sender, EventArgs e)
        {
            title.Font = new Font("Arial", 13, FontStyle.Bold);
            title.Text = title.Text + " - (made by Ishan Surana [220911478])";
            title.Location = new Point(30, 20);
            button19.FlatStyle = FlatStyle.Flat;
            button19.FlatAppearance.BorderSize = 0;
            button19.BackColor = System.Drawing.Color.Black;
        }

        private void Unlock(object sender, EventArgs e)
        {
            title.Font = new Font("Old English Text MT", 30, FontStyle.Bold);
            title.Text = "Calculator";
            title.Location = new Point(140, 20);
        }

        private void Initialize_Component()
        {
            this.title = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.button15 = new System.Windows.Forms.Button();
            this.button16 = new System.Windows.Forms.Button();
            this.button17 = new System.Windows.Forms.Button();
            this.ans = new System.Windows.Forms.TextBox();
            this.button18 = new System.Windows.Forms.Button();
            this.button14 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.Font = new System.Drawing.Font("Old English Text MT", 30F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.title.ForeColor = System.Drawing.Color.White;
            this.title.Location = new System.Drawing.Point(90, 9);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(186, 48);
            this.title.TabIndex = 0;
            this.title.Text = "Calculator";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.DodgerBlue;
            this.button1.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button1.FlatAppearance.BorderSize = 5;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(27, 135);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(43, 38);
            this.button1.TabIndex = 2;
            this.button1.Text = "9";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.DodgerBlue;
            this.button2.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button2.FlatAppearance.BorderSize = 5;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ForeColor = System.Drawing.Color.White;
            this.button2.Location = new System.Drawing.Point(85, 135);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(43, 38);
            this.button2.TabIndex = 3;
            this.button2.Text = "8";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.DodgerBlue;
            this.button3.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button3.FlatAppearance.BorderSize = 5;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ForeColor = System.Drawing.Color.White;
            this.button3.Location = new System.Drawing.Point(146, 135);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(43, 38);
            this.button3.TabIndex = 4;
            this.button3.Text = "7";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.DodgerBlue;
            this.button4.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button4.FlatAppearance.BorderSize = 5;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.ForeColor = System.Drawing.Color.White;
            this.button4.Location = new System.Drawing.Point(146, 189);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(43, 38);
            this.button4.TabIndex = 7;
            this.button4.Text = "4";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.DodgerBlue;
            this.button5.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button5.FlatAppearance.BorderSize = 5;
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.ForeColor = System.Drawing.Color.White;
            this.button5.Location = new System.Drawing.Point(85, 189);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(43, 38);
            this.button5.TabIndex = 6;
            this.button5.Text = "5";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.DodgerBlue;
            this.button6.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button6.FlatAppearance.BorderSize = 5;
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.ForeColor = System.Drawing.Color.White;
            this.button6.Location = new System.Drawing.Point(27, 189);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(43, 38);
            this.button6.TabIndex = 5;
            this.button6.Text = "6";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.BackColor = System.Drawing.Color.DodgerBlue;
            this.button7.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button7.FlatAppearance.BorderSize = 5;
            this.button7.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button7.ForeColor = System.Drawing.Color.White;
            this.button7.Location = new System.Drawing.Point(146, 244);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(43, 38);
            this.button7.TabIndex = 10;
            this.button7.Text = "1";
            this.button7.UseVisualStyleBackColor = false;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.DodgerBlue;
            this.button8.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button8.FlatAppearance.BorderSize = 5;
            this.button8.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button8.ForeColor = System.Drawing.Color.White;
            this.button8.Location = new System.Drawing.Point(85, 244);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(43, 38);
            this.button8.TabIndex = 9;
            this.button8.Text = "2";
            this.button8.UseVisualStyleBackColor = false;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.Color.DodgerBlue;
            this.button9.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button9.FlatAppearance.BorderSize = 5;
            this.button9.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button9.ForeColor = System.Drawing.Color.White;
            this.button9.Location = new System.Drawing.Point(27, 244);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(43, 38);
            this.button9.TabIndex = 8;
            this.button9.Text = "3";
            this.button9.UseVisualStyleBackColor = false;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button10
            // 
            this.button10.BackColor = System.Drawing.Color.Yellow;
            this.button10.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button10.FlatAppearance.BorderSize = 5;
            this.button10.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button10.Location = new System.Drawing.Point(296, 187);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(43, 38);
            this.button10.TabIndex = 14;
            this.button10.Text = "/";
            this.button10.UseVisualStyleBackColor = false;
            this.button10.Click += new System.EventHandler(this.button10_Click);
            // 
            // button11
            // 
            this.button11.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.button11.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button11.FlatAppearance.BorderSize = 5;
            this.button11.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button11.Location = new System.Drawing.Point(235, 187);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(43, 38);
            this.button11.TabIndex = 13;
            this.button11.Text = "*";
            this.button11.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button11.UseVisualStyleBackColor = false;
            this.button11.Click += new System.EventHandler(this.button11_Click);
            // 
            // button12
            // 
            this.button12.BackColor = System.Drawing.Color.SpringGreen;
            this.button12.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button12.FlatAppearance.BorderSize = 5;
            this.button12.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button12.Location = new System.Drawing.Point(296, 135);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(43, 38);
            this.button12.TabIndex = 12;
            this.button12.Text = "-";
            this.button12.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button12.UseVisualStyleBackColor = false;
            this.button12.Click += new System.EventHandler(this.button12_Click);
            // 
            // button13
            // 
            this.button13.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.button13.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button13.FlatAppearance.BorderSize = 5;
            this.button13.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button13.Location = new System.Drawing.Point(235, 135);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(43, 38);
            this.button13.TabIndex = 11;
            this.button13.Text = "+";
            this.button13.UseVisualStyleBackColor = false;
            this.button13.Click += new System.EventHandler(this.button13_Click);
            // 
            // button15
            // 
            this.button15.BackColor = System.Drawing.Color.BlueViolet;
            this.button15.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button15.FlatAppearance.BorderSize = 5;
            this.button15.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button15.ForeColor = System.Drawing.Color.White;
            this.button15.Location = new System.Drawing.Point(296, 239);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(43, 38);
            this.button15.TabIndex = 17;
            this.button15.Text = "AC";
            this.button15.UseVisualStyleBackColor = false;
            this.button15.Click += new System.EventHandler(this.button15_Click);
            // 
            // button16
            // 
            this.button16.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.button16.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button16.FlatAppearance.BorderSize = 5;
            this.button16.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button16.Location = new System.Drawing.Point(235, 239);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(43, 38);
            this.button16.TabIndex = 16;
            this.button16.Text = "^";
            this.button16.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button16.UseVisualStyleBackColor = false;
            this.button16.Click += new System.EventHandler(this.button16_Click);
            // 
            // button17
            // 
            this.button17.BackColor = System.Drawing.Color.DodgerBlue;
            this.button17.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button17.FlatAppearance.BorderSize = 5;
            this.button17.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button17.ForeColor = System.Drawing.Color.White;
            this.button17.Location = new System.Drawing.Point(85, 294);
            this.button17.Name = "button17";
            this.button17.Size = new System.Drawing.Size(43, 38);
            this.button17.TabIndex = 18;
            this.button17.Text = "0";
            this.button17.UseVisualStyleBackColor = false;
            this.button17.Click += new System.EventHandler(this.button17_Click);
            // 
            // ans
            // 
            this.ans.Font = new System.Drawing.Font("Britannic Bold", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ans.Location = new System.Drawing.Point(32, 70);
            this.ans.Name = "ans";
            this.ans.Size = new System.Drawing.Size(300, 37);
            this.ans.TabIndex = 19;
            this.ans.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // button18
            // 
            this.button18.BackColor = System.Drawing.Color.Chartreuse;
            this.button18.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.button18.FlatAppearance.BorderSize = 5;
            this.button18.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button18.Location = new System.Drawing.Point(235, 291);
            this.button18.Name = "button18";
            this.button18.Size = new System.Drawing.Size(43, 38);
            this.button18.TabIndex = 20;
            this.button18.Text = "<=";
            this.button18.UseVisualStyleBackColor = false;
            this.button18.Click += new System.EventHandler(this.button18_Click);
            // 
            // button14
            // 
            this.button14.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.button14.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button14.ForeColor = System.Drawing.Color.White;
            this.button14.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button14.Location = new System.Drawing.Point(296, 291);
            this.button14.Name = "button14";
            this.button14.Size = new System.Drawing.Size(43, 38);
            this.button14.TabIndex = 15;
            this.button14.Text = "=";
            this.button14.UseVisualStyleBackColor = false;
            this.button14.Click += new System.EventHandler(this.button14_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(362, 346);
            this.Controls.Add(this.button18);
            this.Controls.Add(this.ans);
            this.Controls.Add(this.button17);
            this.Controls.Add(this.button15);
            this.Controls.Add(this.button16);
            this.Controls.Add(this.button14);
            this.Controls.Add(this.button10);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.button12);
            this.Controls.Add(this.button13);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.title);
            this.Name = "Form1";
            this.Text = "Death Calc";
            this.Load += new System.EventHandler(this.Form_Load);
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Label title;
        private System.Windows.Forms.Button button17;
        private System.Windows.Forms.TextBox ans;
        private System.Windows.Forms.Button button18;
        private System.Windows.Forms.Button button14;
        private Button button19;
        private Button button1;
        private Button button2;
        private Button button3;
        private Button button6;
        private Button button5;
        private Button button4;
        private Button button9;
        private Button button8;
        private Button button7;
        private Button button13;
        private Button button12;
        private Button button11;
        private Button button10;
        private Button button16;
        private Button button15;
        private Button button20;
        private Button button21;
        private Button button22;
        private Button button23;
        private Button button24;
        private Button button25;
        private Button button26;
    }
}