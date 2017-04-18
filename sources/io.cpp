#include <vector>
#include "../headers/io.h"

namespace io
{
	char de()
	{
		char c[1];
		std::fgets(c, 2, stdin);
		return c[0];
	}

	void Bienvenue()
	{
        std::puts("\n");
        std::puts(  "                                       Welcome to");
        std::puts(" __________   ___    ___   __________     __________   __________   ___   ___    __________");
        std::puts("/___   ___/  /  /   /  /  /  _______/    /  _______/  /  ____   /  /  /_ /   /  /  _______/");
        std::puts("   /  /     /  /__ /  /  /  /__         /  /  __     /  /___/  /  /         /  /  /__");
        std::puts("  /  /     /   __    /  /   __/        /  /  /  \\   /  ____   /  /  /__ /  /  /   __/");
        std::puts(" /  /     /  /   /  /  /  /______     /  /___/  /  /  /   /  /  /  /   /  /  /  /______");
        std::puts("/_ /     /_ /   /_ /  /_________/    /_________/  /_ /   /_ /  /_ /   /_ /  /_________/");
        std::puts("\n");
        std::puts("Dans The Game, vous devez débusquer et tuer tous les monstres présents sur la carte. Bonne chance!");
        std::puts("\n");
	}


	//Non fonctionnel dans le namespace pour l'instant, à reprendre (fonctionne dans l'absolu, testé)

	template<typename T> void afficher(T object, bool need_desc)
    {
        cout << object.get_name();                          //Affiche le nom

        if (need_desc == 1)                                 //Si une description est demandée
        {
            cout << ", \"" << object.get_desc() << "\".";   //Affiche la description
        }
    }

    template<typename T> void choix_element(vector<T> vect_element, bool need_desc)
    {
        typename vector<T>::iterator itv;                                   //Variable de parcours de vecteur
        int cpt = 0;                                                        //Compteur d'éléments

        for (itv = vect_element.begin(); itv != vect_element.end(); itv++)  //Parcours vecteur
        {
            cpt++;                                                          //Incrémentation compteur
            cout << cpt%10 << "- ";                                         //Numéro de l'élément (0 - 9)
            afficher(* itv, need_desc);                                     //Affichage de l'élément
            cout << "   ";
        }
    }
}
