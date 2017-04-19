#include <string>
#include <iostream>
#include <string>

using namespace std;

class competence
{
    string skillName;
    string skillDescription;
    int damage;
    int manaCost;
public:
    competence();
    competence(string skillName, string skillDescription, int damage, int manaCost);
    void printCompetence();
};
