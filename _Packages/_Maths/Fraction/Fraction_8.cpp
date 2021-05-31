//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur =
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur =
//
Fraction& Fraction::operator =(const Fraction& op2) {
   
   // Fixer le numerateur du resultat
   //
   m_numerateur= op2.numerateur();

   // Fixer le denominateur du resultat
   //
   m_denominateur= op2.denominateur();

   // Restituer le resultat
   //
   return *this;
}

Fraction& Fraction::operator =(int op2) {
   
   // Fixer le numerateur du resultat
   //
   m_numerateur= op2;

   // Fixer le denominateur du resultat
   //
   m_denominateur= 1;

   // Restituer le resultat
   //
   return *this;
}