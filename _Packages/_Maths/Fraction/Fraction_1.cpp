//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur +
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Additionner deux fractions entre elles
//
Fraction* Fraction::operator +(const Fraction& op2) {

   // Calculer le PPCM des deux denominateurs
   //
   int ppcm= PPCM(denominateur(), op2.denominateur());

   // Calculer le coefficient multiplicateur de chaque numerateur
   //
   int coef_1= ppcm/denominateur();
   int coef_2= ppcm/op2.denominateur();

   // Fixer le numerateur du resultat
   //
   int num= numerateur()*coef_1 + op2.numerateur()*coef_2;

   // Restituer le resultat
   //
   return new Fraction(num, ppcm);
}

// Additionner une fraction avec un entier
//
Fraction* Fraction::operator +(int op2) {

   // Fixer le numerateur du resultat
   //
   int num= numerateur() + op2*denominateur();

   // Restituer le resultat
   //
   return new Fraction(num, denominateur());
}


