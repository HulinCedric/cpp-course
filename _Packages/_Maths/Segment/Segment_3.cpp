//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Surcharge des operateurs =, == et !=
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Surcharge de l'operateur =
//
Segment& Segment::operator= (const Segment& s) {

   // Valuer les deux attributs du segment support
   //
   m_A= s.m_A;
   m_B= s.m_B;

   // Restituer le resultat
   //
   return *this;
}

// --- Surcharge de l'operateur ==
//
bool Segment::operator== (const Segment& s) {

   // Comparer l'egalite des extremites
   // (a une permutation circulaire pres !)
   //
   if ((m_A==s.m_A && m_B==s.m_B) || (m_A==s.m_B && m_B==s.m_A)) return true;
   
   return false;
}

// --- Surcharge de l'operateur !=
//
bool Segment::operator != (const Segment& s) {return !(*this==s);}



   
















