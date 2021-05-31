//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Surcharges de l'operateur *=
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Multiplier une matrice par un scalaire
//
Matrice& Matrice::operator *= (int op2) {

   // Copier chaque element du premier operande dans le resultat,
   // en le multipliant au passage par le second operande
   //
   for (int i=0; i<ordre()*ordre(); i++) m_pT[i]= m_pT[i]*op2;

   return *this;
}

// Multiplier deux matrices de meme ordre entre elles
//
Matrice& Matrice::operator *= (const Matrice& op2) {

   // Controler la validite de l'operation
   //
   if (m_ordre != op2.ordre()) throw -3.0;

   // Allouer un tableau pour memoriser une ligne resultante
   //
   int* pLigne= new int[ordre()];
   if (pLigne==NULL) throw -1.0;

   // Multiplier chaque ligne du premier operande par chaque colonne du second
   //
   int debut, somme;

   for (int i=0; i<ordre(); i++) {
      debut=ordre()*i;

      for (int j=0; j<ordre(); j++) {
         somme= 0;
         for (int k=0; k<ordre(); k++) somme += m_pT[debut+k]*op2.m_pT[j+k*ordre()];
         pLigne[j]= somme;
      }

      remplir(i+1, pLigne);
   }
   delete[] pLigne;

   return *this;
}







