//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Surcharge de l'operateur =
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Affecter une matrice a une autre
//
Matrice& Matrice::operator = (const Matrice& op2) {

   // Controler la validite de l'operation
   //
   if (ordre() != op2.ordre()) throw -3.0;

   // Copier chaque element du parametre dans l'objet support
   //
   int cardinal= ordre()*ordre(); 
   for (int i=0; i<cardinal; i++) m_pT[i]= op2.m_pT[i];

   return *this;
}

// Affecter un scalaire a une matrice
//
Matrice& Matrice::operator = (int op2) {

   // Copier le scalaire dans chaque element de l'objet support
   //
   int cardinal= ordre()*ordre(); 
   for (int i=0; i<cardinal; i++) m_pT[i]= op2;

   return *this;
}








