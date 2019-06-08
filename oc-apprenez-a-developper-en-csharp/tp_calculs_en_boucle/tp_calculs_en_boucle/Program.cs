using System;
using System.Collections.Generic;

namespace tp_calculs_en_boucle
{
    class Program
    {
        /**
         * Fonction qui addition tout les chiffres entre le min et max
         * 
         * @param int min valeur min
         * @param int max valeur max
         * 
         * @return int
         */
        static int CalculSommeEntiers(int min, int max)
        {
            int resultat = 0;

            for (int i = min; i <= max; i++)
            {
                resultat += i;
            }
            return resultat;
        }
        
        /**
         * Fonction calculant la moyenne des items d'une liste
         * 
         * @param List<double> liste
         * @return double
         */
        static double CalculMoyenne(List<double> liste)
        {
            double resultat = 0;
            foreach (double item in liste)
            {
                resultat += item;
            }

            return resultat / liste.Count;
        }

        /**
         * Fonction sortant les multiples de 3 et les multiples de 5 dans une liste de 0 à 100
         * et retournant l'addition des chiffres en commun des deux listes
         * 
         * @return int
         */
        static int CalculMultiples()
        {
            int resultat = 0;
            for (int i = 1; i <= 100; i++)
            {
                if ((i % 3) == 0 && (i % 5 == 0))
                {
                    resultat += i;
                }
            }
            return resultat;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(CalculSommeEntiers(1, 10));
            Console.WriteLine(CalculSommeEntiers(1, 100));

            List<double> liste = new List<double> { 1.0, 5.5, 9.9, 2.8, 9.6 };
            Console.WriteLine(CalculMoyenne(liste));

            Console.WriteLine(CalculMultiples());

            Console.ReadLine();
        }
    }
}
