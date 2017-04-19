#include "competence.h"

competence::competence()                                                           //Constructeur de compétence vide
{
    this->skillName = "Inconnu";
    this->skillDescription  = "Inconnu";
    this->damage = 0;
    this->manaCost = 0;
}


competence::competence(string skillName, string skillDescription, int damage, int manaCost) //Constructeur de competence
{
    this->skillName = skillName;
    this->skillDescription  = skillDescription;
    this->damage = damage;
    this->manaCost = manaCost;
}


void competence::printCompetence()
{
        cout << "skill name : " << this->skillName << endl;
        cout << "skill description: " << this->skillDescription<< endl;
        cout << "skill damage : " << this->damage<< endl;
        cout << "skill manacost : " << this->manaCost<< endl;
}
