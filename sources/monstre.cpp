#include "../headers/monstre.h"
#include <iostream>
#include <fstream>

using namespace std;


// --------------------CONSTRUCTEURS



//-------------------------------------------FONCTIONS



// TESTS


void monstre::printMonstre()
{
	cout << "Nom: " << this->entiteName<< endl;
	cout << "HP: " << this->entiteHpCurrent << "/" << this->entiteHpMax;
	cout << "Vitesse: " << this->entiteSpeed<< endl;

	cout << endl << "Compétences: " << endl;

	for (int i=0 ; i<this->entiteSkillVect.size() ; i++)
	{
		this->entiteSkillVect[i].printCompetence();
	}

	cout << endl;
}
