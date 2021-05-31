//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Constructeur par defaut
//
DemiDroite::DemiDroite() {
   m_O= Point(0, 0);
   m_V= Vecteur(1, 1);
}

// --- Constructeur normal
//
DemiDroite::DemiDroite(const Point& P, const Vecteur& V) {

   // Controler le cas d'un vecteur nul
   //
   Vecteur V0(0, 0);
   if (V0==V) throw -3.0;

   m_O= P;
   m_V= V;
}

// --- Methode toString pour les tests unitaires
//
char* DemiDroite::toString() {
char* pBuffer= new char[80];

   sprintf(pBuffer, "[%s, %s[",m_O.toString(), m_V.toString());
   return pBuffer;
}



