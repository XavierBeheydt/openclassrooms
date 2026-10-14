using System;

namespace TP_loto
{
    class Program
    {
        /**
         * Méthode (procédure) affichage le tableau de tirage des boule de loto
         * 
         * @param int[] tableau des valeurs de boules
         * @return void
         */
        static void AfficheTirage(int[] tirage)
        {
            Console.Write("Le tirage du Loto est : ");
            // Boucle d'affichage
            foreach (int boule in tirage)
            {
                Console.Write(boule + " ");
            }
        }

        /**
         * Méthode (procédure) principale procédant au tirage des boule
         */
        static void Main(string[] args)
        {
            // Message d'accueil
            Console.WriteLine("Bienvenu au tirage du Loto.");
            Console.WriteLine("Veuillez appuyer sur entrée pour voir le résultat du tirage.");
            Console.ReadLine();
            Console.Clear();


            // Déclaration des variables
            int[] tirage = new int[7];
            Random tirageBoule = new Random();

            // Boucle de remplissage
            int i = 0;
            while (i < tirage.Length)
            {
                bool trouver = false;
                int boule = tirageBoule.Next(1, 49);
                // Boucle prédictive de vérification de doublons
                for (int j = i - 1; j >= 0; j--)
                {
                    if (tirage[j] == boule)
                    {
                        trouver = true;
                    }
                }
                // Insertion et inc de la boucle si doublon non trouvé
                if (! trouver)
                {
                    tirage[i] = boule;
                    i++;
                }
            }

            // Appel de la méthode d'affichage des résultats
            AfficheTirage(tirage);

            // Maintient de la console ouverte
            Console.ReadLine();
        }
    }
}
