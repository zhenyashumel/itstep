using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LoggerApp
{
    public static class Logger
    {
        private static string pattern;
        static Logger()
        {
            pattern = "[DATETIME] [TYPE] [MESSAGE] [METHOD]";
            string pathIni = Path.Combine(Environment.CurrentDirectory, "logger.ini");
            if (File.Exists(pathIni))
            {
                string[] strings = File.ReadAllLines(pathIni);
                if(strings.Length!= 0)
                {
                    //todo:
                    pattern = strings[0];
                }
            }
        }

        public static void Write(TypeAction type, string MethodName, string Message)
        {

            string pathLog = Path.Combine(Environment.CurrentDirectory, "Logs");
            if (!Directory.Exists(pathLog))
                Directory.CreateDirectory(pathLog);

            DateTime dateNow = DateTime.Now;
            string fileName = dateNow.ToString("ddMMyyy") + ".log";
            string pathFile = Path.Combine(pathLog, fileName);

            StringBuilder strBuilder = new StringBuilder(pattern);
            strBuilder.Replace("[DATETIME]", dateNow.ToString("dd.MM.yyyy HH:mm:ss"));
            strBuilder.Replace("[TYPE]", type.ToString());
            strBuilder.Replace("[MESSAGE]", Message);
            strBuilder.Replace("[METHOD]",MethodName);
           

            using (FileStream file = new FileStream(pathFile, FileMode.OpenOrCreate | FileMode.Append))
            {
                using (StreamWriter streamWriter = new StreamWriter(file, Encoding.Default))
                {
                    streamWriter.WriteLine(strBuilder);
                }
            }
        }
    }
}
