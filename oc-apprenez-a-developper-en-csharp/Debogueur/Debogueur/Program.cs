using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Debogueur
{
    class Program
    {
        static void Main(string[] args)
        {
            string chaine = "12,75";
            int i = Convert.ToInt32(chaine);
            Console.WriteLine(i);
        }

        static int CalculSommeIntersection()
        {
            List<int> multipleDe3 = new List<int>();
            List<int> multipleDe5 = new List<int>();

            for (int i = 1; i <= 100 ; i++)
            {
                if (i % 3 == 0)
                    multipleDe3.Add(i);
                if (i % 5 == 0)
                    multipleDe5.Add(i);
            }

            int somme = 0;
            foreach (int m3 in multipleDe3)
            {
                foreach (int m5 in multipleDe5)
                {
                    if (m3 == m5)
                        somme += m3;
                }
            }
            return somme;
        }
    }
}
