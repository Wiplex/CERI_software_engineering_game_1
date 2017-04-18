#include <iostream>

using namespace std;

//! Cet espace sera un espace permettant de définir un buffer custom pour les input, ainsi que de pouvoir afficher tout ce que l'on souhaite.
namespace io
{
	std::istream io_input();
	extern char de();			// Demande l'entrée utilisateur
	void Bienvenue();           //Affiche le message d'accueil (début du programme)

	//! Affichage d'objet.
    /*!
        Affiche le nom (et éventuellement la description) d'un objet.
        \param object Objet à afficher.
        \param need_desc Description ou non.
    */
    template<typename T> void afficher(T object, bool need_desc);

    //!Affichage d'un ensemble d'objets
    /*!
        Parcourt le vecteur de stockage des objets chargés, et les affiche.
        \param vect_element Vecteur d'éléments.
        \param need_desc Description ou non.
        \sa afficher()
    */
    template<typename T> void choix_element(vector<T> vect_element, bool need_desc);
}
