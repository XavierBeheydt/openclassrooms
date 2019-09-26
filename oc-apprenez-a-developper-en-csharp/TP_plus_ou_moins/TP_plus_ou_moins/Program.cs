using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TP_plus_ou_moins
{
    class Program
    {
        static void Main(string[] args)
        {
            // Message de bienvenu
            Console.WriteLine("Bienvenu dans le jeu du plus ou moins.");
            Console.WriteLine("Le but est trouvé un nombre mystère de 1 à 99.");
            Console.Read();

            // Effacement de la console.
            Console.Clear();

            // Création des variables
            int nbSaisi = -1;
            int valeurATrouver = new Random().Next(0, 100);

            // Demande première saisi
            Console.WriteLine("Veuillez entrer votre premier nombre ?");
            // Boule de saisi et de vérification 
            while(nbSaisi != valeurATrouver)
            {
                nbSaisi = Console.Read();
                
                Console.Clear();
                if (nbSaisi > valeurATrouver)
                {
                    Console.WriteLine("Plus petit, veuillez rééssayer.");
                }
                else
                {
                    Console.WriteLine("Plus grand, veuillez Rééssayer.");
                }
                if (nbSaisi <= 0 || nbSaisi >= 100)
                    Console.WriteLine("Vous avez saisi un chiffre en dehors de 1 à 99.");
            }

            // Message de gain
            Console.Clear();
            Console.WriteLine("Gagner !!!");
        }
    }
}
