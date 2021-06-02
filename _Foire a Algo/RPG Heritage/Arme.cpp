#include <iostream>
#include <string>
#include "Arme.h"
 
using namespace std;
 
Arme::Arme() : m_nom("Vieux couteux a beurre"), m_degats(5)
{
 
}
 
Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{
 
}
 
void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
}
 
void Arme::afficher()
{
    cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl << endl;
}

int Arme::getDegats() const
{
    return m_degats;
}