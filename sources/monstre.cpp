#include "../headers/monstre.h"
#include <iostream>
#include <fstream>

using namespace std;


// --------------------CONSTRUCTEURS



//-------------------------------------------FONCTIONS



// TESTS


void monstre::printMonstre()
{
	cout << "nom : " << this->name<< endl;
	cout << "hp max : " << this->hpMax<< endl;
	cout << "speed : " << this->speed<< endl;

	for (int i=0 ; i<this->skillVect.size() ; i++)
	{
		this->skillVect[i].printCompetence();
	}

	cout << endl;
}
