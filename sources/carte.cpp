#include "../headers/carte.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

Carte :: Carte()
{
	this->nom = "";
	this->description = "";
	this->nbr_monstre = 0 ;
	this -> case_dispo = 0;
}

Carte :: Carte (int size, string name, string desc)
{
	verif_taille(size);
	this->nom = name;
	this->description = desc;
	this->plateau = new string * [taille];
	for (int i = 0; i < taille ; i++)
	{
		plateau[i] = new string [taille];
		for (int j = 0 ; j< taille ; j++)
		{
			plateau[i][j] = "" ;

		}
	}
	this -> case_dispo = taille*taille;
}


void Carte::verif_taille(int size)
{
	while ( size < 4  || size > 255)
	{
		cout << "Taille impossible veuillez choisir une taille entre 5 et 255 "<<endl << "choix de la taille :" << endl;
		cin >> size;
	}
	this-> taille=size;
}

void Carte :: coordonneejoueur()
{
	int coordonneejoueur1;
	int coordonneejoueur2;
	bool placement_fait = false;
	while (placement_fait==false)
	{
		cout << "Choisissez la premiere coordonnée où le joueur doit apparaitre :" ;
		cin >> coordonneejoueur1;
		cout << "Choisissez la deuxieme coordonnée où le joueur doit apparaitre :" ;
		cin >> coordonneejoueur2;
		if (coordonneejoueur1 < taille && coordonneejoueur2 < taille)
		{
			plateau[coordonneejoueur1][coordonneejoueur2]="j";
			placement_fait=true;
		}
		else
		{
			cout << "vos coordonnées sont hors de la carte!!" << endl;
		}
	}
	case_dispo = case_dispo - 1;
}

void Carte::coordonneeobstacle()
{
	int nbr_obstacle=0;
	int coordonneeobstacle1;
	int coordonneeobstacle2;
	cout<< "Combien d'obstacle, sur la carte, voulez vous?";
	cin >> nbr_obstacle;
	while (nbr_obstacle >= case_dispo)
	{
		cout<< "Vous avez choisi trop d'obstacle." << endl << "Combien d'obstacle voulez vous sur la carte?";
		cin >> nbr_obstacle;
	}
	int i = 1;
	while (i <= nbr_obstacle)
	{
		cout << "Choisissez la premiere coordonnée où l'obstacle doit apparaitre :" ;
		cin >> coordonneeobstacle1;
		cout << "Choisissez la deuxieme coordonnée où l'obstacle doit apparaitre :" ;
		cin >> coordonneeobstacle2;
		if (coordonneeobstacle1 < taille && coordonneeobstacle2 < taille)
		{
			if (plateau[coordonneeobstacle1][coordonneeobstacle2] == "v")
			{
				plateau[coordonneeobstacle1][coordonneeobstacle2] = "o";
				i++;
			}
			else
			{
				cout << "cette case est deja occupée, Veuillez en choisir une autre " << endl;
			}
		}
		else
		{
			cout << "Vos coordonnées sont hors de la carte!!" << endl;
		}
	}
	case_dispo = case_dispo - nbr_obstacle;
}

void Carte::coordonneemonstre()
{
	int nombre_monstre = 0;
	int coordonneemonstre1;
	int coordonneemonstre2;
	while ((nombre_monstre < taille) || (nombre_monstre > case_dispo))
	{
		cout<< "Combien de monstre voulez-vous sur la carte?";
		cin >> nombre_monstre;
	}
	this -> nbr_monstre = nombre_monstre;
	int i = 1;
	while (i <= nombre_monstre)
	{
		cout << "Choisissez la premiere coordonnée où le monstre doit apparaitre :" ;
		cin >> coordonneemonstre1;
		cout << "Choisissez la deuxieme coordonnée où le monstre doit apparaitre :" ;
		cin >> coordonneemonstre2;
		if (coordonneemonstre1 < taille && coordonneemonstre2 < taille)
		{
			if (plateau[coordonneemonstre1][coordonneemonstre2] == "v")
			{
				plateau[coordonneemonstre1][coordonneemonstre2] = "m";
				i++;
			}
			else
			{
				cout << "Cette case est deja occupée veuillez en choisir une autre " << endl;
			}
		}
		else
		{
			cout << "Vos coordonnées sont hors de la carte!!" << endl;
		}
	}
	case_dispo = case_dispo - nbr_monstre;
}

void Carte :: affichage_normal()
{
	for (int i=0; i<taille; i++)
	{
		for (int j=0; j<taille; j++)
		{
			cout << plateau[i][j];
		}
		cout << endl;
	}
}

int Carte::nbLigneFichier(string nomFichier) //Compte le nb de ligne du fichier pour créer l'identifiant unique d'un monstre
{
	ifstream fichier(nomFichier.c_str()); //Ouverture en mode lecture
	int nbLigne = 0;
	if(fichier)
	{
		string ligne="";

		while(getline(fichier, ligne)) //Stockage de chaque ligne du fichier
		{
			nbLigne++;
		}
		fichier.close(); //On ferme le fichier
	}

	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}

	return nbLigne;
}


void Carte :: sauvegarde()
{
	// Nom de la carte
	string carte = "fichierCarte.txt" ;
	string type_obstacle;
	string monstre;
	int nbligne=nbLigneFichier(carte);

	//ouverture du fichier en écriture
	ofstream fichier(carte, ios :: app) ;

	// Si fichier bien ouvert
	if (fichier)
	{
		fichier << "c" << nbligne << "|" ;
		fichier << nom << "|" ;
		fichier << description << "|";
		fichier << taille << "|";
		for (int i = 0 ; i < taille; i++)
		{
			for (int j = 0 ; j < taille ; j++)
			{
				if (plateau[i][j]=="o")
				{
					cout << "Quelle est l'obstacle à la case "<< i << " "<< j << ":";
					cin >> type_obstacle;
					fichier << "(" << i << "," << j << ","<< type_obstacle << ")";
				}
				if (plateau[i][j]=="m")
				{
					cout << "Quelle est le monstre à la case "<< i << " "<< j << ":";
					cin >> monstre;
					fichier << "(" << i << "," << j << ","<< monstre << ")";
				}
				if (plateau[i][j]=="j")
					fichier << "(" << i << "," << j << ",joueur" << ")";
			}

		}
		fichier << '\n' ;
		// On referme le fichier
		fichier.close() ;
		cout << "Carte sauvegardée" << endl ;
	}
	else cerr << "échec de la sauvegarde" << endl ;
	return ;
}

string Carte :: getName()
{
    return this->nom;
}

string Carte :: getDescription()
{
    return this->description;
}




vector <Carte> Carte :: chargement ()
{
	vector <Carte> selectionnable ;
	ifstream fichier("fichierCarte.txt", ios :: in) ;
	if (fichier)
	{
		string current_line;

//cerr << "1" << endl ;
//cerr << "current_line : " << current_line << endl ;
		while (getline(fichier, current_line))
		{
//cerr << "2" << endl ;
			bool init = false;
			bool fait = false ;
			Carte carte_temporaire ;
			string id = "" ;
			string nom = "" ;
			string description = "" ;
			string taille= "";
			string coordonnee1 = "" ;
			string coordonnee2 = "" ;
			string type = "" ;
			int count_c = 0 ;
			int count_coordonnee = 0 ;
			int i = 0 ;
//cerr << "id : " << id << endl ;
//cerr << "nom : " << nom << endl ;
//cerr << "description : " << description << endl ;
//cerr << "taille : " << taille << endl ;
//cerr << "coordonnée 1 : " << coordonnee1 << endl ;
//cerr << "coordonnée 2 : " << coordonnee2 << endl ;
//cerr << "type : " << type << endl ;
//cerr << "count_c : " << count_c << endl ;
//cerr << "count_coordonnee : " << count_coordonnee << endl ;
//cerr << "i : " << i << endl ;
			while (current_line[i+1] != '\0')
			{
				char tmp = current_line[i] ;
//cerr << "3" << endl ;
//cerr << "tmp : " << tmp << endl ;
				if (tmp == '|')
				{
					count_c++ ;
					i++ ;
//cerr << "4_1 : " << endl ;
//cerr << "count_c : " << count_c << endl ;
//cerr << "i : " << i << endl ;
				}
				else if (count_c == 0)
				{
					id = id + tmp ;
					i++ ;
//cerr << "4_2 : " << endl ;
//cerr << "id : " << id << endl ;
//cerr << "i : " << i << endl ;
				}
				else if (count_c == 1)
				{
					nom = nom + tmp ;
					i++ ;
//cerr << "4_3 : " << endl ;
//cerr << "nom : " << nom << endl ;
//cerr << "i : " << i << endl ;
				}
				else if (count_c == 2)
				{
					description = description + tmp ;
					i++ ;
//cerr << "4_4 : " << endl ;
//cerr << "description : " << description << endl ;
//cerr << "i : " << i << endl ;
				}
				else if (count_c == 3)
				{
					taille = taille + tmp ;
					i++ ;
//cerr << "4_5 : " << endl ;
//cerr << "taille : " << taille << endl ;
//cerr << "i : " << i << endl ;
				}
//cerr << "5 : " << endl ;
//cerr << "t : " << t << endl ;
//cerr << "taille : " << carte_temporaire.taille << endl ;
//cerr << "nom : " << carte_temporaire.nom << endl ;
//cerr << "description : " << carte_temporaire.description << endl ;
				if (count_c == 4)
				{
				int t = atoi(taille.c_str());
				carte_temporaire.taille = t ;

				if (init == false)
				{
					init = true;

					carte_temporaire.plateau = new string * [t];

					for (int i = 0 ; i < t ; i++)
					{
						carte_temporaire.plateau[i] = new string [t] ;
					}
				}

				carte_temporaire.nom = nom ;
				carte_temporaire.description = description ;

//cerr << "6 : " << endl ;
//cerr << "count_c : " << count_c << endl ;
					if (fait)
					{
						type = "";
						coordonnee1 = "" ;
						coordonnee2 = "" ;
						if (current_line[i+1] != '\0') fait = false ;
					}
					else if (tmp == ')')
					{
						fait = true ;
						count_coordonnee = 0 ;
						i++ ;
						int coor1 = atoi(coordonnee1.c_str()) ;
						int coor2 = atoi(coordonnee2.c_str()) ;
						carte_temporaire.plateau[coor1][coor2] = type;
//cerr << "7_1 : " << endl ;
//cerr << "count_c_coordonnee : " << count_c_coordonnee << endl ;
//cerr << "i : " << i << endl ;
//cerr << "coor1 : " << coor1 << endl ;
//cerr << "coor2 : " << coor2 << endl ;
//cerr << "plateau : " << carte_temporaire.plateau[coor1][coor2] << endl ;

					}
					else if (tmp == ',')
					{
						count_coordonnee ++ ;
						i++ ;
//cerr << "7_2 : " << endl ;for (int i = 0; i < taille; i++)
//cerr << "count_coordonnee : " << count_coordonnee << endl ;
//cerr << "i : " << i << endl ;
					}
					else if (tmp == '(')
					{
						i ++ ;
//cerr << "7_3 : " << endl ;
//cerr << "i : " << i << endl ;
					}
					else if ((tmp != '(') && (tmp != ')') && (tmp != ','))
					{
//cerr << "7_4 : " << endl ;
						if (count_coordonnee == 0)
						{
							coordonnee1 = coordonnee1 + tmp ;
							i ++ ;
//cerr << "7_4_1 : " << endl ;
//cerr << "coordonnée 1 : " << coordonnee1 << endl ;
//cerr << "i : " << i << endl ;
						}
						else if (count_coordonnee == 1)
						{
							coordonnee2 = coordonnee2 + tmp ;
							i++ ;
//cerr << "7_4_2 : " << endl ;
//cerr << "coordonnée 2 : " << coordonnee2 << endl ;
//cerr << "i : " << i << endl ;
						}
						else if (count_coordonnee == 2)
						{
							type = type + tmp ;
							i++ ;
//cerr << "7_4_3 : " << endl ;
//cerr << "type : " << type << endl ;
//cerr << "i : " << i << endl ;
						}
					}
				}
			}


//cerr << "enregistrement dans selectionnable" << endl ;
			selectionnable.push_back(carte_temporaire) ;

//			for (int i = 0; i < carte_temporaire.taille; i++)
//			{
//				for (int j = 0; j < carte_temporaire.taille; j++)
//				{
//					cout << carte_temporaire.plateau[i][j];
//				}
//				cout << endl;
//			}
		}
	}
	return selectionnable ;
}

Carte Carte::operator=(const Carte & a_copier)
{
	this -> id = a_copier.id;
	this -> nom = a_copier.nom;
	this -> description = a_copier.description;
	this -> taille = a_copier.taille;

	delete [] this -> plateau;
	this -> plateau = new string * [taille];

	for (int i = 0; i < taille; i++)
	{
		this -> plateau[i] = new string [taille];
	}

	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			this -> plateau[i][j] = a_copier.plateau[i][j];
		}
	}

	this -> nbr_monstre = a_copier.nbr_monstre;
	this -> case_dispo = a_copier.case_dispo;

	return * this;
}





