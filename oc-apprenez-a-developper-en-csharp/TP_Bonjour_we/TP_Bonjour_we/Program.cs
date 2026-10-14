using System;

namespace TP_Bonjour_we
{
    class Program
    {
        static void Main(string[] args)
        {
            int hour = DateTime.Now.Hour;
            int day = (int)DateTime.Now.DayOfWeek;

            bool cas_1 = ((hour > 9 && hour < 18) && (day >= 1 && day <= 5));
            bool cas_3 = ((day == 5 && hour > 18) || (day == 1 && hour < 9) || (day == 6 || day == 7));

            if (cas_1)
            {
                Console.WriteLine("Bonjour, " + Environment.UserName);
            }
            else
            {
                if (cas_3)
                {
                    Console.WriteLine("Bon week-end, " + Environment.UserName);
                }
                else
                {
                    Console.WriteLine("Bonsoir, " + Environment.UserName);
                }
            }

            Console.ReadLine();
        }
    }
}
