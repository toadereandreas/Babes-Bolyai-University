using System;
using System.Data;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        // Establish the connection
        SqlConnection dbConn;

        // In order to bring the data
        SqlDataAdapter daManufacturers, daModels;

        // Fill with data from the database
        DataSet ds;

        // To generate insert, update, delete commands
        SqlCommandBuilder cbModels;

        BindingSource bsManufacturers, bsModels;

        private void Button1_Click(object sender, EventArgs e)
        {
            // in order to send our changes to the database when clicked
            daModels.Update(ds, "Models");
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Instantiate binding sources
            bsManufacturers = new BindingSource();
            bsModels = new BindingSource();

            // Bind the dataGridView to the binding sources
            dgvManufacturers.DataSource = bsManufacturers;
            dgvModels.DataSource = bsModels;

            // Instantiate the connection object
            // Integrated security is true to specify that we're using the current windows account credentials
            dbConn = new SqlConnection("Data Source = DESKTOP-A70AQJO\\SQLEXPRESS;" +
                " Initial Catalog = pizzaDb; Integrated Security = true");

            // Instantiatae the dataSet and dataAdapters
            ds = new DataSet();

            daManufacturers = new SqlDataAdapter("SELECT * FROM DroneManufacturers", dbConn);
            daModels = new SqlDataAdapter("SELECT * FROM DroneModels", dbConn);

            cbModels = new SqlCommandBuilder(daModels);

            // We'll have 2 tables in the data adapters called Manufacturers and Models containing all the rows
            // from the db for the respective table
            daManufacturers.Fill(ds, "Manufacturers");
            daModels.Fill(ds, "Models");

            // We will represent the relation using a Relation object
            DataRelation dr = new DataRelation("ManufacturersModels",
                ds.Tables["Manufacturers"].Columns["dmid"], // the parent column
                ds.Tables["Models"].Columns["dmid"]);   // the child column

            ds.Relations.Add(dr); // We add the relation to the dataSet

            // We specify the binding details for the binding sources
            bsManufacturers.DataSource = ds;
            bsManufacturers.DataMember = "Manufacturers";

            bsModels.DataSource = bsManufacturers;
            // We specify the relation by name in order to filter
            bsModels.DataMember = "ManufacturersModels";
        }
    }
}
