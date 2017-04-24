#include "../headers/personnage.h"
#include <fstream>

using namespace std;


//FONCTIONS DE TEST



void personnage::printPersonnage()
{
	cout << "Nom: " << this->entiteName<< endl;
	cout << "HP: " << this->entiteHpCurrent << "/" << this->entiteHpMax;
	cout << "Vitesse: " << this->entiteSpeed<< endl;
	cout << "MP: " << this->entiteManaCurrent << "/" << this->entiteManaMax;
	cout << "Description: " <<this->entiteDescription<<endl;

	cout << endl << "Compétences: " << endl;

	for (int i=0 ; i<3 ; i++)
	{
		this->entiteSkillVect[i].printCompetence();
	}

	cout << endl;
}
