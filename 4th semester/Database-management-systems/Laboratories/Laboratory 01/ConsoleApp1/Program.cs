using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

/* Example 1
 * Establish a connection to a database
 */
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
           
            Program p = new Program();
            p.ConnectDB();
            Console.ReadLine();
        }

        public void ConnectDB()
        {
            SqlConnection connection = null;

            try
            {
                connection = new SqlConnection("Server=MARA-PC\\SQLEXPRESS;Database=farmacy;Trusted_Connection=True");
                connection.Open();
                Console.WriteLine("Successfully connected to db!");
                Console.WriteLine(connection.ConnectionTimeout);
                Console.WriteLine(connection.ConnectionString);

                // Read data from drug table based on sql command and sql data reader
                String selectStatement = "select * from Drug";
                SqlCommand command = new SqlCommand(selectStatement, connection);
                // Console.WriteLine(command.ExecuteScalar());

                SqlDataReader dataReader = command.ExecuteReader();


                while (dataReader.Read())
                {
                    Console.WriteLine(dataReader["id"] + " " + dataReader["name"]);

                    // Console.WriteLine(dataReader.GetInt32(0) + " " + dataReader.GetValue(1));

                }


            }
            catch (SqlException ex)
            {
                Console.WriteLine("Could not conenct to the db " + ex.Message);
            }
            finally
            {
                connection.Close();
            }

        }
    }
}
