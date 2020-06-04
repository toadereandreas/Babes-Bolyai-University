namespace ASPX_mvc_example.Models
{
    public class User
    {
        public int id { get; set; }
        public string username { get; set; }
        public string password { get; set; }
        public int type { get; set; }

        public string print()
        {
            return "User(id=" + this.id + "; username=" + this.username +
                   "; password=" + this.password + "; type=" + this.type + ")";
        }
    }
}