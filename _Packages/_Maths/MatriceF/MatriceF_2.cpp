//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Surcharges de l'operateur +
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Additionner deux matrices de meme ordre entre elles
//
MatriceF& MatriceF::operator +(const MatriceF& op2) {

   // Controler la validite de l'operation
   //
   if (ordre() != op2.ordre()) throw -3.0;

   // Allouer la matrice resultante
   //
   MatriceF* pM= new MatriceF(ordre());
   if (pM==NULL) throw -1.0;

   // Additionner entre eux les elements de meme rang
   //
   int cardinal= ordre()*ordre();
   Fraction* pF;
   ;
   for (int i=0; i<cardinal; i++) {
	   pF= m_pT[i]+op2.m_pT[i];
	   if (pF==NULL) throw -1.0;
	   pM->m_pT[i]= *pF;
	   delete pF;
   }
   
   // Restituer le resultat
   //
   return *pM;
}

// Additionner un scalaire a une matrice
//
MatriceF& MatriceF::operator +(int op2) {

   // Allouer la matrice resultante
   //
   MatriceF* pM= new MatriceF(ordre());
   if (pM==NULL) throw -1.0;

   // Additionner le scalaire a chaque element 
   //
   int cardinal= ordre()*ordre();
   Fraction* pF;
   for (int i=0; i<cardinal; i++) {
      pF= m_pT[i]+op2;
	  if (pF==NULL) throw -1.0;
      pM->m_pT[i]= *pF;
	  delete pF;
   }
   
   // Restituer le resultat
   //
   return *pM;
}




