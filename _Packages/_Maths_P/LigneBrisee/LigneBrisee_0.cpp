//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Methode privee controlerTaille
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Controler et augmenter eventuellement la taille du tableau des sommets
//
int LigneBrisee::controlerTaille() {
Point** pS;

   // Controler la taille du tableau actuel
   //
   int taille= cardinal();
   if (taille == 0 || taille%10 != 0) return taille;

   // Augmenter la taille du tableau 
   //
   pS= new Point*[taille+10];
   if (pS==NULL) throw -1.0;

   // Recopier les sommets existants
   //
   for (int i=0; m_pSommets[i] != NULL; i++) pS[i]= m_pSommets[i];

   // Liberer le tableau existant
   //
   delete[] m_pSommets;

   // Substituer le nouvel tableau a l'ancien
   //
   m_pSommets= pS;

   // Restituer le resultat
   //
   return taille;
}








   




