using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Oracle.DataAccess.Client;
using Oracle.DataAccess.Types;
using System.Data.SqlClient;
using System.Configuration;   

namespace Insurance
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String oradb = "DATA SOURCE=172.16.54.24:1521/ictorcl;USER ID=IT478;Password=student";
            OracleConnection conn = new OracleConnection(oradb);
            conn.Open();
            OracleDataAdapter da;
            DataSet ds;
            DataTable dt;
            DataRow dr;
            int i = 0;
            MessageBox.Show("Connected");

            OracleCommand command1 = conn.CreateCommand();
            command1.CommandText = "select name as Owner, count(report_number) as No_Of_Accidents, sum(damage_amount) as total_damage from person, participated where person.driver_id = participated.driver_id group by(person.driver_id,name)";
            command1.CommandType = CommandType.Text;

            ds = new DataSet();
            da = new OracleDataAdapter(command1.CommandText, conn);
            da.Fill(ds, "Accident");
            dt = ds.Tables["Accident"];
            int t = dt.Rows.Count;
            MessageBox.Show(t.ToString());
            textBox1.Text = "";
            for (i = 0; i < t; i++)
            {
                dr = dt.Rows[i];
                string owner = dr["owner"].ToString();
                string noa = dr["no_of_accidents"].ToString();
                string td = dr["total_damage"].ToString();
                string line = owner + ", " + noa + ", " + td + "\r\n";
                textBox1.AppendText(line);
            }

            OracleDataReader reader = command1.ExecuteReader();
            dataGridView1.DataSource = reader;
            dataGridView1.DataBind();
            command1.Dispose();
            conn.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'dataSet1.ACCIDENT' table. You can move, or remove it, as needed.
            this.aCCIDENTTableAdapter.Fill(this.dataSet1.ACCIDENT);

        }
    }
}
