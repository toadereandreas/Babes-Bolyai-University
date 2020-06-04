using System.Configuration;
using System.Collections.Specialized;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace lab1DBMS
{
    public partial class Form1 : Form
    {

        SqlConnection dbConn;
        SqlDataAdapter daTable1, daTable2;
        DataSet ds;
        SqlCommandBuilder cb;
        BindingSource bsTable1, bsTable2;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            daTable2.Update(ds, "Table2");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string serverName = ConfigurationManager.AppSettings.Get("server");
            string databaseName = ConfigurationManager.AppSettings.Get("database"); ;
            dbConn = new SqlConnection("Server="+serverName+";Database="+databaseName+";Trusted_Connection=True");
            ds = new DataSet();
            string table1 = ConfigurationManager.AppSettings.Get("table1");
            string table2 = ConfigurationManager.AppSettings.Get("table2");
            daTable1 = new SqlDataAdapter("SELECT * FROM " + table1, dbConn);
            daTable2 = new SqlDataAdapter("SELECT * FROM " + table2, dbConn);
            cb = new SqlCommandBuilder(daTable2);
            daTable1.Fill(ds, "Table1");
            daTable2.Fill(ds, "Table2");
            string fk = ConfigurationManager.AppSettings.Get("fk");
            DataRelation dr = new DataRelation("FK_Table1_Table2",
                ds.Tables["Table1"].Columns[fk],
                ds.Tables["Table2"].Columns[fk]);
            ds.Relations.Add(dr);

            bsTable1 = new BindingSource();
            bsTable1.DataSource = ds;
            bsTable1.DataMember = "Table1";
            bsTable2 = new BindingSource();
            bsTable2.DataSource = bsTable1;
            bsTable2.DataMember = "FK_Table1_Table2";
            dgvCountries.DataSource = bsTable1;
            dgvParticipants.DataSource = bsTable2;
        }
    }
}
