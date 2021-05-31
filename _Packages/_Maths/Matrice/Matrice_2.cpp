//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Surcharges de l'operateur +
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Additionner deux matrices de meme ordre entre elles
//
Matrice& Matrice::operator +(const Matrice& op2) {

   // Controler la validite de l'operation
   //
   if (ordre() != op2.ordre()) throw -3.0;

   // Allouer la matrice resultante
   //
   Matrice* pM= new Matrice(ordre());
   if (pM==NULL) throw -1.0;

   // Additionner entre eux les elements de meme rang
   //
   int cardinal= ordre()*ordre();
   for (int i=0; i<cardinal; i++) pM->m_pT[i]= m_pT[i]+op2.m_pT[i];
   
   // Restituer le resultat
   //
   return *pM;
}

// Additionner un scalaire a une matrice
//
Matrice& Matrice::operator +(int op2) {

   // Allouer la matrice resultante
   //
   Matrice* pM= new Matrice(ordre());
   if (pM==NULL) throw -1.0;

   // Additionner le scalaire a chaque element 
   //
   int cardinal= ordre()*ordre();
   for (int i=0; i<cardinal; i++) pM->m_pT[i]= m_pT[i]+op2;
   
   // Restituer le resultat
   //
   return *pM;
}




