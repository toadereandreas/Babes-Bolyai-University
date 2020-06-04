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
              connection = new SqlConnection("Server=MARA-PC\\SQLEXPRESS;Database=farmacy;Trusted_Connection=True")
              )
            {
               
                Console.WriteLine("Successfully connected!");
                connection.Open();
                SqlDataAdapter adapter = new SqlDataAdapter("select * from drug", connection);
                DataSet drugs = new DataSet();

                adapter.Fill(drugs, "Drug");//populating the data set, with data from table drug, second parameter table name

                foreach (DataRow row in drugs.Tables["Drug"].Rows)
                {
                    Console.WriteLine(row["id"] + " " + row["name"]);
                }

                //insert data into db
                SqlCommand insertCommand = new SqlCommand("insert into drug (id,name,price,form,id_category) values(999,'mara',3.87,'drajeuri',1)",connection);
       
                adapter.InsertCommand = insertCommand;
                adapter.InsertCommand.ExecuteNonQuery();

            }
        }

    }
}
