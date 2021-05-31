//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur *=
//
// Auteur : C.Fouco
//

#include "Fraction.h"

// Surcharges de l'operateur *=
//
Fraction& Fraction::operator *=(const Fraction& op2) {

   // Restituer le resultat
   //
   m_numerateur  = numerateur() * op2.numerateur();
   m_denominateur= denominateur() * op2.denominateur();
   reduire();
   return *this;
}

Fraction& Fraction::operator *=(int op2) {

   // Restituer le resultat
   //
   m_numerateur  = numerateur() * op2;
   reduire();

   return *this;
}