// #include "./carte.h"
// #include "./perso.h"
// #include "./compet.h"
// #include "./monstre.h"
// #include "./io.h"

//! Normalement, à ca point là, la carte doit être chargée, le personnage est choisi et chargé, les monstres sont chargés et il ne reste qu'à lancer le jeu.

using std::stack;
using namespace io;

class jeu
{
	// carte jeu_carte;
	// perso jeu_perso;
	// std::stack<> jeu_coups;
	int jeu_nombre_monstre;

	public:
		jeu();
		~jeu();
		void demarrer_jeu();
	//	void combat(perso &p, monstre &m);
	//	void application_coup(perso &p, compet &a, monstre &m, compet &b);
};
