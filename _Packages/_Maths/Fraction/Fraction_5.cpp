//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharge des operateurs == et !=
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur ==
//
bool Fraction::operator == (const Fraction& op2) {

   // Controler les produits croises
   //
   return numerateur()*op2.denominateur() == op2.numerateur()*denominateur();
}

bool Fraction::operator == (int op2) {

   // Controler le produit croise
   //
   return numerateur() == op2*denominateur();
}

// Surcharges de l'operateur !=
//
bool Fraction::operator != (const Fraction& op2) {return !(*this==op2);}
bool Fraction::operator != (int op2) {return !(*this==op2);}

