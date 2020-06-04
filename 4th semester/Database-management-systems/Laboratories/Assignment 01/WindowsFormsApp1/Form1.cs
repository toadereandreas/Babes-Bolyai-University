using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the '_Lab01_PharmacyDataSet1.Medications' table. You can move, or remove it, as needed.
            this.medicationsTableAdapter.Fill(this._Lab01_PharmacyDataSet1.Medications);
            // TODO: This line of code loads data into the '_Lab01_PharmacyDataSet.Suppliers' table. You can move, or remove it, as needed.
            this.suppliersTableAdapter.Fill(this._Lab01_PharmacyDataSet.Suppliers);

        }

        private void DataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                // Initialize the DataSet.
                dataSet = new DataSet();
                dataSet.Locale = CultureInfo.InvariantCulture;

                // Create the connection string for the AdventureWorks sample database.
                string connectionString = "Data Source=localhost;Initial Catalog=AdventureWorks;"
                    + "Integrated Security=true;";

                // Create the command strings for querying the Contact table.
                string contactSelectCommand = "SELECT ContactID, Title, FirstName, LastName, EmailAddress, Phone FROM Person.Contact";

                // Create the contacts data adapter.
                contactsDataAdapter = new SqlDataAdapter(
                    contactSelectCommand,
                    connectionString);

                // Create a command builder to generate SQL update, insert, and
                // delete commands based on the contacts select command. These are used to
                // update the database.
                SqlCommandBuilder contactsCommandBuilder = new SqlCommandBuilder(contactsDataAdapter);

                // Fill the data set with the contact information.
                contactsDataAdapter.Fill(dataSet, "Contact");
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
