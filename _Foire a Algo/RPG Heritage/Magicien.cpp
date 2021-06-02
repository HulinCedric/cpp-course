/*
 *  Magicien.cpp
 *  RPG
 *
 *  Created by TrAsHeUr on 22/02/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Magicien.h"

using namespace std;

Magicien::Magicien() : Personnage(), m_mana(100)
{
 
}

Magicien::Magicien(string nom) : Personnage(nom), m_mana(100)
{
 
}

void Magicien::bouleDeFeu(Personnage &cible)
{
    cible.recevoirDegats(30);
}

void Magicien::bouleDeGlace(Personnage &cible)
{
    cible.recevoirDegats(30);
}