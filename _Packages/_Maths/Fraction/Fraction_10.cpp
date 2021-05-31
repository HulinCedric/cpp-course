//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur -=
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur -=
//
Fraction& Fraction::operator -=(const Fraction& op2) {

   // Calculer le PPCM des deux denominateurs
   //
   int ppcm= PPCM(denominateur(), op2.denominateur());

   // Calculer le coefficient multiplicateur de chaque numerateur
   //
   int coef_1= ppcm/denominateur();
   int coef_2= ppcm/op2.denominateur();

   // Modifier le numerateur de l'objet support
   //
   m_numerateur= numerateur()*coef_1 - op2.numerateur()*coef_2;

   // Modifier le denominateur de l'objet supporr
   // 
   m_denominateur= ppcm;

   // Restituer le resultat
   //
   reduire();
   return *this;
}

Fraction& Fraction::operator -=(int op2) {

   // Restituer le resultat
   //
   m_numerateur -= op2*denominateur();
   reduire();

   return *this;
}