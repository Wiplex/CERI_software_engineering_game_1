#include "interface.h"
#include <iostream>

using namespace std;


bool interface::checkInput(int x) //Verifie que l'utilisateur entre bien un entier
{
    if (!cin)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Veuillez entrer un entier." << endl;
        return false;
    }
    return true;
}


competence interface::createCompetence() //Permet à l'utilisateur de créer une compétence
{
    string skillName;
    string skillDescription;
    int damage;
    int manaCost;

    cout << "Entrez le nom de la compétence : ";
    cin >> skillName;

    cout << "Entrez une description de la compétence : ";
    cin >> skillDescription;

    cout << "Entrez le nombre de dommage de la compétence (chiffre négatif pour du soin) : ";
    cin >> damage;
    while(!checkInput(damage))
    {
        cout << "Entrez le nombre de dommage de la compétence (chiffre négatif pour du soin) : ";
        cin >> damage;
    }

    cout << "Entrez le cout en mana de la competence : ";
    cin >> manaCost;
    while(!checkInput(manaCost))
    {
        cout << "Entrez le cout en mana de la competence : ";
        cin >> manaCost;
    }

    competence creation(skillName, skillDescription, damage, manaCost);

    return creation;

}


monstre interface::createMonstre() //Permet à l'utilisateur de créer un monstre avec des caractéristiques choisies
{
    string name;
    int hpMax;
    int speed;

    cout << "Entrez le nom du monstre : ";
    cin >> name;
    cout << endl;

    cout << "Entrez son nombre de points de vie : ";
    cin >> hpMax;
    while(!checkInput(hpMax))
    {
        cout << "Entrez son nombre de points de vie : ";
        cin >> hpMax;
    }

    cout << "Entrez sa vitesse : ";
    cin >> speed;
    while(!checkInput(speed))
    {
        cout << "Entrez sa vitesse : ";
        cin >> speed;
    }

    monstre creation(name, hpMax, speed); //Créé le monstre

    for (int i=0 ; i<3 ; i++) //Rempli le tableau de compétences avec de nouvelles compétences
    {
        // PREVOIR UN SWITCH POUR SAVOIR SI L'USER VEUT CONTINUER A RENTRER DES COMPETENCES
        // PENSER A CHANGER LE 3 DANS LA BOUCLE EN 11
        creation.skillTab[i] = this->createCompetence();
    }

    creation.printMonstre();

    creation.saveInFile(); //Le sauvegarde dans le fichier texte

    return creation;
}


