using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Serializer
{
    public static class SerializerHelper
    {
        public static void Serialize<T>(string FilePath, ICollection<T> obj)
        {
            BinaryFormatter xml = new BinaryFormatter();
            using (FileStream file = new FileStream(FilePath, FileMode.Create))
            {
                xml.Serialize(file, obj);
            }
        }

        public static ICollection<T> Deserialize<T>(string FilePath)
        {
            BinaryFormatter xml = new BinaryFormatter();
            using (FileStream file = new FileStream(FilePath, FileMode.Open))
            {
                return (ICollection<T>)xml.Deserialize(file);
            }
        }
    }
}
