//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges de l'operateur /=
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur /=
//
Fraction& Fraction::operator /=(const Fraction& op2) {

   // Controler la validite de l'operation
   //
   if(op2.numerateur()==0) throw -3.0;

   // Modifier l'objet support
   //
   m_numerateur  = numerateur() * op2.denominateur();
   m_denominateur= denominateur() * op2.numerateur();

   // Restituer le resultat
   //
   reduire();
   return *this;
}

Fraction& Fraction::operator /=(int op2) {

   // Controler la validite de l'operation
   //
   if(op2==0) throw -3.0;
   
   // Restituer le resultat
   //
   m_denominateur*= op2;
   reduire();
   return *this;
}