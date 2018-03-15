using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace PervoeZadanie {
    class Program {
        private static object _sync;
        private static List<int> S;
        private static List<int> R;
        static Program() {
            S = new List<int>();
            R = new List<int>();
            _sync = new object();

        }
        static void Main(string[] args) {

            Thread[] threads = new Thread[4];
            threads[0] = new Thread(threadA);
            threads[1] = new Thread(threadB);
            threads[2] = new Thread(threadC);
            threads[3] = new Thread(threadD);

            for (int i = 0; i < threads.Length; i++) {
                threads[i].Start();
            }
        }

        private static void threadA() {


            for (int i = 0; i > -1; i++) {
                lock (_sync) {
                    S.Add(i);
                 //   Console.ForegroundColor = ConsoleColor.Red;
                 //   Console.Write(S.Last() + " ");
                }
               
                Thread.Sleep(500);               

            }

        }

        private static void threadB() {
            while (true) {
                while (S.Count == 0)
                    Thread.Sleep(1000);
                lock (_sync) {
                    R.Add(S.Last() * S.Last());
                 //   Console.ForegroundColor = ConsoleColor.Yellow;
                  //  Console.Write(R.Last() + " ");
                }
              
            }

        }

        private static void threadC() {
            while (true) {
                while (S.Count == 0)
                    Thread.Sleep(1000);
                lock (_sync) {
                    R.Add(S.Last() / 3);
                   // Console.ForegroundColor = ConsoleColor.Green;
                   // Console.Write(R.Last() + " ");
                }
              
            }
        }

        private static void threadD() {
            while (true) {
                while (R.Count == 0) {
                    Console.WriteLine("List R is empty!!!");
                    Thread.Sleep(1000);
                                   
                }
                // Console.ForegroundColor = ConsoleColor.Blue;
                Console.Write(R.Last() + " ");
               
            }

        }
    }




}
