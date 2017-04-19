#include "monstre.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


monstre::monstre()                                                 //Constructeur vide
{
    this->name = "Inconnu";
    this->hpMax = 0;
    this->hpCurrent = hpMax;
    this->speed = 0;
    this->alive = true;
    this->skillTab = new competence[11];
}


monstre::monstre(string name, int hpMax, int speed)               //Constructeur avec arguments de statut du monstre
{
    this->name = name;
    this->hpMax = hpMax;
    this->hpCurrent = this->hpMax;
    this->speed = speed;
    this->alive = true;
    this->skillTab = new competence[11];
}


competence * monstre::getSkillTab()
{
    return skillTab;
}


void monstre::saveInFile()
{

}


void monstre::printMonstre()
{
    cout << "nom : " << this->name<< endl;
    cout << "hp max : " << this->hpMax<< endl;
    cout << "speed : " << this->speed<< endl;

    for (int i=0 ; i<3 ; i++)
    {
        this->skillTab[i].printCompetence();
    }

    cout << endl;
}



