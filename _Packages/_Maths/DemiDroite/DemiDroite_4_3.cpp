//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Methode parallele
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Determine si une demi-droite est parallele a une droite donnee
//
bool DemiDroite::parallele(const Droite& D) const {

   // Determiner la droite support
   //
   Droite* pS=support();
   if (pS==NULL) return false;

   // Controler le parallelisme des deux droites
   //
   bool bIndic= pS->parallele(D);
   delete pS;
   return bIndic;
}

// --- Determine si deux demi-droites sont paralleles
//
bool DemiDroite::parallele(const DemiDroite& D) const {
	
   // Determiner les deux droites supports
   //
   Droite* pS1= support();
   if (pS1==NULL) return false;

   Droite* pS2= D.support();
   if (pS1==NULL) {delete pS1; return false;}

   // Controler le parallelisme des deux droites
   //
   bool bIndic= pS1->parallele(*pS2);
   delete pS1; delete pS2;
   return bIndic;
}
