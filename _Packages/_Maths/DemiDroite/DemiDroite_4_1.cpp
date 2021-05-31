//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Methodes support
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Determine la droite support de la demi-droite cible
//
Droite* DemiDroite::support() const{

   return new Droite(m_O, m_V);
}

// --- Determine si le segment est entierement porte par 
//     la demi droite cible
//
bool DemiDroite::support(const Segment& S) const {

   // Obtenir les deux extremites du segment
   //
   Point** pExtremites= S.extremites();
   if (pExtremites==NULL) throw -1.0;

   // Verifier l'appartenance de chaque extremite du segment 
   // a la demi droite cible
   //
   bool resultat= true;
   if (!appartient(*pExtremites[0])) resultat= false;
   else if (!appartient(*pExtremites[1])) resultat= false; 

   // Supprimer les variables de travail
   //
   delete pExtremites[0]; delete pExtremites[1];
   delete [] pExtremites;

   return resultat;
}
