//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2006_2007 - Package _Maths
//
// Classe MatriceF : surcharges des operateurs () et []
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Surcharges de l'operateur ()
//
Fraction& MatriceF::operator()(int i, int j) {

   // Controler la validite des deux parametres
   //
   if (i<1 || i > ordre()) throw -2.1;
   if (j<1 || j > ordre()) throw -2.2;

   // Restituer le resultat 
   // 
   return m_pT[ordre()*(i-1)+(j-1)];
}

Fraction* MatriceF::operator () (int i) {

   // Controler la validite du second parametre
   //
   if (i<1 || i > ordre()) throw -2.1;

   // Allouer le tableau resultant
   //
   Fraction* pR= new Fraction[ordre()];
   if(pR==NULL) throw -1.0;

   // Recopier le contenu de la ligne cible dans le tableau de sortie 
   //
   for (int j=0; j<ordre(); j++) pR[j]= m_pT[ordre()*(i-1)+ j];

   // Restituer le resultat 
   //
   return pR;
}

// Surcharge de l'operateur []
//
Fraction* MatriceF::operator [] (int j) {

   // Controler la validite du second parametre
   //
   if (j<1 || j > ordre()) throw -2.1;

   // Allouer le tableau resultant
   //
   Fraction* pR= new Fraction [ordre()];
   if(pR==NULL) throw -1.0;

   // Recopier le contenu de la colonne cible dans le tableau resultant 
   //
   for (int i=0; i<ordre(); i++) pR[i]= m_pT[j-1+i*ordre()];

   // Restituer le resultat 
   //
   return pR;
}