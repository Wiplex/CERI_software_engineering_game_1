#include "../headers/personnage.h"
#include <fstream>

using namespace std;


//FONCTIONS DE TEST



void personnage::printPersonnage()
{
	cout << "nom : " << this->name<< endl;
	cout << "hp max : " << this->hpMax<< endl;
	cout << "speed : " << this->speed<< endl;
	cout << "mana max : " << this->manaMax<<endl;
	cout << "description : " <<this->description<<endl;

	for (int i=0 ; i<3 ; i++)
	{
		this->skillVect[i].printCompetence();
	}

	cout << endl;
}
