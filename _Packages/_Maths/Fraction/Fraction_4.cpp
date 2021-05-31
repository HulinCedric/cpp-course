//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur /
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Diviser deux fractions entre elles
//
Fraction* Fraction::operator /(const Fraction& op2) {

   // Traiter le cas d'une division invalide
   //
   if (op2.numerateur()==0.0) throw -3.0;

   // Fixer le numerateur du resultat
   //
   int num= numerateur()*op2.denominateur();

   // Fixer le denominateur du resultat
   //
   int den= denominateur()*op2.numerateur();

   // Restituer le resultat
   //
   return new Fraction(num, den);
}

// Diviser une fraction par un entier
//
Fraction* Fraction::operator /(int op2) {

   // Traiter le cas d'un diviseur nul
   //
   if (op2==0) throw -3.0;

   // Fixer le denominateur du resultat
   //
   int den= denominateur()*op2;

   // Restituer le resultat
   //
   return new Fraction(numerateur(), den);
}

