#include "monstre.h"
#include "personnage.h"
#ifndef INTERFACE_H
#define INTERFACE_H

struct interface
{
    bool checkInput(int x); //Vérifie que l'user entre des entier
    competence createCompetence(); //Creer une competence
    competence createCompetenceMonstre(); //Créer une compétence pour monstre (sans mana)
    monstre createMonstre(); //Créer un monstre
    vector<competence> loadCompetenceFromFile(string nomFichier,int numLigne); //Récupérer les compétences d'un monstre dans le .txt

    vector<monstre> loadAllMonstreFromFile(); //Retourne un vecteur contenant tous les monstres du fichier .txt
    vector<personnage> loadAllPersonnageFromFile();
};

#endif
