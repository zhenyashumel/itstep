using MVVMLight_Sample.Helper.JSONClasses;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var request = WebRequest.Create(@"https://randomuser.me/api/?results=10"); ;
            WebResponse response = request.GetResponse();

            var dataStream = response.GetResponseStream();

            StreamReader reader = new StreamReader(dataStream);

            string responseFromServer = reader.ReadToEnd();

            JavaScriptSerializer ser = new JavaScriptSerializer();
            var users =  (Rootobject)ser.Deserialize(responseFromServer, typeof(Rootobject));


            Console.WriteLine(users);
            Console.Read();
        }
    }
}
