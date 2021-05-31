//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Operateurs == et != 
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"

// --- Surcharge de l'perateur =
//
Vecteur& Vecteur::operator = (const Vecteur& V) {

   m_x= V.m_x;
   m_y= V.m_y;
   return *this;
}

// --- Surcharge de l'operateur ==
//
bool Vecteur::operator == (const Vecteur& V) {

   return (abscisse() == V.abscisse()) && (ordonnee() == V.ordonnee());
}

// --- Surcharge de l'operateur !=
//
bool Vecteur::operator != (const Vecteur& V) {

   return ! (*this == V);
}










