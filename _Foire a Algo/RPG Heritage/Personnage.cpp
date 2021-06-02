#include <string>
#include <iostream>
/*
Personnage.cpp
*/
 
#include "Personnage.h"
 
using namespace std;
 
Personnage::Personnage() : m_vie(100), m_nom("Jack")
{
 
}

Personnage::Personnage(string nom) : m_vie(100), m_nom(nom)
{
 
} 
 
void Personnage::recevoirDegats(int degats)
{
    m_vie -= degats;
}
 
void Personnage::coupDePoing(Personnage &cible)
{
    cible.recevoirDegats(10);
}