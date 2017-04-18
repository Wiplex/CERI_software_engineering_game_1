#include "../headers/io.h"
#include <vector>
#include <termios.h>	// Needed for terminal input manipulation
#include <stdio.h>	// Needed for terminal input manipulation

// Notes :
// Get the terminal column number :
// 	> stty -a | grep "col" | tail -c 22 | tail -c 13 | head -c 3
// Get the terminal rows number :
// 	> stty -a | grep "col" | tail -c 22 | head -c 2

namespace io {
	char de()
	{
		// Create new structures for storing new and old configs of the current terminal.
		static struct termios old, mew;
		char ch;				// Return character
		// Initialize new terminal I/O settings
		tcgetattr(0, &old);			/* Grab old terminal i/o settings */
		mew = old;				/* Make new settings same as old settings */
		mew.c_lflag &= ~ICANON;			/* Disable buffered i/o */
		mew.c_lflag &= ~ECHO;			/* Set echo mode */
		tcsetattr(0, TCSANOW, &mew);		/* Use these new terminal i/o settings now */
		ch = getchar();				// getchar() now takes only one char
		// Restore old terminal I/O settings
		tcsetattr(0, TCSANOW, &old);
		return ch;
	}
	void Bienvenue()
	{
        std::puts("\n");
        std::puts("                                         Welcome to");
        std::puts(" __________   ___    ___   __________     __________   __________   __________   __________");
        std::puts("/___   ___/  /  /   /  /  /  _______/    /  _______/  /  ____   /  /   __    /  /  _______/");
        std::puts("   /  /     /  /__ /  /  /  /__         /  /  __     /  /___/  /  /  /   /  /  /  /__");
        std::puts("  /  /     /   __    /  /   __/        /  /  /  \\   /  ____   /  /  /   /  /  /   __/");
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
