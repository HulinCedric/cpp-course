//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Methode appartient
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Determine si un point donne P appartient ou pas a la demi droite cible
//
// Le point P appartient a la demi droite cible si et seulement si :
//
//    1) Il verifie l'equation de la droite support
//    2) Le vecteur OP est de meme sens que V
//
bool DemiDroite::appartient(const Point& P) const{

   Vecteur OP(m_O, P);
   if (!OP.memeSens(m_V)) return false;

   return true;
}
