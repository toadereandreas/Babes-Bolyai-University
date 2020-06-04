namespace WindowsFormsApp2
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Label midLabel;
            System.Windows.Forms.Label sidLabel;
            System.Windows.Forms.Label refLabel;
            System.Windows.Forms.Label nameLabel;
            System.Windows.Forms.Label costLabel;
            System.Windows.Forms.Label descriptionLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.sidDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.hasContractDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.suppliersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this._Lab01_PharmacyDataSet = new WindowsFormsApp2._Lab01_PharmacyDataSet();
            this.suppliersTableAdapter = new WindowsFormsApp2._Lab01_PharmacyDataSetTableAdapters.SuppliersTableAdapter();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.midDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sidDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.refDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nameDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.costDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.descriptionDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.medicationsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this._Lab01_PharmacyDataSet1 = new WindowsFormsApp2._Lab01_PharmacyDataSet1();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button1 = new System.Windows.Forms.Button();
            this.showAllMedications = new System.Windows.Forms.Button();
            this.midTextBox = new System.Windows.Forms.TextBox();
            this.sidTextBox = new System.Windows.Forms.TextBox();
            this.refTextBox = new System.Windows.Forms.TextBox();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.costTextBox = new System.Windows.Forms.TextBox();
            this.descriptionTextBox = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.clearTextBoxesButton = new System.Windows.Forms.Button();
            this.insertMedicineButton = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.updateMedicationButton = new System.Windows.Forms.Button();
            this.deleteSelectedMedicineButton = new System.Windows.Forms.Button();
            this.medicationsTableAdapter = new WindowsFormsApp2._Lab01_PharmacyDataSet1TableAdapters.MedicationsTableAdapter();
            this.tableAdapterManager = new WindowsFormsApp2._Lab01_PharmacyDataSet1TableAdapters.TableAdapterManager();
            midLabel = new System.Windows.Forms.Label();
            sidLabel = new System.Windows.Forms.Label();
            refLabel = new System.Windows.Forms.Label();
            nameLabel = new System.Windows.Forms.Label();
            costLabel = new System.Windows.Forms.Label();
            descriptionLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.suppliersBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._Lab01_PharmacyDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.medicationsBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._Lab01_PharmacyDataSet1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // midLabel
            // 
            midLabel.AutoSize = true;
            midLabel.Location = new System.Drawing.Point(15, 22);
            midLabel.Name = "midLabel";
            midLabel.Size = new System.Drawing.Size(26, 13);
            midLabel.TabIndex = 5;
            midLabel.Text = "mid:";
            // 
            // sidLabel
            // 
            sidLabel.AutoSize = true;
            sidLabel.Location = new System.Drawing.Point(15, 48);
            sidLabel.Name = "sidLabel";
            sidLabel.Size = new System.Drawing.Size(23, 13);
            sidLabel.TabIndex = 7;
            sidLabel.Text = "sid:";
            // 
            // refLabel
            // 
            refLabel.AutoSize = true;
            refLabel.Location = new System.Drawing.Point(15, 74);
            refLabel.Name = "refLabel";
            refLabel.Size = new System.Drawing.Size(22, 13);
            refLabel.TabIndex = 9;
            refLabel.Text = "ref:";
            // 
            // nameLabel
            // 
            nameLabel.AutoSize = true;
            nameLabel.Location = new System.Drawing.Point(15, 100);
            nameLabel.Name = "nameLabel";
            nameLabel.Size = new System.Drawing.Size(36, 13);
            nameLabel.TabIndex = 11;
            nameLabel.Text = "name:";
            // 
            // costLabel
            // 
            costLabel.AutoSize = true;
            costLabel.Location = new System.Drawing.Point(15, 126);
            costLabel.Name = "costLabel";
            costLabel.Size = new System.Drawing.Size(30, 13);
            costLabel.TabIndex = 13;
            costLabel.Text = "cost:";
            // 
            // descriptionLabel
            // 
            descriptionLabel.AutoSize = true;
            descriptionLabel.Location = new System.Drawing.Point(15, 152);
            descriptionLabel.Name = "descriptionLabel";
            descriptionLabel.Size = new System.Drawing.Size(61, 13);
            descriptionLabel.TabIndex = 15;
            descriptionLabel.Text = "description:";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.sidDataGridViewTextBoxColumn,
            this.nameDataGridViewTextBoxColumn,
            this.hasContractDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.suppliersBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(6, 19);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(333, 307);
            this.dataGridView1.TabIndex = 0;
            // 
            // sidDataGridViewTextBoxColumn
            // 
            this.sidDataGridViewTextBoxColumn.DataPropertyName = "sid";
            this.sidDataGridViewTextBoxColumn.HeaderText = "sid";
            this.sidDataGridViewTextBoxColumn.Name = "sidDataGridViewTextBoxColumn";
            this.sidDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nameDataGridViewTextBoxColumn
            // 
            this.nameDataGridViewTextBoxColumn.DataPropertyName = "name";
            this.nameDataGridViewTextBoxColumn.HeaderText = "name";
            this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
            this.nameDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // hasContractDataGridViewTextBoxColumn
            // 
            this.hasContractDataGridViewTextBoxColumn.DataPropertyName = "hasContract";
            this.hasContractDataGridViewTextBoxColumn.HeaderText = "hasContract";
            this.hasContractDataGridViewTextBoxColumn.Name = "hasContractDataGridViewTextBoxColumn";
            this.hasContractDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // suppliersBindingSource
            // 
            this.suppliersBindingSource.DataMember = "Suppliers";
            this.suppliersBindingSource.DataSource = this._Lab01_PharmacyDataSet;
            // 
            // _Lab01_PharmacyDataSet
            // 
            this._Lab01_PharmacyDataSet.DataSetName = "_Lab01_PharmacyDataSet";
            this._Lab01_PharmacyDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // suppliersTableAdapter
            // 
            this.suppliersTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView2
            // 
            this.dataGridView2.AllowUserToAddRows = false;
            this.dataGridView2.AllowUserToDeleteRows = false;
            this.dataGridView2.AutoGenerateColumns = false;
            this.dataGridView2.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView2.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.midDataGridViewTextBoxColumn,
            this.sidDataGridViewTextBoxColumn1,
            this.refDataGridViewTextBoxColumn,
            this.nameDataGridViewTextBoxColumn1,
            this.costDataGridViewTextBoxColumn,
            this.descriptionDataGridViewTextBoxColumn});
            this.dataGridView2.DataSource = this.medicationsBindingSource;
            this.dataGridView2.Location = new System.Drawing.Point(6, 19);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.ReadOnly = true;
            this.dataGridView2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.dataGridView2.RowTemplate.ReadOnly = true;
            this.dataGridView2.Size = new System.Drawing.Size(803, 401);
            this.dataGridView2.TabIndex = 1;
            // 
            // midDataGridViewTextBoxColumn
            // 
            this.midDataGridViewTextBoxColumn.DataPropertyName = "mid";
            this.midDataGridViewTextBoxColumn.HeaderText = "mid";
            this.midDataGridViewTextBoxColumn.Name = "midDataGridViewTextBoxColumn";
            this.midDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // sidDataGridViewTextBoxColumn1
            // 
            this.sidDataGridViewTextBoxColumn1.DataPropertyName = "sid";
            this.sidDataGridViewTextBoxColumn1.HeaderText = "sid";
            this.sidDataGridViewTextBoxColumn1.Name = "sidDataGridViewTextBoxColumn1";
            this.sidDataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // refDataGridViewTextBoxColumn
            // 
            this.refDataGridViewTextBoxColumn.DataPropertyName = "ref";
            this.refDataGridViewTextBoxColumn.HeaderText = "ref";
            this.refDataGridViewTextBoxColumn.Name = "refDataGridViewTextBoxColumn";
            this.refDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nameDataGridViewTextBoxColumn1
            // 
            this.nameDataGridViewTextBoxColumn1.DataPropertyName = "name";
            this.nameDataGridViewTextBoxColumn1.HeaderText = "name";
            this.nameDataGridViewTextBoxColumn1.Name = "nameDataGridViewTextBoxColumn1";
            this.nameDataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // costDataGridViewTextBoxColumn
            // 
            this.costDataGridViewTextBoxColumn.DataPropertyName = "cost";
            this.costDataGridViewTextBoxColumn.HeaderText = "cost";
            this.costDataGridViewTextBoxColumn.Name = "costDataGridViewTextBoxColumn";
            this.costDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // descriptionDataGridViewTextBoxColumn
            // 
            this.descriptionDataGridViewTextBoxColumn.DataPropertyName = "description";
            this.descriptionDataGridViewTextBoxColumn.HeaderText = "description";
            this.descriptionDataGridViewTextBoxColumn.Name = "descriptionDataGridViewTextBoxColumn";
            this.descriptionDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // medicationsBindingSource
            // 
            this.medicationsBindingSource.DataMember = "Medications";
            this.medicationsBindingSource.DataSource = this._Lab01_PharmacyDataSet1;
            // 
            // _Lab01_PharmacyDataSet1
            // 
            this._Lab01_PharmacyDataSet1.DataSetName = "_Lab01_PharmacyDataSet1";
            this._Lab01_PharmacyDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.dataGridView1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(345, 336);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Suppliers table";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.dataGridView2);
            this.groupBox2.Location = new System.Drawing.Point(363, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(818, 426);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Medications table";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(413, 19);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(390, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Show medications from selected supplier";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // showAllMedications
            // 
            this.showAllMedications.Location = new System.Drawing.Point(413, 52);
            this.showAllMedications.Name = "showAllMedications";
            this.showAllMedications.Size = new System.Drawing.Size(390, 23);
            this.showAllMedications.TabIndex = 5;
            this.showAllMedications.Text = "Show all medications";
            this.showAllMedications.UseVisualStyleBackColor = true;
            this.showAllMedications.Click += new System.EventHandler(this.showAllMedications_Click);
            // 
            // midTextBox
            // 
            this.midTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "mid", true));
            this.midTextBox.Location = new System.Drawing.Point(82, 19);
            this.midTextBox.Name = "midTextBox";
            this.midTextBox.Size = new System.Drawing.Size(257, 20);
            this.midTextBox.TabIndex = 6;
            // 
            // sidTextBox
            // 
            this.sidTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "sid", true));
            this.sidTextBox.Location = new System.Drawing.Point(82, 45);
            this.sidTextBox.Name = "sidTextBox";
            this.sidTextBox.Size = new System.Drawing.Size(257, 20);
            this.sidTextBox.TabIndex = 8;
            // 
            // refTextBox
            // 
            this.refTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "ref", true));
            this.refTextBox.Location = new System.Drawing.Point(82, 71);
            this.refTextBox.Name = "refTextBox";
            this.refTextBox.Size = new System.Drawing.Size(257, 20);
            this.refTextBox.TabIndex = 10;
            // 
            // nameTextBox
            // 
            this.nameTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "name", true));
            this.nameTextBox.Location = new System.Drawing.Point(82, 97);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(257, 20);
            this.nameTextBox.TabIndex = 12;
            // 
            // costTextBox
            // 
            this.costTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "cost", true));
            this.costTextBox.Location = new System.Drawing.Point(82, 123);
            this.costTextBox.Name = "costTextBox";
            this.costTextBox.Size = new System.Drawing.Size(257, 20);
            this.costTextBox.TabIndex = 14;
            // 
            // descriptionTextBox
            // 
            this.descriptionTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.medicationsBindingSource, "description", true));
            this.descriptionTextBox.Location = new System.Drawing.Point(82, 149);
            this.descriptionTextBox.Name = "descriptionTextBox";
            this.descriptionTextBox.Size = new System.Drawing.Size(257, 20);
            this.descriptionTextBox.TabIndex = 16;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.midTextBox);
            this.groupBox3.Controls.Add(midLabel);
            this.groupBox3.Controls.Add(this.clearTextBoxesButton);
            this.groupBox3.Controls.Add(this.descriptionTextBox);
            this.groupBox3.Controls.Add(descriptionLabel);
            this.groupBox3.Controls.Add(sidLabel);
            this.groupBox3.Controls.Add(this.costTextBox);
            this.groupBox3.Controls.Add(this.sidTextBox);
            this.groupBox3.Controls.Add(costLabel);
            this.groupBox3.Controls.Add(refLabel);
            this.groupBox3.Controls.Add(this.nameTextBox);
            this.groupBox3.Controls.Add(this.refTextBox);
            this.groupBox3.Controls.Add(nameLabel);
            this.groupBox3.Location = new System.Drawing.Point(12, 354);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(345, 209);
            this.groupBox3.TabIndex = 17;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "CRUD operations";
            // 
            // clearTextBoxesButton
            // 
            this.clearTextBoxesButton.Location = new System.Drawing.Point(0, 180);
            this.clearTextBoxesButton.Name = "clearTextBoxesButton";
            this.clearTextBoxesButton.Size = new System.Drawing.Size(339, 23);
            this.clearTextBoxesButton.TabIndex = 7;
            this.clearTextBoxesButton.Text = "Clear text boxes";
            this.clearTextBoxesButton.UseVisualStyleBackColor = true;
            this.clearTextBoxesButton.Click += new System.EventHandler(this.clearTextBoxesButton_Click);
            // 
            // insertMedicineButton
            // 
            this.insertMedicineButton.Location = new System.Drawing.Point(6, 19);
            this.insertMedicineButton.Name = "insertMedicineButton";
            this.insertMedicineButton.Size = new System.Drawing.Size(390, 23);
            this.insertMedicineButton.TabIndex = 18;
            this.insertMedicineButton.Text = "Insert new medicine";
            this.insertMedicineButton.UseVisualStyleBackColor = true;
            this.insertMedicineButton.Click += new System.EventHandler(this.insertMedicineButton_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.insertMedicineButton);
            this.groupBox4.Controls.Add(this.updateMedicationButton);
            this.groupBox4.Controls.Add(this.deleteSelectedMedicineButton);
            this.groupBox4.Controls.Add(this.showAllMedications);
            this.groupBox4.Controls.Add(this.button1);
            this.groupBox4.Location = new System.Drawing.Point(363, 444);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(809, 119);
            this.groupBox4.TabIndex = 18;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Medications table controls";
            // 
            // updateMedicationButton
            // 
            this.updateMedicationButton.Location = new System.Drawing.Point(6, 52);
            this.updateMedicationButton.Name = "updateMedicationButton";
            this.updateMedicationButton.Size = new System.Drawing.Size(390, 23);
            this.updateMedicationButton.TabIndex = 8;
            this.updateMedicationButton.Text = "Update medication";
            this.updateMedicationButton.UseVisualStyleBackColor = true;
            this.updateMedicationButton.Click += new System.EventHandler(this.updateMedicationButton_Click);
            // 
            // deleteSelectedMedicineButton
            // 
            this.deleteSelectedMedicineButton.Location = new System.Drawing.Point(6, 85);
            this.deleteSelectedMedicineButton.Name = "deleteSelectedMedicineButton";
            this.deleteSelectedMedicineButton.Size = new System.Drawing.Size(390, 23);
            this.deleteSelectedMedicineButton.TabIndex = 6;
            this.deleteSelectedMedicineButton.Text = "Delete selected medicine";
            this.deleteSelectedMedicineButton.UseVisualStyleBackColor = true;
            this.deleteSelectedMedicineButton.Click += new System.EventHandler(this.deleteSelectedMedicineButton_Click);
            // 
            // medicationsTableAdapter
            // 
            this.medicationsTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.MedicationsTableAdapter = this.medicationsTableAdapter;
            this.tableAdapterManager.UpdateOrder = WindowsFormsApp2._Lab01_PharmacyDataSet1TableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(1184, 581);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(1200, 620);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(1200, 620);
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "DBMS Assignment 1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.suppliersBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._Lab01_PharmacyDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.medicationsBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._Lab01_PharmacyDataSet1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private _Lab01_PharmacyDataSet _Lab01_PharmacyDataSet;
        private System.Windows.Forms.BindingSource suppliersBindingSource;
        private _Lab01_PharmacyDataSetTableAdapters.SuppliersTableAdapter suppliersTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn sidDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn hasContractDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridView2;
        private _Lab01_PharmacyDataSet1 _Lab01_PharmacyDataSet1;
        private System.Windows.Forms.BindingSource medicationsBindingSource;
        private _Lab01_PharmacyDataSet1TableAdapters.MedicationsTableAdapter medicationsTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn midDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sidDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn refDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn costDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn descriptionDataGridViewTextBoxColumn;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button showAllMedications;
        private _Lab01_PharmacyDataSet1TableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.TextBox midTextBox;
        private System.Windows.Forms.TextBox sidTextBox;
        private System.Windows.Forms.TextBox refTextBox;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.TextBox costTextBox;
        private System.Windows.Forms.TextBox descriptionTextBox;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button insertMedicineButton;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button deleteSelectedMedicineButton;
        private System.Windows.Forms.Button clearTextBoxesButton;
        private System.Windows.Forms.Button updateMedicationButton;
    }
}

