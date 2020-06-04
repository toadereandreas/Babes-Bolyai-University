using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using ASPX_mvc_example.Models;
using MySql.Data.MySqlClient;

namespace ASPX_mvc_example.DataAbstractionLayer
{
    public class DAL
    {

        public List<Entry> GetEntries()
        {
            MySqlConnection conn;
            string myConnectionString;

            myConnectionString = "server=localhost;uid=root;pwd=;database=wp;";
            List<Entry> entryList = new List<Entry>();

            try
            {
                conn = new MySqlConnection();
                conn.ConnectionString = myConnectionString;
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "select * from entries";
                MySqlDataReader myreader = cmd.ExecuteReader();

                while (myreader.Read())
                {
                    Entry entry = new Entry();
                    entry.id = myreader.GetInt32("id");
                    entry.email = myreader.GetString("email");
                    entry.title = myreader.GetString("title");
                    entry.comment = myreader.GetString("comment");
                    entry.date = myreader.GetString("date");
                    
                   entryList.Add(entry);
                }
                myreader.Close();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
            return entryList;
        }

        public User GetUserInfo(string username)
        {
            MySql.Data.MySqlClient.MySqlConnection conn;

            var myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            User user = new User();

            try
            {
                conn = new MySql.Data.MySqlClient.MySqlConnection {ConnectionString = myConnectionString};
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "select * from users where username=" + "'" + username + "'";
                // Console.WriteLine("cmdtext = " + "select * from users where username=" + "'" + username + "'");
                MySqlDataReader myreader = cmd.ExecuteReader();

                while (myreader.Read())
                {
                    user.password = myreader.GetString("password");
                    user.type = myreader.GetInt16("type");
                    user.id = myreader.GetInt32("id");
                    user.username = username;
                }
                myreader.Close();
            }
            catch (MySql.Data.MySqlClient.MySqlException ex)
            {
                Console.Write(ex.Message);
            }

            Console.WriteLine("DAL.cs > GetUserInfo: User found -> " + user.print());
            return user;
        }

        public bool AddEntry(string email, string title, string comment, string date)
        {
            MySqlConnection conn;
            var myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            
            try
            {
                conn = new MySql.Data.MySqlClient.MySqlConnection {ConnectionString = myConnectionString};
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "INSERT INTO entries(email, title, comment, date) VALUES" +
                                  "('" + email + "','"+title+"','"+comment+"','"+date+"')";
                Console.WriteLine("INSERT INTO entries(email, title, comment, date) VALUES" +
                                  "('" + email + "','"+title+"','"+comment+"','"+date+"')");
                int result = cmd.ExecuteNonQuery();

                if (result >= 1)
                    return true;
                
                return false;
            }
            catch (MySql.Data.MySqlClient.MySqlException ex)
            {
                Console.Write(ex.Message);
                return false;
            }
        }

        public bool UpdateEntry(string email, string title, string comment, string date)
        {
            MySqlConnection conn;
            var myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            
            try
            {
                conn = new MySql.Data.MySqlClient.MySqlConnection {ConnectionString = myConnectionString};
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "UPDATE entries SET title='"+title+"', comment ='"+comment+"', date='"+date+"' WHERE email='"+email+"'";
                Console.WriteLine("UPDATE entries SET title='"+title+"', comment ='"+comment+"', date='"+date+"' WHERE email='"+email+"'");
                int result = cmd.ExecuteNonQuery();

                if (result >= 1)
                    return true;
                
                return false;
            }
            catch (MySql.Data.MySqlClient.MySqlException ex)
            {
                Console.Write(ex.Message);
                return false;
            }
        }

        public bool DeleteEntry(string email)
        {
            MySqlConnection conn;
            var myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            
            try
            {
                conn = new MySql.Data.MySqlClient.MySqlConnection {ConnectionString = myConnectionString};
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "DELETE FROM entries WHERE email='"+email+"'";
                Console.WriteLine("DELETE FROM entries WHERE email='"+email+"'");
                int result = cmd.ExecuteNonQuery();

                if (result >= 1)
                    return true;
                
                return false;
            }
            catch (MySql.Data.MySqlClient.MySqlException ex)
            {
                Console.Write(ex.Message);
                return false;
            }
        }
        
        public List<Entry> GetEntriesByTitle(string title, int offset)
        {
            MySqlConnection conn;
            string myConnectionString;

            myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            List<Entry> entryList = new List<Entry>();

            try
            {
                conn = new MySqlConnection();
                conn.ConnectionString = myConnectionString;
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "select * from entries where title='"+title+"' LIMIT 4 OFFSET " + offset;
                Console.WriteLine("select * from entries where title='"+title+"' LIMIT 4 OFFSET " + offset);
                MySqlDataReader myreader = cmd.ExecuteReader();

                while (myreader.Read())
                {
                    Entry entry = new Entry();
                    entry.id = myreader.GetInt32("id");
                    entry.email = myreader.GetString("email");
                    entry.title = myreader.GetString("title");
                    entry.comment = myreader.GetString("comment");
                    entry.date = myreader.GetString("date");
                    
                    entryList.Add(entry);
                }
                myreader.Close();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
            return entryList;
        }
        
        public List<Entry> GetEntriesByMail(string email, int offset)
        {
            MySqlConnection conn;
            string myConnectionString;

            myConnectionString = "server=localhost;uid=root;pwd=;database=my_db;";
            List<Entry> entryList = new List<Entry>();

            try
            {
                conn = new MySqlConnection();
                conn.ConnectionString = myConnectionString;
                conn.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "select * from entries where email='"+email+"' LIMIT 4 OFFSET " + offset;
                Console.WriteLine("select * from entries where email='"+email+"' LIMIT 4 OFFSET " + offset);
                MySqlDataReader myreader = cmd.ExecuteReader();

                while (myreader.Read())
                {
                    Entry entry = new Entry();
                    entry.id = myreader.GetInt32("id");
                    entry.email = myreader.GetString("email");
                    entry.title = myreader.GetString("title");
                    entry.comment = myreader.GetString("comment");
                    entry.date = myreader.GetString("date");
                    
                    entryList.Add(entry);
                }
                myreader.Close();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
            return entryList;
        }
    }
}