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
    partial class Form1
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
            title = new Label();
            button17 = new Button();
            ans = new TextBox();
            button18 = new Button();
            button14 = new Button();
            button19 = new Button();
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button6 = new Button();
            button5 = new Button();
            button4 = new Button();
            button9 = new Button();
            button8 = new Button();
            button7 = new Button();
            button13 = new Button();
            button12 = new Button();
            button11 = new Button();
            button10 = new Button();
            button16 = new Button();
            button15 = new Button();
            SuspendLayout();
            // 
            // title
            // 
            title.AutoSize = true;
            title.Font = new Font("Old English Text MT", 30F, FontStyle.Bold, GraphicsUnit.Point, 0);
            title.ForeColor = Color.White;
            title.Location = new Point(120, 11);
            title.Margin = new Padding(4, 0, 4, 0);
            title.Name = "title";
            title.Size = new Size(243, 60);
            title.TabIndex = 0;
            title.Text = "Calculator";
            // 
            // button17
            // 
            button17.BackColor = Color.DodgerBlue;
            button17.FlatAppearance.BorderColor = Color.Black;
            button17.FlatAppearance.BorderSize = 5;
            button17.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button17.ForeColor = Color.White;
            button17.Location = new Point(113, 362);
            button17.Margin = new Padding(4, 5, 4, 5);
            button17.Name = "button17";
            button17.Size = new Size(57, 47);
            button17.TabIndex = 18;
            button17.Text = "0";
            button17.UseVisualStyleBackColor = false;
            button17.Click += button17_Click;
            // 
            // ans
            // 
            ans.Font = new Font("Britannic Bold", 20.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            ans.Location = new Point(43, 86);
            ans.Margin = new Padding(4, 5, 4, 5);
            ans.Name = "ans";
            ans.Size = new Size(399, 45);
            ans.TabIndex = 19;
            ans.TextAlign = HorizontalAlignment.Center;
            // 
            // button18
            // 
            button18.BackColor = Color.Chartreuse;
            button18.FlatAppearance.BorderColor = Color.Black;
            button18.FlatAppearance.BorderSize = 5;
            button18.Font = new Font("Microsoft Sans Serif", 13F, FontStyle.Bold, GraphicsUnit.Point, 0);
            button18.Location = new Point(313, 358);
            button18.Margin = new Padding(4, 5, 4, 5);
            button18.Name = "button18";
            button18.Size = new Size(57, 47);
            button18.TabIndex = 20;
            button18.Text = "<=";
            button18.UseVisualStyleBackColor = false;
            button18.Click += button18_Click;
            button18.MouseHover += hovering;
            button18.MouseLeave += dehovering;
            // 
            // button14
            // 
            button14.BackColor = Color.FromArgb(255, 128, 0);
            button14.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button14.ForeColor = Color.White;
            button14.ImageAlign = ContentAlignment.TopCenter;
            button14.Location = new Point(395, 358);
            button14.Margin = new Padding(4, 5, 4, 5);
            button14.Name = "button14";
            button14.Size = new Size(57, 47);
            button14.TabIndex = 15;
            button14.Text = "=";
            button14.UseVisualStyleBackColor = false;
            button14.Click += button14_Click;
            // 
            // button19
            // 
            button19.Location = new Point(263, 45);
            button19.Margin = new Padding(4, 5, 4, 5);
            button19.Name = "button19";
            button19.Size = new Size(13, 26);
            button19.TabIndex = 21;
            button19.UseVisualStyleBackColor = true;
            button19.Click += Unlock;
            // 
            // button1
            // 
            button1.BackColor = Color.DodgerBlue;
            button1.FlatAppearance.BorderColor = Color.Black;
            button1.FlatAppearance.BorderSize = 5;
            button1.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button1.ForeColor = Color.White;
            button1.Location = new Point(36, 166);
            button1.Margin = new Padding(4, 5, 4, 5);
            button1.Name = "button1";
            button1.Size = new Size(57, 47);
            button1.TabIndex = 2;
            button1.Text = "9";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.DodgerBlue;
            button2.FlatAppearance.BorderColor = Color.Black;
            button2.FlatAppearance.BorderSize = 5;
            button2.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button2.ForeColor = Color.White;
            button2.Location = new Point(113, 166);
            button2.Margin = new Padding(4, 5, 4, 5);
            button2.Name = "button2";
            button2.Size = new Size(57, 47);
            button2.TabIndex = 3;
            button2.Text = "8";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.BackColor = Color.DodgerBlue;
            button3.FlatAppearance.BorderColor = Color.Black;
            button3.FlatAppearance.BorderSize = 5;
            button3.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button3.ForeColor = Color.White;
            button3.Location = new Point(195, 166);
            button3.Margin = new Padding(4, 5, 4, 5);
            button3.Name = "button3";
            button3.Size = new Size(57, 47);
            button3.TabIndex = 4;
            button3.Text = "7";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // button6
            // 
            button6.BackColor = Color.DodgerBlue;
            button6.FlatAppearance.BorderColor = Color.Black;
            button6.FlatAppearance.BorderSize = 5;
            button6.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button6.ForeColor = Color.White;
            button6.Location = new Point(36, 233);
            button6.Margin = new Padding(4, 5, 4, 5);
            button6.Name = "button6";
            button6.Size = new Size(57, 47);
            button6.TabIndex = 5;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = false;
            button6.Click += button6_Click;
            // 
            // button5
            // 
            button5.BackColor = Color.DodgerBlue;
            button5.FlatAppearance.BorderColor = Color.Black;
            button5.FlatAppearance.BorderSize = 5;
            button5.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button5.ForeColor = Color.White;
            button5.Location = new Point(113, 233);
            button5.Margin = new Padding(4, 5, 4, 5);
            button5.Name = "button5";
            button5.Size = new Size(57, 47);
            button5.TabIndex = 6;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = false;
            button5.Click += button5_Click;
            // 
            // button4
            // 
            button4.BackColor = Color.DodgerBlue;
            button4.FlatAppearance.BorderColor = Color.Black;
            button4.FlatAppearance.BorderSize = 5;
            button4.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button4.ForeColor = Color.White;
            button4.Location = new Point(195, 233);
            button4.Margin = new Padding(4, 5, 4, 5);
            button4.Name = "button4";
            button4.Size = new Size(57, 47);
            button4.TabIndex = 7;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // button9
            // 
            button9.BackColor = Color.DodgerBlue;
            button9.FlatAppearance.BorderColor = Color.Black;
            button9.FlatAppearance.BorderSize = 5;
            button9.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button9.ForeColor = Color.White;
            button9.Location = new Point(36, 300);
            button9.Margin = new Padding(4, 5, 4, 5);
            button9.Name = "button9";
            button9.Size = new Size(57, 47);
            button9.TabIndex = 8;
            button9.Text = "3";
            button9.UseVisualStyleBackColor = false;
            button9.Click += button9_Click;
            // 
            // button8
            // 
            button8.BackColor = Color.DodgerBlue;
            button8.FlatAppearance.BorderColor = Color.Black;
            button8.FlatAppearance.BorderSize = 5;
            button8.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button8.ForeColor = Color.White;
            button8.Location = new Point(113, 300);
            button8.Margin = new Padding(4, 5, 4, 5);
            button8.Name = "button8";
            button8.Size = new Size(57, 47);
            button8.TabIndex = 9;
            button8.Text = "2";
            button8.UseVisualStyleBackColor = false;
            button8.Click += button8_Click;
            // 
            // button7
            // 
            button7.BackColor = Color.DodgerBlue;
            button7.FlatAppearance.BorderColor = Color.Black;
            button7.FlatAppearance.BorderSize = 5;
            button7.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button7.ForeColor = Color.White;
            button7.Location = new Point(195, 300);
            button7.Margin = new Padding(4, 5, 4, 5);
            button7.Name = "button7";
            button7.Size = new Size(57, 47);
            button7.TabIndex = 10;
            button7.Text = "1";
            button7.UseVisualStyleBackColor = false;
            button7.Click += button7_Click;
            // 
            // button13
            // 
            button13.BackColor = Color.FromArgb(255, 128, 128);
            button13.FlatAppearance.BorderColor = Color.Black;
            button13.FlatAppearance.BorderSize = 5;
            button13.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button13.Location = new Point(313, 166);
            button13.Margin = new Padding(4, 5, 4, 5);
            button13.Name = "button13";
            button13.Size = new Size(57, 47);
            button13.TabIndex = 11;
            button13.Text = "+";
            button13.UseVisualStyleBackColor = false;
            button13.Click += button13_Click;
            // 
            // button12
            // 
            button12.BackColor = Color.SpringGreen;
            button12.FlatAppearance.BorderColor = Color.Black;
            button12.FlatAppearance.BorderSize = 5;
            button12.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button12.Location = new Point(395, 166);
            button12.Margin = new Padding(4, 5, 4, 5);
            button12.Name = "button12";
            button12.Size = new Size(57, 47);
            button12.TabIndex = 12;
            button12.Text = "-";
            button12.TextAlign = ContentAlignment.TopCenter;
            button12.UseVisualStyleBackColor = false;
            button12.Click += button12_Click;
            // 
            // button11
            // 
            button11.BackColor = Color.FromArgb(192, 255, 255);
            button11.FlatAppearance.BorderColor = Color.Black;
            button11.FlatAppearance.BorderSize = 5;
            button11.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button11.Location = new Point(313, 230);
            button11.Margin = new Padding(4, 5, 4, 5);
            button11.Name = "button11";
            button11.Size = new Size(57, 47);
            button11.TabIndex = 13;
            button11.Text = "*";
            button11.TextAlign = ContentAlignment.BottomCenter;
            button11.UseVisualStyleBackColor = false;
            button11.Click += button11_Click;
            // 
            // button10
            // 
            button10.BackColor = Color.Yellow;
            button10.FlatAppearance.BorderColor = Color.Black;
            button10.FlatAppearance.BorderSize = 5;
            button10.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button10.Location = new Point(395, 230);
            button10.Margin = new Padding(4, 5, 4, 5);
            button10.Name = "button10";
            button10.Size = new Size(57, 47);
            button10.TabIndex = 14;
            button10.Text = "/";
            button10.UseVisualStyleBackColor = false;
            button10.Click += button10_Click;
            // 
            // button16
            // 
            button16.BackColor = Color.FromArgb(255, 128, 255);
            button16.FlatAppearance.BorderColor = Color.Black;
            button16.FlatAppearance.BorderSize = 5;
            button16.Font = new Font("Microsoft Sans Serif", 20F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button16.Location = new Point(313, 293);
            button16.Margin = new Padding(4, 5, 4, 5);
            button16.Name = "button16";
            button16.Size = new Size(57, 47);
            button16.TabIndex = 16;
            button16.Text = "^";
            button16.TextAlign = ContentAlignment.BottomCenter;
            button16.UseVisualStyleBackColor = false;
            button16.Click += button16_Click;
            // 
            // button15
            // 
            button15.BackColor = Color.BlueViolet;
            button15.FlatAppearance.BorderColor = Color.Black;
            button15.FlatAppearance.BorderSize = 5;
            button15.Font = new Font("Microsoft Sans Serif", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            button15.ForeColor = Color.White;
            button15.Location = new Point(395, 293);
            button15.Margin = new Padding(4, 5, 4, 5);
            button15.Name = "button15";
            button15.Size = new Size(57, 47);
            button15.TabIndex = 17;
            button15.Text = "AC";
            button15.UseVisualStyleBackColor = false;
            button15.Click += button15_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaptionText;
            ClientSize = new Size(483, 426);
            Controls.Add(title);
            Controls.Add(button19);
            Controls.Add(button18);
            Controls.Add(ans);
            Controls.Add(button17);
            Controls.Add(button15);
            Controls.Add(button16);
            Controls.Add(button14);
            Controls.Add(button10);
            Controls.Add(button11);
            Controls.Add(button12);
            Controls.Add(button13);
            Controls.Add(button7);
            Controls.Add(button8);
            Controls.Add(button9);
            Controls.Add(button4);
            Controls.Add(button5);
            Controls.Add(button6);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Margin = new Padding(4, 5, 4, 5);
            Name = "Form1";
            Text = "Death Calc";
            Load += Form_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        private void Form_Load(object sender, EventArgs e)
        {
            title.Font = new Font("Arial", 15, FontStyle.Bold);
            title.Text = title.Text + " - (made by Ishan Surana)";
            title.Location = new Point(30, 30);
            button19.FlatStyle = FlatStyle.Flat;
            button19.FlatAppearance.BorderSize = 0;
            button19.BackColor = System.Drawing.Color.Black;
        }
        private void Unlock(object sender, EventArgs e)
        {
            title.Font = new Font("Old English Text MT", 30, FontStyle.Bold);
            title.Text = "Calculator";
            title.Location = new Point(120, 9);
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
    }
}