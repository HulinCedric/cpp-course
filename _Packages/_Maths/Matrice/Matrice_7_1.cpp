//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Surcharges de l'operateur +=.
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Surcharges de l'operateur +=
//
Matrice& Matrice::operator +=(const Matrice& op2) {

   // Controler la validite de l'operation
   //
   if (ordre() != op2.ordre()) throw -3.0;

   // Additionner entre eux les elements de meme rang
   //
   int cardinal= ordre()*ordre();
   for (int i=0; i<cardinal; i++) m_pT[i] += op2.m_pT[i];
  
   // Restituer le resultat
   //
   return *this;
}

Matrice& Matrice::operator +=(int op2) {

   // Additionner le scalaire a chaque element 
   //
   int cardinal= ordre()*ordre();
   for (int i=0; i<cardinal; i++) m_pT[i] += op2;
   
   // Restituer le resultat
   //
   return *this;
}





