//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges des operateurs < et <=
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur <
//
bool Fraction::operator <(const Fraction& op2) {

   // Soustraire les deux operandes entre eux
   //
   Fraction* pF= *this- op2;
   if (pF==NULL) throw -1.0;

   // Controler le signe du resultat
   //
   if (pF->numerateur() < 0) { delete pF; return true;}

   delete pF; return false;
}

bool Fraction::operator <(int op2) {

   // Soustraire les deux operandes
   //
   Fraction* pF= *this - op2;
   if (pF==NULL) throw -1.0;

   // Controler le signe du resultat
   //
   if (pF->numerateur() < 0) {delete pF; return true;}

   delete pF; return false;
}

// Surcharges de l'operateur <=
//
bool Fraction::operator <=(const Fraction& op2) {

   // Soustraire les deux operandes
   //
   Fraction* pF= *this - op2;
   if (pF==NULL) throw -1.0;

   // Controler le signe du resultat
   //
   if (pF->numerateur() <= 0) {delete pF; return true;}

   delete pF; return false;
}

bool Fraction::operator <=(int op2) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Soustraire les deux operandes
   //
   Fraction* pF= *this - op2;
   if (pF==NULL) throw -1.0;

   // Controler le signe du resultat
   //
   if (pF->numerateur() <= 0) {delete pF; return true;}

   delete pF; return false;
}
