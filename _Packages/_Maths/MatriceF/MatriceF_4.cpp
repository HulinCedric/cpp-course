//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Feuille_8
//
// Classe MatriceF - Surcharges de l'operateur *
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Multiplier une matrice par un scalaire
//
MatriceF& MatriceF::operator * (int op2) {

   // Allouer la matrice resultante
   //
   MatriceF* pM= new MatriceF(ordre());
   if (pM==NULL) throw -1.0;

   // Copier chaque element du premier operande dans le resultat,
   // en le multipliant au passage par le second operande
   //
   Fraction* pF;
   for (int i=0; i<ordre()*ordre(); i++) {
      pF= m_pT[i]*op2;
      if (pF==NULL) throw -1.0;
      pM->m_pT[i]= *pF;
	  delete pF;
   }

   return *pM;
}

// Multiplier deux matrices de meme ordre entre elles
//
MatriceF& MatriceF::operator * (const MatriceF& op2) {

   // Controler la validite de l'operation
   //
   if (m_ordre != op2.ordre()) throw -3.0;

   // Allouer la matrice resultante
   //
   MatriceF* pM= new MatriceF(ordre());
   if (pM==NULL) throw -1.0;

   // Allouer un tableau pour memoriser une ligne resultante
   //
   Fraction* pLigne= new Fraction[ordre()];
   if (pLigne==NULL) {delete[] pM; throw -1.0;}

   // Multiplier chaque ligne du premier operande par chaque colonne du second
   //
   int debut;
   Fraction somme;
   Fraction* pF;

   for (int i=0; i<ordre(); i++) {
      debut=ordre()*i;

      for (int j=0; j<ordre(); j++) {
         somme= 0;

         for (int k=0; k<ordre(); k++) {
			 pF= m_pT[debut+k]*op2.m_pT[j+k*ordre()];
			 if (pF==NULL) {delete pF; delete[] pLigne; throw -1.0;}
			 somme += *pF;
             delete pF;
         }

         pLigne[j]= somme;
      }

      pM->remplir(i+1, pLigne);
   }

   delete[] pLigne;

   return *pM;
}







