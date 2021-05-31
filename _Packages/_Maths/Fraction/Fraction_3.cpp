//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharge de l'operateur *
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Multiplier deux fractions entre elles
//
Fraction* Fraction::operator *(const Fraction& op2) {

   // Fixer le numerateur du resultat
   //
   int num= numerateur()*op2.numerateur();

   // Fixer le denominateur du resultat
   //
   int den= denominateur()*op2.denominateur();

   // Restituer le resultat
   //
   return new Fraction(num, den);
}

// Multiplier une fraction par un entier
//
Fraction* Fraction::operator*(int op2) {

   // Fixer le numerateur du resultat
   //
   int num= numerateur()*op2;

   // Restituer le resultat
   //
   return new Fraction(num, denominateur());
}

