//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2006_2007 - Package _Maths
//
// Classe Matrice : calcul de la matrice transposee
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Calcul de la matrice transposee
//
Matrice& Matrice::transposee() {

   // Allouer la matrice resultante
   // 
   Matrice* pR= new Matrice(m_ordre);
   if (pR==NULL) throw -1.0;

   // Extraire chaque colonne de l'objet support et la copier dans
   // la ligne de meme rang dans la matrice resultante
   //
   int* pColonne;
   int rang=0; 

   for (int j= 1; j<= m_ordre; j++) {
      pColonne= (*this)[j];
      for (int k=0; k<m_ordre; k++) pR->m_pT[rang++]= pColonne[k];
      delete[] pColonne;
   }

   // Restituer le resultat 
   // 
   return *pR; 
}

