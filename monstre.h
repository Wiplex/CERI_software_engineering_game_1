#include <string>
#include "competence.h"

class monstre
{
    string name;
    int hpMax;
    int hpCurrent;
    int speed;
    bool alive;


public:
    competence * skillTab; // POUR TEST, A MODIFIER
    monstre();
    monstre(string name, int hpMax, int speed);
    void saveInFile(); //Permet d'écrire le monstre dans un fichier de sauvegarde
    competence * getSkillTab();
    void printMonstre(); // Pour tester



};
