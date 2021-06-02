#include <string>
#include <iostream>
#include "Personnage.h"

using namespace std;

Personnage::Personnage() : m_nomPerso("NoName"), m_vie(100), m_mana(100)
{
}

Personnage::Personnage( string nomArme, int degatsArme) :  m_nomPerso("NoName"), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
}

Personnage::Personnage(int vie, int mana, string nomArme, int degatsArme) :  m_nomPerso("NoName"), m_vie(vie), m_mana(mana), m_arme(nomArme, degatsArme)
{
}

Personnage::Personnage(string nomPerso, int vie, int mana, string nomArme, int degatsArme) :  m_nomPerso(nomPerso), m_vie(vie), m_mana(mana),m_arme(nomArme, degatsArme)
{
}

Personnage::Personnage(string nomPerso) :  m_nomPerso(nomPerso), m_vie(100), m_mana(100)
{
}

Personnage::Personnage(string nomPerso, string nomArme, int degatsArme) :  m_nomPerso(nomPerso), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
}

Personnage::~Personnage()
{
	cout << m_nomPerso << " Detruit" << endl;
}

void Personnage::recevoirDegats (int nbDegats)
{
	m_vie -= nbDegats; // On enlève le nombre de dégâts reçus à la vie du personnage
    
	if (m_vie < 0) // Pour éviter d'avoir une vie négative
    {
        m_vie = 0; // On met la vie à 0 (ça veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats()); // On inflige à la cible les dégâts que causent notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) // Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    if (m_vie > 0) // Plus de 0 de vie ?
    {
        return true; // VRAI, il est vivant !
    }
    else
    {
        return false; // FAUX, il n'est plus vivant !
    }
}

void Personnage::afficherEtat()
{
	cout << m_nomPerso << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}