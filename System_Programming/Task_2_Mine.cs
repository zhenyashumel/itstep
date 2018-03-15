using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VtoroeTask {
    public class Mine {

        private int gold;
        private bool isWorking;


        public Mine() {
            Random rnd = new Random();
            gold = rnd.Next(1000, 2000);
            isWorking = false;
        }

        public int GetGold() {
            if (gold > 100) {
                isWorking = true;
                gold -= 100;
                return 100;
            } else {
                int x = gold;
                gold = 0;
                return x;                

            }
        }
        public bool isEmpty() {
            return gold == 0 ? true : false;
        }
    }
}
