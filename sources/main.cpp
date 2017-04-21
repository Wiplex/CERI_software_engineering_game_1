#include "../headers/personnage.h"
#include "../headers/io.h"

using namespace io;

int main()
{
	//TEST
	interface inter;
	// inter.createMonstre();
	vector<monstre> tout = inter.loadAllMonstreFromFile();
	//  bob.printMonstre();
	cout << "LES MONSTRES" << endl << endl;
	for (int i = 0; i<tout.size();i++)
	{
	  tout[i].printMonstre();
	}

	competence feu("feu", 10, 5);
	competence glace("glace", 20, 10);
	competence vent("vent", 15, 7);

	vector<competence> skills;
	skills.push_back(feu);
	skills.push_back(glace);
	skills.push_back(vent);

	personnage john("john",10,20,30,"description", skills);
	//john.savePersoInFile();


	vector<personnage> toutperso = inter.loadAllPersonnageFromFile();
	cout<<endl<<endl;
	cout << "LES PERSOS" << endl << endl;
	for (int i = 0; i<toutperso.size();i++)
	{
	  toutperso[i].printPersonnage();
	}
	//cout << john.getAlive();

	return 0;


}
