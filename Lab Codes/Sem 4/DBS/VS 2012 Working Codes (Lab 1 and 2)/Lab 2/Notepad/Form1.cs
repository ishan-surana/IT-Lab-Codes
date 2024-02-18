using System;
using System.Drawing;
using System.Windows.Forms;

namespace Notepad
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void selectAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectAll();
        }

        private void boldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!richTextBox1.SelectionFont.Bold) richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Bold);
            else richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Regular);
        }

        private void italicsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!richTextBox1.SelectionFont.Italic) richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Italic);
            else richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Regular);
        }

        private void underlinedToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!richTextBox1.SelectionFont.Underline) richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Underline);
            else richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Regular);
        }

        private void strikethrough_Click(object sender, EventArgs e)
        {
            if (!richTextBox1.SelectionFont.Strikeout) richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Strikeout);
            else richTextBox1.SelectionFont = new Font(richTextBox1.Font, FontStyle.Regular);
        }

        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Undo();
        }

        private void redoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Redo();
        }

        private void zoomInToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.ZoomFactor = 1.25f * richTextBox1.ZoomFactor;
        }

        private void zoomOutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.ZoomFactor = 0.8f * richTextBox1.ZoomFactor;
        }

        private void wordWrapToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.WordWrap = !richTextBox1.WordWrap;
            wordWrapToolStripMenuItem.Checked = !wordWrapToolStripMenuItem.Checked;
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Form1().ShowDialog();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "Rich Text Format (*.rtf)|*.rtf";
            if (save.ShowDialog() == DialogResult.OK)
            {
                this.richTextBox1.SaveFile(save.FileName);
                this.Text = save.FileName + " - Notepad";
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            if (open.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.LoadFile(open.FileName, RichTextBoxStreamType.RichText);
                this.Text = open.FileName + " - Notepad";
            }
        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog colors = new ColorDialog();
            if (colors.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SelectionColor = colors.Color;
            }
        }
    }
}
