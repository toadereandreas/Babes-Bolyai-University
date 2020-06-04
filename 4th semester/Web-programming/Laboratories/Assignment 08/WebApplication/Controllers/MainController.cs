using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

using ASPX_mvc_example.Models;
using ASPX_mvc_example.DataAbstractionLayer;

namespace WebApplication.Controllers
{
    public class MainController : Controller
    {
        public string GetByTitle()
        {
            string title = Request.Params["title"];
            int page = int.Parse(Request.Params["page"]);
            int offset = (page - 1) * 4;
            DAL dal = new DAL();
            List<Entry> entries = dal.GetEntriesByTitle(title, offset);
            ViewData["studentList"] = entries;
            
            string result = "<table><thead><th>Email</th><th>Title</th><th>Comment</th><th>Date</th></thead>";

            foreach (Entry entry in entries)
            {
                result += "<tr><td>" + entry.email + "</td><td>" + entry.title + "</td><td>" + entry.comment + "</td><td>" + entry.date + "</td><td></tr>";
            }

            result += "</table>";
            return result;
        }
        
        public string GetByEmail()
        {
            string email = Request.Params["email"];
            int page = int.Parse(Request.Params["page"]);
            int offset = (page - 1) * 4;
            DAL dal = new DAL();
            List<Entry> entries = dal.GetEntriesByMail(email, offset);
            ViewData["studentList"] = entries;
            
            string result = "<table><thead><th>Email</th><th>Title</th><th>Comment</th><th>Date</th></thead>";

            foreach (Entry entry in entries)
            {
                result += "<tr><td>" + entry.email + "</td><td>" + entry.title + "</td><td>" + entry.comment + "</td><td>" + entry.date + "</td><td></tr>";
            }

            result += "</table>";
            return result;
        }
        
        public string Login()
        {
            string username = Request.Params["username"];
            string pass = Request.Params["password"];
            string result = "";
            DAL dal = new DAL();
            User user = dal.GetUserInfo(username);
            string actualpass = user.password;
            if (actualpass == "" || actualpass != pass)
            {
                RedirectToAction("Index");
            }
            else
            {
                Console.WriteLine("x="+user.type);
                if (user.type == 0)
                {
                    Session["sid"] = user.id;
                    Session["username"] = user.username;
                    result = "SeeEntries";
                    RedirectToAction("SeeEntries");
                }
                if(user.type == 1)
                {
                    Session["sid"] = user.id;
                    Session["username"] = user.username;
                    result = "adminEntries";
                    RedirectToAction("AdminEntries");
                }
                
            }

            Console.Out.WriteLine(result);
            
            return result;
        }

        public string AddEntry()
        {
            string email = Request.Params["email"];
            string title = Request.Params["title"];
            string comment = Request.Params["comment"];
            string date = Request.Params["date"];
            
            DAL dal = new DAL();
            bool queryResult = dal.AddEntry(email, title, comment, date);
            
            if( queryResult )
                return "<p>Entry added!</p>";
            
            return "<p>Error while adding entry!</p>";
        }

        public string UpdateEntry()
        {
            string email = Request.Params["email"];
            string title = Request.Params["title"];
            string comment = Request.Params["comment"];
            string date = Request.Params["date"];
            
            DAL dal = new DAL();
            bool queryResult = dal.UpdateEntry(email, title, comment, date);
            
            if( queryResult )
                return "<p>Entry updated!</p>";
            
            return "<p>Error while updating entry!</p>";
        }

        public string DeleteEntry()
        {
            string email = Request.Params["email"];
            
            DAL dal = new DAL();
            bool queryResult = dal.DeleteEntry(email);
            
            if( queryResult )
                return "<p>Entry deleted!</p>";
            
            return "<p>Error while deleting entry!</p>";
        }

        public ActionResult SeeEntries()
        {
            return View("UserView");
        }
        
        public ActionResult AdminEntries()
        {
            return View("AdminView");
        }

        public string Test()
        {
            return "It's working";
        }

        // GET: Main
        public ActionResult Index()
        {
            return View("LoginView");
        }
    }
}