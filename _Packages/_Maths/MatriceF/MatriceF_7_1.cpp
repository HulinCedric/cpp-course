//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Surcharges de l'operateur +=.
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Surcharges de l'operateur +=
//
MatriceF& MatriceF::operator +=(const MatriceF& op2) {

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

MatriceF& MatriceF::operator +=(int op2) {

   // Additionner le scalaire a chaque element 
   //
   int cardinal= ordre()*ordre();
   for (int i=0; i<cardinal; i++) m_pT[i] += op2;
   
   // Restituer le resultat
   //
   return *this;
}





