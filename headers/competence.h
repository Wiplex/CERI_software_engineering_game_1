#include <string>
#include <iostream>
#include <string>
#include <sstream>

#ifndef COMPETENCE_H
#define COMPETENCE_H

using namespace std;

class competence
{
    string skillName;
    int damage;
    int manaCost;
public:
    competence();
    competence(string skillName, int damage, int manaCost);
    competence(string skillName, int damage);
    ~competence();

    string getSkillName();
    int getDamage();
    int getManaCost();

    template<typename T>string toString(const T & valeur);

    void printCompetence(); //Test

    string competenceString(); //Convertit les carac. d'une compétence en une string formatée

};


#endif
