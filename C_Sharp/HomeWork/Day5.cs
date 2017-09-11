using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2
{
    class User
    {
        #region Fields

        private string name;
        private string[] sexArr = { "Man", "Woman", "It" };
        private string password;
        private string login;
        private int age;
        private string eMail;
        private int sex;
        private string phone;
        private string skype;
        #endregion

        public string Name
        {
            get { return name; }
            set
            {
                if (String.IsNullOrWhiteSpace(name))
                    throw new ArgumentException("you must enter a name");
                else
                    name = value;
            }
        }

        public string age
        {
            get { return name; }
            set
            {
                if (String.IsNullOrWhiteSpace(name))
                    throw new ArgumentException("you must enter a name");
                else
                    name = value;
            }
        }




    }
}
