using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
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
            // Initialize group boxes text
            this.groupBox1.Text = this._Lab01_PharmacyDataSet.Suppliers.TableName;
            this.groupBox2.Text = this._Lab01_PharmacyDataSet1.Medications.TableName;
            this.clearCRUDOperationsTextBoxes();
        }

        private void clearCRUDOperationsTextBoxes()
        {
            try
            {
                this.midTextBox.Text = "";
                this.sidTextBox.Text = "";
                this.refTextBox.Text = "";
                this.nameTextBox.Text = "";
                this.costTextBox.Text = "";
                this.descriptionTextBox.Text = "";
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void validateTextBoxesFields()
        {
            if (this.midTextBox.Text == "")
                throw new Exception("mid textBox is empty!");
            if (this.sidTextBox.Text == "")
                throw new Exception("sid textBox is empty!");
            if (this.refTextBox.Text == "")
                throw new Exception("ref textBox is empty!");
            if (this.nameTextBox.Text == "")
                throw new Exception("name textBox is empty!");
            if (this.descriptionTextBox.Text == "")
                throw new Exception("description textBox is empty!");
            if (this.costTextBox.Text == "")
                throw new Exception("cost textBox is empty!");
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string currentCellString = dataGridView1.Rows[dataGridView1.CurrentCell.RowIndex].Cells[dataGridView1.CurrentCell.ColumnIndex].Value.ToString();
                int supplierId = -1;

                if (Int32.TryParse(currentCellString, out supplierId))
                {
                    this.showMedicineOfGivenSuppplierId(supplierId);
                    this.clearCRUDOperationsTextBoxes();
                }
                else
                {
                    this.showMedicineOfGivenSuppplierName(currentCellString);
                    this.clearCRUDOperationsTextBoxes();
                }
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        
        private void showMedicineOfGivenSuppplierName(string _supplierName)
        {
            try
            {
                this.medicationsTableAdapter.FillByGivenName(this._Lab01_PharmacyDataSet1.Medications, _supplierName);
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void showMedicineOfGivenSuppplierId( int _supplierId)
        {
            try
            {
                this.medicationsTableAdapter.FillByGivenSid(this._Lab01_PharmacyDataSet1.Medications, Convert.ToByte(_supplierId));
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void showAllMedications_Click(object sender, EventArgs e)
        {
            try
            {
                this.medicationsTableAdapter.Fill(this._Lab01_PharmacyDataSet1.Medications);
                this.clearCRUDOperationsTextBoxes();
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void insertMedicineButton_Click(object sender, EventArgs e)
        {
            try
            {
                int mid = Int32.Parse(this.midTextBox.Text);
                int sid = Int32.Parse(this.sidTextBox.Text);
                string _ref = this.refTextBox.Text;
                string name = this.nameTextBox.Text;
                int cost = Int32.Parse(this.costTextBox.Text);
                string description = this.descriptionTextBox.Text;
                this.medicationsTableAdapter.InsertQuery
                this.medicationsTableAdapter.InsertQuery(Convert.ToByte(mid), Convert.ToByte(sid), _ref, name, cost, description);
                this.medicationsTableAdapter.Fill(this._Lab01_PharmacyDataSet1.Medications);
                this.clearCRUDOperationsTextBoxes();
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void clearTextBoxesButton_Click(object sender, EventArgs e)
        {
            try
            { 
                this.clearCRUDOperationsTextBoxes();
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void deleteSelectedMedicineButton_Click(object sender, EventArgs e)
        {
            try
            {
                string currentCellString = this.dataGridView2.Rows[dataGridView2.CurrentCell.RowIndex].Cells[dataGridView2.CurrentCell.ColumnIndex].Value.ToString();
                int medicineId = 0;
                if (Int32.TryParse(currentCellString, out medicineId))
                {
                    this.medicationsTableAdapter.DeleteQuery(Convert.ToByte(medicineId));
                    this.medicationsTableAdapter.Fill(this._Lab01_PharmacyDataSet1.Medications);
                    this.clearCRUDOperationsTextBoxes();
                }
                else MessageBox.Show("Can not convert the value of the current cell to int!");
            } catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }

        private void updateMedicationButton_Click(object sender, EventArgs e)
        {
            try
            {
                int mid = Int32.Parse(this.midTextBox.Text);
                int sid = Int32.Parse(this.sidTextBox.Text);
                string _ref = this.refTextBox.Text;
                string name = this.nameTextBox.Text;
                int cost = Int32.Parse(this.costTextBox.Text);
                string description = this.descriptionTextBox.Text;
                this.medicationsTableAdapter.UpdateQuery(Convert.ToByte(mid), Convert.ToByte(sid), _ref, name, cost, description);
                this.medicationsTableAdapter.Fill(this._Lab01_PharmacyDataSet1.Medications);
                this.clearCRUDOperationsTextBoxes();
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.ToString());
            }
        }
    }
}
