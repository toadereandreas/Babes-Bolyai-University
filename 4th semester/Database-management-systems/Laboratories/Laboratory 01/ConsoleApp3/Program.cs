using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.SqlClient;
using System.Data;
/**
 * Populating a data set based on sql data adapter
 */
namespace ConsoleApplication2
{
    class Program
    {


        static void Main(string[] args)
        {
            Program p = new Program();
            p.PopulateData();
            Console.ReadLine();
        }

        public void PopulateData()
        {
            SqlConnection connection = null;
            using (
              connection = new SqlConnection("Server=DESKTOP-A70AQJO\\SQLEXPRESS;Database=Lab01-Pharmacy;Trusted_Connection=True")
              )
            {

                Console.WriteLine("Successfully connected!");
                connection.Open();
                SqlDataAdapter adapter = new SqlDataAdapter("select * from Doctors", connection);
                DataSet doctors = new DataSet();

                adapter.Fill(doctors, "Doctors");//populating the data set, with data from table drug, second parameter table name

                foreach (DataRow row in doctors.Tables["Doctors"].Rows){
                    Console.WriteLine(row["did"] + " " + row["name"]);
                }

                //insert data into db
                SqlCommand insertCommand = new SqlCommand("insert into Doctors (did,aid,name,position,salary,phoneNumber) values (100,5,'mara','director',387,'0746296128')", connection);

                adapter.InsertCommand = insertCommand;
                //dapter.InsertCommand.ExecuteNonQuery();

            }
        }

    }
}
